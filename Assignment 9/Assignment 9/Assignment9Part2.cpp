#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

#include "DynamicArray.h"

struct Class
{
	string subjectCode;
	int count;
};

int main()
{
	cout << "Programmer: Anna Felipe" << endl;
	cout << "Programmer ID: 1506055" << endl;
	cout << "File Name: Assignemnt9Part2.cpp" << endl;
	cout << endl;

	DynamicArray<string> sub;
	DynamicArray<string> sem;
	DynamicArray<string> sec;

	int n = 0;
	int dup = 0;
	int counter = 0;
	bool duplicate;
	bool stored;

	
	char* token;
	char buf[1000];
	const char* const tab = "\t";

	
	ifstream fin;
	fin.open("dvc-schedule.txt");
	if (!fin.good())
		cout << "I/O error. File can't be found!\n";

	
	while (fin.good())
	{
		
		if (counter % 1000 == 0)
			cout << '.'; cout.flush();
		duplicate = false;
		stored = false;
		string line;
		getline(fin, line);
		strcpy(buf, line.c_str());
		if (buf[0] == 0) 
			continue; 
		
		const string term(token = strtok(buf, tab));
		const string section(token = strtok(0, tab));
		const string course((token = strtok(0, tab)) ? token : "");
		const string instructor((token = strtok(0, tab)) ? token : "");
		const string whenWhere((token = strtok(0, tab)) ? token : "");
		if (course.find('-') == string::npos) 
			continue;
		const string subjectCode(course.begin(), course.begin() + course.find('-'));

		
		for (int i = 0; i < counter; i++)
		{
			if (sem[i] == term && sec[i] == section)
			{
				dup++;
				duplicate = true;
				break;
			}
		}

		if (duplicate == true)
			continue;

		srand(time(0));
		rand();

		int n = 800;
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
	cout << endl;


}

