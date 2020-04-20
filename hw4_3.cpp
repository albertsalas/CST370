/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw4/challenges/tsp-2-1/submissions/code/1321085983
 * Title: hw4_3
 * Abstract: Reads an input graph data from a user first. Then, it presents a path for the travelling salesman problem (TSP).
 * Author: Albert Salas
 * ID: 7777
 * Date: 02/21/2020
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <array>

using namespace std;

int generatePath(vector<int> &a, int n, const vector<vector<int>> &paths) {
    int currentPathCost = 0;
    // 0 2 1 4 3 0
    for (int i = -1; i < n; ++i) {
        if (i == -1) {
            if (paths[0][a[0]] == 0) {
                return -1;
            }
            currentPathCost += paths[0][a[0]];
        } else if (i == n - 1) {
            if (paths[a[n - 1]][0] == 0) {
                return -1;
            }
            currentPathCost += paths[a[n - 1]][0];
        } else {
            if (paths[a[i]][a[i + 1]] == 0) {
                return -1;
            }
            currentPathCost += paths[a[i]][a[i + 1]];
        }
    }
    return currentPathCost;
}

vector<int> findShortestPath(vector<int> a, int n, const vector<vector<int>> &paths) {
    vector<int> shortestPath;
    int shortestPathCost = -1;
    sort(a.begin(), a.end());
    while (next_permutation(a.begin(), a.end())) {
        int currentPathCost = generatePath(a, n, paths);
        if ((shortestPathCost == -1 || currentPathCost < shortestPathCost) && currentPathCost > 0) {
            copy(a.begin(), a.end(), back_inserter(shortestPath));
            shortestPathCost = currentPathCost;
        }
    }
//    shortestPath.insert(shortestPath.begin(), 0);
    shortestPath.push_back(shortestPathCost);
    return shortestPath;
}

int main() {
    int numCities;
    cin >> numCities;
    map<string, int> cityNum;
    map<int, string> numCity;
    vector<int> nums(numCities - 1);
    for (int i = 0; i < numCities; ++i) {
        string city;
        cin >> city;
        cityNum.emplace(city, i);
        numCity.emplace(i, city);
    }

    for (int i = 0; i < numCities - 1; ++i) {
        nums[i] = i + 1;
    }

    int totalPaths;
    cin >> totalPaths;
    vector<vector<int>> paths(numCities);
    for (auto &p : paths) {
        p.resize(numCities);
    }
    for (int i = 0; i < totalPaths; ++i) {
        string source, destination;
        int cost;
        cin >> source >> destination >> cost;
        int s = cityNum[source];
        int d = cityNum[destination];
        paths[s][d] = cost;
    }
    vector<int> result(findShortestPath(nums, numCities - 1, paths));
    if (result[result.size() - 1] == -1) {
        cout << "Path:" << endl;
        cout << "Cost:" << -1 << endl;
    } else {
        cout << "Path:";
        cout << numCity[0] << "->";
        for (int i = 0; i < result.size() - 1; ++i) {
            cout << numCity[result[i]] << "->";
        }
        cout << numCity[0];
        cout << endl;
        cout << "Cost:" << result[result.size() - 1];
    }
    return 0;
}