/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw5/challenges/dfs-4/submissions/code/1321572429
 * Title: hw5_3
 * Abstract: Implements the Depth-First Search (DFS) algorithm using a stack and a mark array
 * Author: Albert Salas
 * ID: 7777
 * Date: 03/02/2020
 */

#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;

void DFS(const vector<list<int>> &adjList, vector<int> &mark, stack<int> &s, int &currentMark) {
    if (s.empty()) {
        return;
    }
    for (auto it = adjList[s.top()].begin(); it != adjList[s.top()].end(); ++it) {
        if (mark[*it] == 0) {
            s.push(*it);
            ++currentMark;
            mark[*it] = currentMark;
            DFS(adjList, mark, s, currentMark);
        }
    }
    s.pop();
}

int main() {
    int vertices;
    cin >> vertices;
    vector<list<int>> adjList(vertices);
    int edges;
    cin >> edges;
    int source, destination;
    for (int i = 0; i < edges; ++i) {
        cin >> source >> destination;
        adjList[source].push_back(destination);
    }
    if (vertices == 1) {
        cout << "Mark[" << 0 << "]:" << 1 << endl;
        return 0;
    }

    vector<int> mark(vertices);
    stack<int> s;
    mark[0] = 1;
    s.push(0);
    int currentMark = 1;
    DFS(adjList, mark, s, currentMark);
    for (int i = 0; i < mark.size(); ++i) {
        cout << "Mark[" << i << "]:" << mark[i] << endl;
    }
    return 0;
}