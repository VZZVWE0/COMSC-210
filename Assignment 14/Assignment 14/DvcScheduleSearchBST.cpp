// Programmer: Anna Felipe
// Programmer's ID: 1506055

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

#include "BinarySearchTree.h"

using namespace std;

int main() {

	cout << "Programmer: Anna Felipe" << endl;
	cout << "Programmer's ID: 1506055" << endl;
	cout << "File: " << __FILE__ << endl;

	BinarySearchTree<string, set<int>> records;

	char* token;
	char buffer[1000];
	const char* const tab = "\t";

	
	ifstream fin;
	fin.open("dvc-schedule.txt");
	if (!fin.good()) throw "I/O error";

	while (fin.good()) {

		string line;
		getline(fin, line);
		strcpy(buffer, line.c_str());
		if (buffer[0] == 0) continue; 
	
		const string term(token = strtok(buffer, tab));
		const string section((token = strtok(0, tab)) ? token : "");
		const string course((token = strtok(0, tab)) ? token : "");
		const string instructor((token = strtok(0, tab)) ? token : "");
		const string whenWhere((token = strtok(0, tab)) ? token : "");
		if (course.find('-') == string::npos)
			continue; 

		const string subjectCode(course.begin(), course.begin() + course.find('-'));

		string classCode = "";
		size_t found = term.find("2");

		if (term.find("Spring") != string::npos) {
			classCode += term[found];
			classCode += term[(found + 1)];
			classCode += term[(found + 2)];
			classCode += term[(found + 3)];
			classCode += "1";
		}
		else if (term.find("Summer") != string::npos) {
			classCode += term[found];
			classCode += term[(found + 1)];
			classCode += term[(found + 2)];
			classCode += term[(found + 3)];
			classCode += "2";
		}
		else if (term.find("Fall") != string::npos) {
			classCode += term[found];
			classCode += term[(found + 1)];
			classCode += term[(found + 2)];
			classCode += term[(found + 3)];
			classCode += "3";
		}

		int code = 0;

		stringstream placeh(classCode);

		placeh >> code;

		records[course].insert(code);
	}
	fin.close();

	while (1) {

		cout << endl;
		cout << "Enter a course like (COMSC-210) including a subject code(COMSC), a dash(-), and an alphanumeric sequence number (210)." << endl;
		cout << "Or enter X to quit." << endl;
		cout << endl;
		string course;

		getline(cin, course);

		if (course == "X" || course == "x") {
			break;
		}

		if (records.containsKey(course)) {

			set<int>::iterator it = records[course].begin();
			set<int>::reverse_iterator rit = records[course].rbegin();

			string s_front = to_string(*it);
			string s_back = to_string(*rit);

			string front = "";
			string back = "";

			if (s_front[s_front.length() - 1] == '1') {
				front += "Spring ";
				s_front.erase(s_front.length() - 1);
				front += s_front;
			}
			else if (s_front[s_front.length() - 1] == '2') {
				front += "Summer ";
				s_front.erase(s_front.length() - 1);
				front += s_front;
			}
			else if (s_front[s_front.length() - 1] == '3') {
				front += "Fall ";
				s_front.erase(s_front.length() - 1);
				front += s_front;
			}

			if (s_back[s_back.length() - 1] == '1') {
				back += "Spring ";
				s_back.erase(s_back.length() - 1);
				back += s_back;
			}
			else if (s_back[s_back.length() - 1] == '2') {
				back += "Summer ";
				s_back.erase(s_back.length() - 1);
				back += s_back;
			}
			else if (s_back[s_back.length() - 1] == '3') {
				back += "Fall ";
				s_back.erase(s_back.length() - 1);
				back += s_back;
			}
	
			cout << course << " was first offered in " << front << endl;
			cout << course << " was last offered in " << back << endl;

		}
		else {
			cout << course << " could not be found as far back as the year 2000" << endl;
		}
	}
}