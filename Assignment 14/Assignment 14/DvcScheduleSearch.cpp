// Programmer: Anna Felipe
// Programmer's ID: 1506055

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <fstream> 
#include <string>
#include <map>
#include <cstring> 

using namespace std;

vector<string> parser(const string& uInput, const string& delim) {
    
    vector<string> inputs;
    inputs.push_back(uInput.substr(0, uInput.find(delim)));
    inputs.push_back(uInput.substr(uInput.find(delim) + 1, uInput.length()));
    return inputs;
}

int main() {

    cout << "Programmer: Anna Felipe" << endl;
    cout << "Programmer's ID: 1506055" << endl;
    cout << "File: " << __FILE__ << endl;

    map<string, map<string, vector<string>>> records;

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
        
        records[subjectCode][course].push_back(term);
    }
    fin.close();

    cout << endl;
    cout << "Enter a course (like COMSC-210) including a subject code(COMSC), a dash(-), and an alphanumeric sequence number(210)." << endl;
    cout << "Or enter X to quit." << endl;
    cout << endl;
    string uInput;

    do {
        cout << endl;
        cout << "Course: ";
        cin >> uInput;
        cout << "----------------------------------------------" << endl;
        vector<string> v = records[parser(uInput, "-")[0]][uInput];

        if (!v.empty()) {
            string last = v.front();
            for (auto it : v) {
                vector<string> current = parser(it, " ");
                vector<string> lastTime = parser(last, " ");
                if (current[1] >= lastTime[1]) {
                    if (current[1] == lastTime[1]) {
                        if (current[0] == "Spring" || (current[0] == "Summer" && lastTime[0] == "Fall")) {
                            last = it;
                        }
                    }
                    else {
                        last = it;
                    }
                }
            }
            vector<string> lastTime = parser(last, " ");
            cout << "=> " << uInput << " was last offered in " << lastTime[0] << " " << lastTime[1] << "." << endl;
        }
        if (!v.empty()) {
            string first = v.back();
            for (auto it : v) {
                vector<string> current = parser(it, " ");
                vector<string> firstTime = parser(first, " ");
                if (current[1] <= firstTime[1]) {
                    if (current[1] == firstTime[1]) {
                        if (current[0] == "Spring" || (current[0] == "Summer" && firstTime[0] == "Fall")) {
                            first = it;
                        }
                    }
                    else {
                        first = it;
                    }
                }
            }
            vector<string> firstTime = parser(first, " ");
            cout << "=> " << uInput << " was first offered in " << firstTime[0] << " " << firstTime[1] << "." << endl;
        }
        else {
            if (uInput != "x" && uInput != "X") {
                cout << uInput << " could not be found as far back as the year 2000." << endl;
            }
        }
    } while (uInput != "x" && uInput != "X");

    system("PAUSE");
}