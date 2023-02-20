// Programmer: Anna Felipe
// Programmer's ID: 1506055

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include <cstring> 

#include "DynamicArray.h"

bool check_duplication(const string classCode, const DynamicArray<string>& classArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (classArray[i] == classCode)
            return true;
    }
    return false;
}

struct subject {
    string subjectCode;
    int count;
};

int main() {

    cout << "Programmer: Anna Felipe\n";
    cout << "Programmer's ID: 1506055\n";
    cout << "File: " << __FILE__ << endl;

    DynamicArray<string> nonDuplicateClasses(100);
    DynamicArray<subject> subjectCount(100);

    int count = 0;
    int duplicates = 0;
    int classIndex = 0;
    int subjectIndex = 0;

    char* token;
    char buf[1000];
    const char* const tab = "\t";


    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good())
        cout << "I/O error. File can't find!\n";

    cout << endl;
    cout << "Please Wait. Loading: ";

    while (fin.good()) {

        count++;
        if (count % 1000 == 0)
            cout << "|";
        cout.flush();
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

        string classCode = term + "," + section;

        bool found = check_duplication(classCode, nonDuplicateClasses,
            classIndex);
        if (!found)
        {
            nonDuplicateClasses[classIndex++] = classCode;
            for (int i = 0; i < subjectIndex; i++)
                if (subjectCount[i].subjectCode.compare(subjectCode) == 0)
                {
                    found = true; 
                    subjectCount[i].count++; 
                    break;
                }
        }
        else { 
            
            duplicates++;
        }
        if (!found) {
            subjectCount[subjectIndex].subjectCode = subjectCode;
            subjectCount[subjectIndex].count = 1;
            subjectIndex++;
        }
        count++;


    }
    fin.close();


    for (int i = 0; i < subjectIndex; i++)  {
        for (int j = i; j < subjectIndex; j++)
            if (subjectCount[i].subjectCode > subjectCount[j].subjectCode)
                swap(subjectCount[i], subjectCount[j]);
    }

    for (int i = 0; i < subjectIndex; i++)  {
        cout << subjectCount[i].subjectCode << ", " << subjectCount[i].count << " section" << endl;
    }

    cout << endl;
    cout << "Total duplication: " << duplicates << endl;
    cout << "Total counts: " << count << endl;
    cout << "Total subjects: " << subjectIndex << endl;
}

