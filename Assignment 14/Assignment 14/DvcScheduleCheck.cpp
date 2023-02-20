// Programmer: Anna Felipe
// Programmer's ID: 1506055

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <fstream> 
#include <string>
#include <map>
#include <set>
#include <cstring> 

using namespace std;

int main() {

    cout << "Programmer: Anna Felipe" << endl;
    cout << "Programmer's ID: 1506055" << endl;
    cout << "File: " << __FILE__ << endl;
    
    map<string, map<string, set<string>>> records;

    char* token;
    char buf[1000];
    const char* const tab = "\t";
    
    ifstream fin;
    
    fin.open("dvc-schedule.txt");
    if (!fin.good()) throw "I/O error";

    while (fin.good()) {
        
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

        records[term][section].insert(course);
    }
    fin.close();

    for (auto term : records) {
        for (auto section : term.second) {
            set<string> v = section.second;
            if (v.size() > 1) {
                cout << endl;
                cout << "Invalid entries have been found in " << term.first << ": " << endl;
                for (auto course: v) {
                    cout << "=> " << course << " " << section.first << endl;

                }
            } 
        }
    }
    
    system("PAUSE");
}