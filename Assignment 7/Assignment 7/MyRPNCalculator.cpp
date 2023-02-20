//Programmer: Anna Felipe
//Programmer ID: 1506055

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include "Stack.h"
using namespace std;

bool calcCommand(const string& input);
void performOp(const string& input, stack<double>& calcStack);

int main() {

	cout << "Programmer: Anna Felipe" << endl;
	cout << "Programmer ID: 1506055" << endl;
	cout << "File Name: " << __FILE__ << endl;
	cout << endl;

	stack<double> calcStack;
	string input;
			
	while (true) {


		cout << "Enter: ";
		while (!calcStack.empty()) {

				cout << calcStack.top() << " ";
				break;
		}
		
		cin >> input;
		
		double num;

		if (istringstream(input) >> num)
		{
				calcStack.push(num);
		}
		else if (calcCommand(input))
		{
				performOp(input, calcStack);
		}

	}
	system("PAUSE");
	return 0;
};
bool calcCommand(const string& input)
{
	string operands[] = { "-", "+", "*", "/" };

	for (int i = 0; i < 4; i++)
	{
		if (input == operands[i])
		{
			return true;
		}
	}
	return false;
}
void performOp(const string& input, stack<double>& calcStack)
{
	double num1, num2, result;

	if (input == "+") {
		num1 = calcStack.top();
		calcStack.pop();
		num2 = calcStack.top();
		calcStack.pop();
		result = num1 + num2;
	}
	if (input == "-") {
		num1 = calcStack.top();
		calcStack.pop();
		num2 = calcStack.top();
		calcStack.pop();
		result = num1 - num2;
	}
	if (input == "*") {
		num1 = calcStack.top();
		calcStack.pop();
		num2 = calcStack.top();
		calcStack.pop();
		result = num1 * num2;
	}
	if (input == "/") {
		num1 = calcStack.top();
		calcStack.pop();
		num2 = calcStack.top();
		calcStack.pop();
		result = num1/num2;
	}
	cout << result << endl;

}