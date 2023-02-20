// Programmer: Anna Felipe
// Programmer's ID: 1506055

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include "AssociativeArray.h"

using namespace std;

int main() {

    cout << "Programmer: Anna Felipe" << endl;
    cout << "Programmer's ID: 1506055" << endl;
    cout << "File: " << __FILE__ << endl;
    cout << endl;

    AssociativeArray<string, AssociativeArray<string, bool> > alreadySeen;
    AssociativeArray<string, AssociativeArray<string, int> > count;
    AssociativeArray<string, int> subjectCounts;

    int duplicates = 0;
    int index = 0;

    char* token;
    char buf[1000];
    const char* const tab = "\t";


    ifstream fin;
    fin.open("dvc-schedule.txt");

    while (fin.good()) {

        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());

        if (buf[0] == 0)
            continue;

        const string term(token = strtok(buf, tab));
        const string section((token = strtok(0, tab)) ? token : "");
        const string course((token = strtok(0, tab)) ? token : "");
        const string instructor((token = strtok(0, tab)) ? token : "");
        const string whenWhere((token = strtok(0, tab)) ? token : "");

        if (course.find('-') == string::npos)
            continue;

        const string subjectCode(course.begin(), course.begin() + course.find('-'));
        string classCode = term + "." + section;

        if (alreadySeen[term].containsKey(section)) {
            duplicates++;
        }
        else {
            alreadySeen[term][section] = true;
            count[subjectCode][course]++;
        }


    }fin.close();


    AssociativeArray<int, string> skeys;
    queue<string> qKeys = count.keys();
    for (int i = 0; !qKeys.empty(); i++)
    {
        skeys[i] = qKeys.front();
        qKeys.pop();
    }

    for (int i = 0; i < skeys.size(); i++) {
        for (int j = i + 1; j < skeys.size(); j++) {
            if (skeys[i] > skeys[j]) {
                swap(skeys[i], skeys[j]);
            }
        }
    }
    for (int i = 0; i < count.size(); i++) {
    int numBlank = 0;

    AssociativeArray<int, string> ckeys;
    queue<string> qc = count[skeys[i]].keys();
    for (unsigned int i = 0; !qc.empty(); i++) {
        ckeys[i] = qc.front();
        qc.pop();
    }

    for (int x = 0; x < count[skeys[i]].size(); x++) {
        for (int y = x + 1; y < count[skeys[i]].size(); y++) {
            if (ckeys[x] > ckeys[y]) {
                swap(ckeys[x], ckeys[y]);
            }
        }
    }

AssociativeArray<int, string> outputs;

    for (int j = 0; j < (count[skeys[i]].size()); j++) {
        string s = " " + ckeys[i] + "," + to_string(count[skeys[i]][ckeys[j]]) + " section(s)";
        outputs[j] = s;
    }
    
    }

    cout << "Total duplicates: " << duplicates << endl;

}


