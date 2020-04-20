/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw8/challenges/kahns-topological-sort/submissions/code/1322591180
 * Title: hw8_2
 * Abstract: Conducts the topological sorting based on the source removal algorithm 
 * Author: Albert Salas
 * ID: 7777
 * Date: 04/09/2020
 */

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;


int main() {
    int numVertices;
    int numEdges;
    cin >> numVertices;
    cin >> numEdges;
    vector<list<int>> adjList(numVertices);
    vector<int> inDegree(numVertices);
    for (int i = 0; i < numEdges; i++) {
        int source, destination;
        cin >> source >> destination;
        adjList[source].push_back(destination);
        inDegree[destination]++;
    }
    queue<int> q;
    for (int i = 0; i < inDegree.size(); i++) {
        cout << "In-degree[" << i << "]:" << inDegree[i] << endl;
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topOrder;
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        topOrder.push_back(vertex);
        for (auto i : adjList[vertex]) {
            inDegree[i]--;
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
    }
    if (topOrder.size() != adjList.size()) {
        string s = "No Order:";
        cout << s;
    } else {
        cout << "Order:";
        for (int i = 0; i < topOrder.size(); i++) {
            cout << topOrder[i];
            if (i != topOrder.size() - 1) {
                cout << "->";
            }
        }
    }
    return 0;
}