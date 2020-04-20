/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw3/challenges/adjacency-list/submissions/code/1320742345
 * Title: hw3_3.cpp
 * Abstract: Converts a directed graph data from a user into a corresponding adjacency list format
 * Author: Albert Salas
 * ID: 7777
 * Date: 02/13/2020
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int vertices;
    cin >> vertices;
    int edges;
    cin >> edges;
    vector<vector<int>> graph(vertices);
    for (int i = 0; i < vertices; ++i) {
        graph[i].push_back(i);
    }
    for (int i = 0; i < edges; ++i) {
        int v1, v2;
        cin >> v1;
        cin >> v2;
        graph[v1].push_back(v2);
        sort(graph[v1].begin() + 1, graph[v1].end());
    }
    for (const vector<int> &e : graph) {

        for (int i = 0; i < e.size(); ++i) {
            cout << e[i];
            if (i != e.size() - 1) {
                cout << "->";
            }
        }
        cout << endl;
    }
    return 0;
}


