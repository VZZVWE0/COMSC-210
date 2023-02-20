//Programmer: Anna Felipe
//Programmer ID: 1506055

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

struct Node
{
    string name;

    bool cityPassed;
    list<pair<int, double> > neighbors;
    int prev;
    double cost;
};

struct Terminus 
{
    int index; 
    int prev; 
    double cost; 
};

bool operator<(const Terminus& a, const Terminus& b)
{
    return b.cost < a.cost;
}

pair<stack<int>, double> getCheapestRoute(int iStart, int iEnd, vector<Node>& database)
{
    pair<stack<int>, double> result;
   
    for (int i = 0; i < database.size(); i++) 
    {
        database[i].cost = 0;
        database[i].prev = -1;
        database[i].cityPassed = false;
    }
    
    priority_queue<Terminus> toDo;
    
    Terminus startNode = { iStart, -1, 0 };
    toDo.push(startNode);
  
    while (!toDo.empty()) {
        
        Terminus popT = toDo.top();
        toDo.pop();
        if (database[popT.index].cityPassed)
        {
            continue;
        }
       
        database[popT.index].cityPassed = true;
        database[popT.index].cost = popT.cost;
        database[popT.index].prev = popT.prev;
       
        if (popT.index == iEnd) 
        {
            break;
        }
        for (pair<int, double>& neb : database[popT.index].neighbors) 
        {
           
            Terminus temp = { neb.first, popT.index, database[popT.index].cost + neb.second };
            toDo.push(temp);
        }
    }
    result.second = database[iEnd].cost;

    int nextIndex = iEnd;

    while (nextIndex != iStart) 
    {
        result.first.push(nextIndex);
        nextIndex = database[nextIndex].prev;
    }
    result.first.push(iStart);
    return result;
}

int main()
{
    cout << "Programmer: Anna Felipe" << endl;
    cout << "Programmer's ID: 1506055" << endl;
    cout << "File: " << __FILE__ << endl; 

    ifstream fin;
    fin.open("cities.txt");
    if (!fin.good()) throw "I/O error";
  
    vector<Node> database;

    while (fin.good()) 
    {
        string startCity, endCity, cost;
      
        getline(fin, startCity);
        getline(fin, endCity);
        getline(fin, cost);
        fin.ignore(1000, 10); 
  
        int iToNode = -1, iFromNode = -1, i;
        for (i = 0; i < database.size(); i++) 
            if (database[i].name == startCity)
                break;

        if (i == database.size()) 
        {
            
            Node fromNode = { startCity };
            database.push_back(fromNode);
        }
        iFromNode = i;

        for (i = 0; i < database.size(); i++)
            if (database[i].name == endCity)
                break;

        if (i == database.size()) 
        {
            
            Node toNode = { endCity };
            database.push_back(toNode);
        }
        iToNode = i;
      
        double edgeCost = atof(cost.c_str());
        database[iFromNode].neighbors.push_back(pair<int, double>(iToNode, edgeCost));
        database[iToNode].neighbors.push_back(pair<int, double>(iFromNode, edgeCost));
    }
    fin.close();
    
    while (true)
    {
        string startCity, endCity;
        cout << "\nEnter the source city [blank to exit]: ";
        getline(cin, startCity);
        if (startCity.length() == 0) break;
        
        int iFrom;
        for (iFrom = 0; iFrom < database.size(); iFrom++)
            if (database[iFrom].name == startCity)
                break;

        cout << "Enter the destination city [blank to exit]: ";
        getline(cin, endCity);
        if (endCity.length() == 0) break;
        
        int iTo;
        for (iTo = 0; iTo < database.size(); iTo++)
            if (database[iTo].name == endCity)
                break;
 
        pair<stack<int>, double> result = getCheapestRoute(iFrom, iTo, database);
        cout << "Total miles : " << result.second;

        for (; !result.first.empty(); result.first.pop())
            cout << '-' << database[result.first.top()].name;      
        cout << endl;
    }
}