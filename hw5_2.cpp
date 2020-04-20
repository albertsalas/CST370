/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw5/challenges/bfs-hops/submissions/code/1321570860
 * Title: hw5_2
 * Abstract: Displays the city names in the range of hop(s) from a starting city
 * Author: Albert Salas
 * ID: 7777
 * Date: 3/6/2020
 */

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

unordered_set<string> BFS(map<string, list<string>> &adjList, map<string, int> &mark, string &start) {
    unordered_set<string> neighborsFound;
    for (auto it = adjList[start].begin(); it != adjList[start].end(); ++it) {
        if (mark[*it] == 0) {
            neighborsFound.insert(*it);
            mark[*it] = 1;
        }
    }
    return neighborsFound;
}

set<string> hop(map<string, list<string>> &adjList, string &start, map<string, int> &mark, int &hops) {
    set<string> neighborsWithinHopDistance;
    neighborsWithinHopDistance.insert(start);
    unordered_set<string> currentCities;
    currentCities.insert(start);

    for (int i = 0; i < hops; ++i) {
        unordered_set<string> neighbors;
        for (string s : currentCities) {
            unordered_set<string> currentNeighbors = BFS(adjList, mark, s);
            neighbors.insert(currentNeighbors.begin(), currentNeighbors.end());
        }
        for (const string &s : neighbors) {
            neighborsWithinHopDistance.insert(s);
        }
        currentCities = neighbors;
    }
    return neighborsWithinHopDistance;
}

int main() {
    int cities;
    cin >> cities;
    map<string, list<string>> adjList;
    map<string, int> mark;
    for (int i = 0; i < cities; ++i) {
        string source;
        cin >> source;
        list<string> temp;
        adjList.insert({source, temp});
        mark.insert({source, 0});
    }
    int paths;
    cin >> paths;
    for (int i = 0; i < paths; ++i) {
        string source, destination;
        cin >> source >> destination;
        adjList[source].push_back(destination);
    }
    string start;
    cin >> start;
    int hops;
    cin >> hops;

    mark[start] = 1;
    set<string> neighborsWithinHopDistance = hop(adjList, start, mark, hops);
    for (const string &s : neighborsWithinHopDistance) {
        cout << s << endl;
    }
    return 0;
}