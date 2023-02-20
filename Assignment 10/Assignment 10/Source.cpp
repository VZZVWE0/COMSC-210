#include <iostream>
#include <fstream>
using namespace std;

#include "LabExercise10.h"

int main(){

cout << "Isuph Shrestha\nID: 1665028" << endl;

cout << "File: " << __FILE__ << endl;

AssociativeArray<string, AssociativeArray<string, bool>> seen;

AssociativeArray<string, AssociativeArray<string, int>> COUNT;

char* token; char buf[1000]; const char* const tab = "\t";

bool first = true, dup = false, duplicate = false, newSection = true, newTerm = true, newSubject = true;

int counter = 0;  int subCounter = 0, duplicateCounter = 0;

// open the input file

ifstream fin;

fin.open("dvc-schedule.txt");

if (!fin.good())

cout << "I/O error. File can't find!\n";



while (fin.good()) {



	if (first) {

		first = false;

		continue;

	}



	// read the line

	string line;

	getline(fin, line);

	strcpy(buf, line.c_str());



	if (buf[0] == 0) continue; // skip blank lines



	//parse the line

	const string term(token = strtok(buf, tab));

	const string section((token = strtok(0, tab)) ? token : "");

	const string course((token = strtok(0, tab)) ? token : "");

	const string instructor((token = strtok(0, tab)) ? token : "");

	const string whenWhere((token = strtok(0, tab)) ? token : "");

	if (course.find('-') == string::npos) continue; // invalid line: no dash in course name

	const string subjectCode(course.begin(), course.begin() + course.find('-'));





	if (!seen[term][section]) {

		seen[term][section] = true;

		COUNT[subjectCode][course]++;

		dup = false;

	}

	else {

		newTerm = false;

		duplicateCounter++;

		dup = true;

		if (int i == numTerm) {

			numTerm++;

		}

	}

	counter++;

	dup = false;

	duplicate = false;

	newSubject = true;

	newTerm = true;

	newSection = true;



	if (counter % 1000 == 0) {

		cout << '.';

		cout.flush();

	}



}

cout << endl;

cout << "Duplicates: " << duplicateCounter << endl;

queue<string> subKeys = COUNT.keys(); //queue of all subject codes

//Queue<string> courseKeys = COUNT[subjectCodes]

// Need Help to print the output

//cout << "Duplicates: " << duplicateCounter << endl;

cout << "Line Counts: " << counter << endl;

cout << "Subjects: " << COUNT.size() << endl;

fin.close();

return 0;

}