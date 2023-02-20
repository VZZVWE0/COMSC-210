//Programmer: Anna Felipe
//Programmer ID: 1506055

#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
using namespace std;

#include "Stack.h"

int main() {

    cout << "Programmer: Anna Felipe" << endl;
    cout << "Programmer ID: 1506055" << endl;
    cout << "File Name: " << __FILE__ << endl;
    cout << endl;

    Stack<string> obj;

    cout << "Stack test: (string)";
    cout << "\n-----------------";
        
    cout << "\nTesting Stack::size";
    cout << "\nEXPECTED: 0";
    cout << "\nACTUAL: " << obj.size();
    if (0 == obj.size())
        cout << "\nPass!";
    else
        cout << "\nFail!";
  
    cout << "\n\n";
    cout << "\nTesting Stack::peek & Stack::push";
    obj.push("ONE");
    cout << "\nEXPECTED: ONE";
    cout << "\nACTUAL: " << obj.peek();
    if ((obj.peek().compare("ONE")) == 0)
        cout << "\nPass!";
    else
        cout << "\nFail!";
                
    cout << "\n\n";
    cout << "\nTesting Stack::pop";
    obj.push("TWO");
    cout << "\nBefore pop: " << obj.peek();
    obj.pop();
    cout << "\nAfter pop: " << obj.peek();

    if ((obj.peek().compare("ONE")) == 0)
        cout << "\nPass!";
    else
        cout << "\nFail!";

    cout << "\n\n";
    cout << "\nTesting copy constructor";
    Stack<string> copy_obj(obj);
    bool flag = true;

    if (obj.empty() && copy_obj.empty()) {
        flag = true;
    }
    else if (obj.empty() || copy_obj.empty()) {
        flag = false;
    }
    else if (obj.size() != copy_obj.size())
        flag = false;
    else if ((obj.peek().compare(copy_obj.peek())) != 0) {
        flag = false;
    }
    else
    {
        Stack<string> temp1, temp2;
        while (!obj.empty() && !copy_obj.empty()) {
            if (obj.peek().compare(copy_obj.peek()) != 0)
            {
                flag = false; break;
            }
            temp1.push(obj.peek());
            obj.pop();
            copy_obj.pop();

        }
        if (obj.empty() && copy_obj.empty())
            flag = true;
        else
            flag = false;

        while (temp1.empty()) {
            obj.push(temp1.peek());
            copy_obj.push(temp1.peek());
            temp1.pop();
        }
    }

    if (flag == 1)
        cout << "\nPass!";
    else
        cout << "\nFail!";

    cout << "\n\n";
    cout << "\nTesting assignment operator";
    Stack<string> assign_obj;
    assign_obj = obj;
    flag = true;

    if (obj.empty() && assign_obj.empty()) {
        flag = true;
    }
    else if (obj.empty() || assign_obj.empty()) {
        flag = false;
    }
    else if (obj.size() != assign_obj.size())
        flag = false;
    else if ((obj.peek().compare(assign_obj.peek())) != 0) {
        flag = false;
    }
    else
    {
        Stack<string> temp1, temp2;
        while (!obj.empty() && !assign_obj.empty()) {
            if (obj.peek().compare(assign_obj.peek()) != 0)
            {
                flag = false; break;
            }
            temp1.push(obj.peek());
            obj.pop();
            assign_obj.pop();

        }
        if (obj.empty() && assign_obj.empty())
            flag = true;
        else
            flag = false;

        while (temp1.empty()) {
            obj.push(temp1.peek());
            assign_obj.push(temp1.peek());
            temp1.pop();
        }
    }

    if (flag == 1)
        cout << "\nPass!";
    else
        cout << "\nFail!";
    
    cout << "\n\n";
    cout << "\nTesting Stack::size";
    copy_obj.clear();
    copy_obj.push("ONE"); copy_obj.push("TWO"); copy_obj.push("THREE"); copy_obj.push("FOUR"); copy_obj.push("FIVE");
    cout << "\nAfter pushing 5 now element, size is: " << copy_obj.size();
    if (5 == copy_obj.size())
        cout << "\nPass!";
    else
        cout << "\nFail!";
     
    cout << "\n\n";
    cout << "\nTesting Stack::clear & empty";
    obj.clear();
    if (0 == obj.size())
        cout << "\nPass!";
    else
        cout << "\nFail!";
 
    cout << "\n\n";
    cout << "\nConstant object test:";
    cout << "\nsize: " << copy_obj.size();
    if (0 == copy_obj.size())
        cout << "\nEmpty!";
    else
        cout << "\nNOT empty!";
}