//Programmer: Anna Felipe
//Programmer ID: 1506055

#include<iostream>
#include<string>
#include<cassert>

#include "Queue.h"

using namespace std;

int main() {

    cout << "Programmer: Anna Felipe" << endl;;
    cout << "Programmer's ID: 1506055" << endl;
    cout << "File: Queue.TestDriver.cpp" << endl;

    Queue<int> t_int;

    cout << "Queue test: (int)" << endl;
    cout << "Testing Queue::size" << endl;
    cout << "EXPECTED: 0" << endl;
    cout << "ACTUAL: " << t_int.size() << endl;
    cout << "Pass" << endl;

    cout << endl;


    cout << "Testing Queue::peek & Queue:: push" << endl;
    cout << "EXPECTED: 2" << endl;
    t_int.push(2);
    cout << "ACTUAL: " << t_int.front() << endl;
    t_int.push(42);
    t_int.push(999);
    cout << "Pass" << endl;


    cout << "\n\n" << "Testing Queue::pop" << endl;
    cout << "BEFORE pop: 2" << endl;
    t_int.pop();
    cout << "AFTER pop: " << t_int.front() << endl;
    cout << "BEFORE pop: 42" << endl;
    t_int.pop();
    cout << "AFTER pop: " << t_int.front() << endl;
    cout << "Pass" << endl;

    t_int.push(2);
    t_int.push(429);
    t_int.push(999);
    cout  << endl;

    cout << "Testing Queue::back" << endl;
    cout << "EXPECTED: 999" << endl;
    cout << "ACTUAL: " << t_int.back() << endl;
    cout << "Pass" << endl;

    cout << endl;
    cout << "Testing copy constructor" << endl;
    Queue<int> c_int = t_int;
    for (int i = 0; i < t_int.size(); i++)
    {
        assert(t_int.front() == c_int.front());
        assert(t_int.back() == t_int.back());
        t_int.pop();
        c_int.pop();
    }
    cout << "Pass" << endl;

    t_int.push(2);
    t_int.push(429);
    t_int.push(999);

    cout << endl;
    cout << "Testing assignment operator" << endl;
    Queue<int> a_int = t_int;
    for (int i = 0; i < t_int.size(); i++)
    {
        assert(t_int.front() == a_int.front());
        assert(t_int.back() == a_int.back());

        t_int.pop();
        a_int.pop();
    }
    cout << "Pass" << endl;
    cout << endl;

    cout << "Const object test" << endl;
    const Queue<int> co_int;
    assert(co_int.size() == 0);
    assert(co_int.front() == co_int.front());
    assert(co_int.back() == co_int.back());

    cout << "Pass" << endl;

    cout << "\n\n" << "Testing Queue::clear & empty" << endl;
    t_int.clear();
    assert(t_int.empty() == true);
    cout << "Pass" << endl;
    cout << endl;

    Queue<double> t_double;

    cout << "Queue test: (double)" << endl;
    cout << "Testing Queue::size" << endl;
    cout << "EXPECTED: 0" << endl;
    cout << "ACTUAL: " << t_double.size() << endl;
    cout << "Pass" << endl;

    cout << endl;

    cout << "Testing Queue::peek & Queue:: push \n";
    cout << "EXPECTED: 2.2\n";
    t_double.push(2.2);
    t_double.push(42.2);
    t_double.push(999.2);
    cout << "ACTUAL: " << t_double.front() << endl;
    cout << "Pass" << endl;

    cout << "\n\n" << "Testing Queue::pop" << endl;
    cout << "BEFORE pop: 2.2" << endl;
    t_double.pop();
    cout << "AFTER pop: " << t_double.front() << endl;
    cout << "BEFORE pop: 42.2" << endl;
    t_double.pop();
    cout << "AFTER pop: " << t_double.front() << endl;
    cout << "Pass" << endl;

    t_double.push(2.2);
    t_double.push(-429.2);
    t_double.push(999.2);
    cout << endl;

    cout << "Testing Queue::back" << endl;
    cout << "EXPECTED: 999.2" << endl;;
    cout << "ACTUAL: " << t_double.back() << endl;
    cout << "Pass" << endl;

    cout << endl;
    cout << "Testing copy constructor" << endl;
    Queue<double> c_double = t_double;
    for (double i = 0; i < t_double.size(); i++)
    {
        assert(t_double.front() == c_double.front());
        assert(t_double.back() == t_double.back());
        t_double.pop();
        c_double.pop();
    }
    cout << "Pass" << endl;

    t_double.push(2.2);
    t_double.push(-429.2);
    t_double.push(999.2);

    cout << endl;
    cout << "Testing assignment operator" << endl;
    Queue<double> a_double = t_double;
    for (double i = 0; i < t_double.size(); i++)
    {
        assert(t_double.front() == a_double.front());
        assert(t_double.back() == a_double.back());

        t_double.pop();
        a_double.pop();
    }
    cout << "Pass" << endl;
    cout << endl;

    cout << "Const object test" << endl;
    const Queue<double> co_double;
    assert(co_double.size() == 0);
    assert(co_double.front() == co_double.front());
    assert(co_double.back() == co_double.back());

    cout << "Pass" << endl;

    cout << end;
    cout << "Testing Queue::clear & empty" << endl;
    t_double.clear();
    assert(t_double.empty() == true);
    cout << "Pass" << endl;
    cout << endl;


    Queue<char> t_char;

    cout << "Queue test: (char)" << endl;
    cout << "Testing Queue::size" << endl;;
    cout << "EXPECTED: 0" << endl;
    cout << "ACTUAL: " << t_char.size() << endl;
    cout << "Pass" << endl;

    cout << endl;

    cout << "Testing Queue::peek & Queue:: push" << endl;
    cout << "EXPECTED: A" << endl;
    t_char.push('A');
    cout << "ACTUAL: " << t_char.front() << endl;
    t_char.push('B');
    t_char.push('C');
    cout << "Pass" << endl;


    cout << endl;
    cout << "Testing Queue::pop" << endl;
    cout << "BEFORE pop: A" << endl;
    t_char.pop();
    cout << "AFTER pop: " << t_char.front() << endl;
    cout << "BEFORE pop: B" << endl;
    t_char.pop();
    cout << "AFTER pop: " << t_char.front() << endl;
    cout << "Pass" << endl;

    t_char.push('A');
    t_char.push('B');
    t_char.push('C');
    cout << endl;

    cout << "Testing Queue::back" << endl;
    cout << "EXPECTED: C" << endl;
    cout << "ACTUAL: " << t_char.back() << endl;

    cout << endl;
    cout << "Testing copy constructor" << endl;
    Queue<char> c_char = t_char;
    for (char i = 0; i < t_char.size(); i++)
    {
        assert(t_char.front() == c_char.front());
        assert(t_char.back() == t_char.back());
        t_char.pop();
        c_char.pop();
    }
    cout << "Pass" << endl;

    t_char.push('A');
    t_char.push('B');
    t_char.push('C');

    cout << endl;
    cout << "Testing assignment operator" << endl;
    Queue<char> a_char = t_char;
    for (char i = 0; i < t_char.size(); i++)
    {
        assert(t_char.front() == a_char.front());
        assert(t_char.back() == a_char.back());

        t_char.pop();
        a_char.pop();
    }
    cout << "Pass" << endl;
    cout << endl;

    cout << "Const object test" << endl;
    const Queue<char> co_char;
    assert(co_char.size() == 0);
    assert(co_char.front() == co_char.front());
    assert(co_char.back() == co_char.back());

    cout << "Pass" << endl;

    cout << endl;
    cout << "Testing Queue::clear & empty \n";
    t_char.clear();
    assert(t_char.empty() == true);
    cout << "Pass" << endl;
    cout << endl;

    Queue<string> t_string;

    cout << "Queue test: (string)" << endl;
    cout << "Testing Queue::size" << endl;
    cout << "EXPECTED: 0" << endl;
    cout << "ACTUAL: " << t_string.size() << endl;
    cout << "Pass" << endl;

    cout << endl;

    cout << "Testing Queue::peek & Queue:: push" << endl;
    cout << "EXPECTED: Hello" << endl;
    t_string.push("Hello");
    cout << "ACTUAL: " << t_string.front() << endl;
    t_string.push("World");
    t_string.push("!!!");
    cout << "Pass" << endl;


    cout << "\n\n" << "Testing Queue::pop" << endl;
    cout << "BEFORE pop: Hello" << endl;
    t_string.pop();
    cout << "AFTER pop: " << t_string.front() << endl;
    cout << "BEFORE pop: World" << endl;
    t_string.pop();
    cout << "AFTER pop: " << t_string.front() << endl;
    cout << "Pass" << endl;

    t_string.push("Hello");
    t_string.push("World");
    t_string.push("!!!");
    cout << endl;

    cout << "Testing Queue::back" << endl;
    cout << "EXPECTED: !!!" << endl;
    cout << "ACTUAL: " << t_string.back() << endl;


    cout << "\n\n" << "Testing copy constructor" << endl;
    Queue<string> c_string = t_string;
    while (!t_string.empty())
    {
        assert(t_string.front() == c_string.front());
        assert(t_string.back() == t_string.back());
        t_string.pop();
        c_string.pop();
    }
    cout << "Pass" << endl;

    t_string.push("Hello");
    t_string.push("World");
    t_string.push("!");

    cout << endl;
    cout << "Testing assignment operator \n";
    Queue<string> a_string = t_string;
    while (!t_string.empty())
    {
        assert(t_string.front() == a_string.front());
        assert(t_string.back() == a_string.back());

        t_string.pop();
        a_string.pop();
    }
    cout << "Pass" << endl;
    cout << endl;

    cout << "Const object test" << endl;
    const Queue<string> co_string;
    assert(co_string.size() == 0);
    assert(co_string.front() == co_string.front());
    assert(co_string.back() == co_string.back());

    cout << "Pass" << endl;

    cout << endl;
    cout << "Testing Queue::clear & empty" << endl;
    t_string.clear();
    assert(t_string.empty() == true);
    cout << "Pass" << endl;
    cout << endl;
    return 0;
}