//Programmer: Anna Felipe
//Programmer ID: 1506055

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Queue.h"
#include "DynamicArray.h"

using namespace std;

struct Customer {

	char id;
	int arrivalTime;
	int endTime;
};

int getRandomNumberOfArrivals(double);
char genID(char&);
int randTimeAdd(int, int);


int main() {

	char curAlpha = 'A';

	cout << "Programmer: Anna Felipe" << endl;
	cout << "Programmer ID: 1506055" << endl;
	cout << "File Name: Simulation" << endl;
	cout << endl;

	srand(time(0));
	rand();

	int servers = 0;
	int maxWait = 0;
	int minServ = 0;
	int maxServ = 0;
	int atime = 0;

	double arrivalRate = 0.5;

	ifstream simFile;
	simFile.open("simulation.txt");

	if (simFile.is_open()) {

		string line;

		int switchCount = 0;

		while (getline(simFile, line)) {

			switch (switchCount) {

				case 0:
					servers = atoi(line.c_str());
					cout << "number of servers: " << servers << endl;
					break;

				case 1:
					arrivalRate = atof(line.c_str());
					break;

				case 2:
					maxWait = atoi(line.c_str());
					cout << "maximum queue length: " << maxWait << endl;
					break;

				case 3:
					minServ = atoi(line.c_str());
					cout << "minimum service time: " << minServ << " minutes" << endl;
					break;

				case 4:
					maxServ = atoi(line.c_str());
					cout << "maximum service time: " << maxServ << " minutes" << endl;
					break;

				case 5:
					atime = atoi(line.c_str());
					cout << "customer arrival rate: " << arrivalRate << " per minute, for " << atime << " minutes" << endl;
					break;

				default:
					throw("Error");

				};
			switchCount++;
		};
	};

	Queue<Customer> custQ;
	DynamicArray<Customer> nowServing;
	DynamicArray<int> serversStatus;

	for (int time = 0;; time++)	{

		for (int i = 0; i < servers; i++)	{

			if (serversStatus[i])	{ 

				if (nowServing[i].endTime == time)	{

					serversStatus[i] = false;
				}
			}
		}

		if (time < atime)	{

			int numArrive = getRandomNumberOfArrivals(arrivalRate);

				for (int i = 0; i < numArrive; i++)	{

					if (custQ.size() < maxWait)	{

					Customer c;

					c.id = genID(curAlpha);
					c.arrivalTime = time;
					custQ.push(c);
				}
			}
		}
		
		for (int i = 0; i < servers; i++)	{

			if (!serversStatus[i] && !custQ.empty())	{

				nowServing[i] = custQ.front();

				custQ.pop();

				nowServing[i].endTime = time + randTimeAdd(minServ, maxServ);

				serversStatus[i] = true;
			}
		}

	cout << endl;
	cout << "Time: " << time << endl;
	cout << "---------------------------" << endl;
	cout << "server now serving wait queue" << endl;
	cout << "------ ----------- ----------" << endl;

		for (int i = 0; i < servers; i++)	{

			string show = " ";

			if (serversStatus[i])	{

				show = nowServing[i].id;

			}

		cout << setw(2) << i << setw(10) << show;

		if (i == 0)	{

			Queue<Customer> tempQ = custQ;

			cout << setw(10);

			while (!tempQ.empty())	{

					cout << tempQ.front().id;

					tempQ.pop();
				}
			}
				cout << endl;
		}

		int numIdle = 0;

		for (int i = 0; i < servers; i++)	{

			if (!serversStatus[i])	{

				numIdle++;
			}
		}

		if (numIdle == servers && time >= atime)	{

			break;

		}
		do	{

			cout << endl;

			cout << "Press ENTER to continue..." << endl;

		} while (cin.get() != '\n');

	}

	system("PAUSE");

}

int randTimeAdd(const int a, const int b)	{

	return a + (rand() % b);

}

char genID(char& curAlpha)	{

	if (curAlpha == 'Z')	{

		curAlpha = 'A';

		return 'Z';
	}

	return curAlpha++;
}

int getRandomNumberOfArrivals(double averageArrivalRate)	{

	int arrivals = 0;

	double probOfnArrivals = exp(-averageArrivalRate);

	for (double randomValue = (double)rand() / RAND_MAX;

		(randomValue -= probOfnArrivals) > 0.0;

		probOfnArrivals *= averageArrivalRate / static_cast<int>(++arrivals));

	return arrivals;
}