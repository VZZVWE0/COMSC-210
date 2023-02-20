#include <iostream>
#include <string>
#include <cassert> 
#include <cmath>
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include <cstring>

#include "DynamicArray.h"

using namespace std;

int main() {

	cout << "Programmer: Anna Felipe" << endl;
	cout << "Programmer ID: 1506055" << endl;
	cout << "File Name: Assignment9Part1.cpp" << endl;
	cout << endl;

	char* token;
	char buf[1000];
	const char* const tab = "\t";

	ifstream fin;
	fin.open("dvc-schedule.txt");
	if (!fin.good()) {
		throw "I/O error";
	}

	while (fin.good()) {
		string line;
		getline(fin, line);
		strcpy(buf, line.c_str());

		if (buf[0]) == 0)) {
			continue;
		};

		const string term(token = strtok(buf, tab));
		const string section((token = strtok(0, tab)) ? token : "");
		const string course((token = strtok(0, tab)) ? token : "");
		const string instructor((token = strtok(0, tab)) ? token : "");
		const string whenWhere((token = strtok(0, tab)) ? token : "");

		if (course.find('-') == string::npos) {
			continue;
		}
		const string subjectCode(course.begin(), course.begin() + course.find('-'));
	
		
		srand(time(0));
		rand();

		int n = 500;
		string bigOh = "O(n)";

		cout.setf(ios::fixed);
		cout.precision(4);

		double elapsedSecondsNorm = 0;
		double expectedSeconds = 0;

		for (int cycle = 0; cycle < 4; cycle++, n *= 2) {

			int* a = new int[n];

			for (int i = 0; i < n; i++)
				a[i] = rand();

			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
					if (a[j] < a[i])
						swap(a[i], a[j]);

			clock_t startTime = clock();

			for (int i = 1; i < n; i++)
				assert(a[i - 1] <= a[i]);

			clock_t endTime = clock();

			delete[]a;

			double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

			double factor = pow(2.0, double(cycle));

			if (cycle == 0) {

				elapsedSecondsNorm = elapsedSeconds;
			}
			else if (bigOh == "O(n)") {

				expectedSeconds = factor * elapsedSecondsNorm;
			}
			else if (bigOh == "O(n log n)") {

				expectedSeconds = factor * log(double(n)) / log(n / factor) * elapsedSecondsNorm;
			}
			else if (bigOh == "O(n squared)") {

				expectedSeconds = factor * factor * elapsedSecondsNorm;
			}
			cout << elapsedSeconds;

			if (cycle == 0) {

				cout << " (expected " << bigOh << ')';
			}
			else

				cout << " (expected " << expectedSeconds << ')';

			cout << " for n=" << n << endl;

		}
	}
	fin.close();

	

}