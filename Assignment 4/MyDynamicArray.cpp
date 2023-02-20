//Programmer: Anna Felipe
//Programmer ID: 1506055

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "DynamicArray.h"

using namespace std;

int main() {

    cout << "Programmer: Anna Felipe " << endl;
    cout << "Programmer's ID: 1506055 " << endl;
    cout << "File:" << __FILE__ << endl;
    cout << endl;

    DynamicArray<double> storedValue(100);
    DynamicArray<int> a(100);

    string index;
    string value;

    while (true) {

        cout << "Input an index and a value [Q to quit]: ";
        cin >> index;
        if (index == "Q" || index == "q") {
            break;
        }
        cin >> value;
        cout << endl;

        storedValue[atof(index.c_str())] = atof(value.c_str());

        a[atof(index.c_str())] = true;
    }
    
    int duplicatedinput = 0;

    bool DynamicArray = false;
    

    if (a[atof(index.c_str())] == 1) {
        
        DynamicArray = true;

        duplicatedinput++;

    }

    int storeTotal = 0;

    for (int i = 0; i < 100; i++) {

        if (a[i] == true) {

            storeTotal++;
        }

    }

    cout << "You stored this many values: " << storeTotal - duplicatedinput << endl;
    cout << endl;


    cout << "The index-value pairs are:" << endl;
    cout << endl;

    for (int i = 0; i < 100; i++) {

        if (a[i] == true) {

            cout << setw(5) << i << " => " << storedValue[i] << endl;
            cout << endl;
        }
    }

    while (true) {

        cout << "Input an index and a value [Q to quit]: ";
        cin >> index;
        if (index == "Q" || index == "q") {

            break;

        }
        if (a[atof(index.c_str())] == true && atof(index.c_str()) >= 0 && atof(index.c_str()) < 100) {

            double indexSearch = storedValue[atoi(index.c_str())];
            cout << "Found it -- the value stored at " << index << " is " << indexSearch << endl;
            cout << endl;
        }
        else {

            cout << "I didn't find it" << endl;
            cout << endl;

        }
    }


    system("PAUSE");

    return 0;
}