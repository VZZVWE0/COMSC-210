#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <queue>
#include <cmath>
#include <cstdlib>
#include "PriorityQueue.h"
#include "DynamicArray.h"

using namespace std;

struct Customer {
    char id;
    int arrivalTime;
};

struct ServerInfo {
    Customer customer;
    bool status;
    
};

struct ServiceEvent {
    int serverNum;
    int endTime;
};

int getRandomNumberOfArrivals(double);
char genID(char&);
int randTimeAdd(int, int);

bool operator<(const ServiceEvent& a, const ServiceEvent& b) {
    return a.endTime < b.endTime ? false : true;
}

int main() {
    srand(time(0));
    rand();

    cout << "Programmer: Anna Felipe\n";
    cout << "Programmer's ID: 1506055\n";
    cout << "File: " << __FILE__ << "\n\n";

    int numServers = 0;
    int MaxWait = 0;
    int minServTime = 0;
    int maxServTime = 0;
    int timer = 0;
    double avgArrivalRate = 0.0;
    char x = 'A';

    ifstream fin;
    fin.open("simulation.txt");
    int switchCount = 0;
    while (fin.good()) {

        string input;
        getline(fin, input);
        switch (switchCount) {
        case 0:
            numServers = atoi(input.c_str());
            cout << "number of servers:     " << numServers << endl;
            break;
        case 1:
            avgArrivalRate = atof(input.c_str());
            cout << "customer arrival rate: " << avgArrivalRate << " per minute, for " << timer << " minutes" << endl;
            break;
        case 2:
            MaxWait = atoi(input.c_str());
            cout << "maximum queue length:  " << MaxWait << endl;
            break;
        case 3:
            minServTime = atoi(input.c_str());
            cout << "minimum service time:  " << minServTime << " minutes" << endl;
            break;
        case 4:
            maxServTime = atoi(input.c_str());
            cout << "maximum service time:  " << maxServTime << " minutes" << endl;
            break;
        case 5:
            timer = atoi(input.c_str());
            break;
        default:
            throw ("UH OH - PROBLEM");
        }
        switchCount++;
    }

    queue<Customer> waitLine;
    DynamicArray<ServerInfo> servers;
    PriorityQueue<ServiceEvent> eventList;

    for (int time = 0; ; time++) {
        while ((eventList.top().endTime == time) && !eventList.empty()) {
            servers[eventList.top().serverNum].status = false;
            eventList.pop();
        }

  
     if (time < timer) {
            int numArrive = getRandomNumberOfArrivals(avgArrivalRate);
            for (int i = 0; i < numArrive; i++) {
                if (waitLine.size() < MaxWait) {
                    Customer c;
                    c.id = genID(x);
                    c.arrivalTime = time;
                    waitLine.push(c);
                }
            }
        }

        for (int i = 0; i < numServers; i++) {
            if (!servers[i].status && !waitLine.empty()) {
                servers[i].customer = waitLine.front();
                waitLine.pop();
                servers[i].status = true;
                ServiceEvent temp = { i, time + randTimeAdd(minServTime, maxServTime) };
                eventList.push(temp);
            }
        }

        cout << endl;
        cout << "Time: " << time << endl;
        cout << "-----------------------------" << endl;
        cout << "server now serving wait queue" << endl;
        cout << "------ ----------- ----------" << endl;
        for (int i = 0; i < numServers; i++) {
            string show = " ";
            if (servers[i].status) {
                show = servers[i].customer.id;
            }
            cout << setw(4) << i << setw(10) << show;
            if (i == 0) {
                queue<Customer> tempQ = waitLine;
                cout << setw(10);
                while (!tempQ.empty()) {
                    cout << tempQ.front().id;
                    tempQ.pop();
                }
            }
            cout << endl;    
        }

        cout << endl;
        cout << "server | time for end-of-service" << endl;
        cout << "------ + -----------------------" << endl;
        for (PriorityQueue<ServiceEvent> temp = eventList; !temp.empty(); temp.pop()) {
            cout.width(4);
            cout << temp.top().serverNum << "   |";
            cout.width(4);
            cout << temp.top().endTime << endl;
        }


        int numIdle = 0;
        for (int i = 0; i < numServers; i++) {
            if (!servers[i].status) {
                numIdle++;
            }
        }
        if (numIdle == numServers && time >= timer) {
            break;
        }
        do {
            cout << endl;
            cout << "Press ENTER to continue...";
        } while (cin.get() != '\n');
    }
}

int randTimeAdd(const int a, const int b) {
    return a + (rand() % b);
}

char genID(char& x) {
    if (x == 'Z') {
        x = 'A';
        return 'Z';
    }
    return x++;
}

int getRandomNumberOfArrivals(double averageArrivalRate) {
    int arrivals = 0;
    double probOfnArrivals = exp(-averageArrivalRate);
    for (double randomValue = (double)rand() / RAND_MAX;
        (randomValue -= probOfnArrivals) > 0.0;
        probOfnArrivals *= averageArrivalRate / static_cast<double>(++arrivals));
    return arrivals;
}