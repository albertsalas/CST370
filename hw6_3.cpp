/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw6/challenges/connect-components/submissions/code/1321768245
 * Title: hw6_3
 * Abstract: Connects several connected components of a graph with minimum number of edges to create a single connected component of the graph.
 * Author: Albert Salas
 * ID: 7777
 * Date: 03/13/2020
 */
#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

void breadthFirstSearch(vector<list<int>> &adj, vector<int> &markArray, queue<int> q) {
    if (q.empty()) {
        return;
    }
    for (int &it : adj[q.front()]) {
        if (markArray[it] == 0) {
            markArray[it] = 1;
            q.push(it);
        }
    }
    q.pop();
    breadthFirstSearch(adj, markArray, q);
}

int main() {
    int vertices;
    cin >> vertices;
    int edges;
    cin >> edges;
    vector<list<int>> adj(vertices);
    for (int i = 0; i < edges; ++i) {
        int source, destination;
        cin >> source >> destination;
        adj[source].push_back(destination);
    }
    vector<int> markArray(vertices);

    // since it starts at 0, it gets pushed to the queue and the connections since any connection is going to connect to 0
    queue<int> q;
    q.push(0);
    vector<int> connections;
    connections.push_back(0);
    markArray[0] = 1;
    breadthFirstSearch(adj, markArray, q);
    for (int i = 0; i < markArray.size(); ++i) {
        if (markArray[i] == 0) {
            markArray[i] = 1;
            q.push(i);
            connections.push_back(i);
            breadthFirstSearch(adj, markArray, q);
        }
    }
    
    if (connections.size() == 1) {
        cout << "No new edge:";
    } else {
        for (int i = 0; i < connections.size(); ++i) {
            if (i + 1 < connections.size()) {
                cout << "Edge: " << connections[i] << "-" << connections[i + 1] << endl;
            }
        }
    }
    return 0;
}