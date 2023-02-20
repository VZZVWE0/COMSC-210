// Programmer: Anna Felipe
// Programmer's ID: 1506055

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring> 
#include <queue>
#include "HashTable.h"

using namespace std;

int hashCode(const string& key) {
    int result = 0;
    for (int i = 0; i < key.length(); i++)
        result += key.at(i);
    return result;
}

int main() {
    cout << "Programmer: Anna Felipe" << endl;
    cout << "Programmer's ID: 1506055" << endl;
    cout << "File: " << __FILE__ << endl;

    HashTable<string, bool, 91000> record(hashCode);
    HashTable<string, int, 100> subClass(hashCode);
    int duplicates = 0;
    int count = 0;
   
    char* token;
    char buf[1000];
    const char* const tab = "\t";

    ifstream fin;
    fin.open("dvc-schedule.txt");

    while (fin.good()) {
        count++;
        cout << "Lines read: " << count << "\r";
        cout.flush();
        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());
        if (buf[0] == 0) continue;

        const string term(token = strtok(buf, tab));
        const string section(token = strtok(0, tab));
        const string course((token = strtok(0, tab)) ? token : "");
        const string instructor((token = strtok(0, tab)) ? token : "");
        const string whenWhere((token = strtok(0, tab)) ? token : "");

        if (course.find('-') == string::npos) 
            continue; 

        const string subjectCode(course.begin(), course.begin() + course.find('-'));

        string classCode = term + section;

        if (record[classCode]) {
            duplicates++;
        }
        else {
            record[classCode] = true;
            subClass[subjectCode]++;
        }
    }
    fin.close();

    cout << "Total records: " << count << endl;
    cout << "Total duplicates: " << duplicates << endl;
    cout << "Total non-duplicates: " << count - duplicates << endl;
    cout << endl;

    queue<string> q = subClass.keys();
    set<string> s;

    while (!q.empty()) {
        s.insert(q.front());
        q.pop();
    }

    for (auto& i : s) {
        cout << i << ", " << subClass[i] << " section" << endl;
    }

    system("PAUSE");

}