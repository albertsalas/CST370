/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw9/challenges/alien-alphabet/submissions/code/1323063620
 * Title: hw9_2
 * Abstract: Displays the alphabetical order of characters for an alien language
 * Author: Albert Salas
 * ID: 7777
 * Date: 03/24/2020
 */

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

void toLowercase(string &s) {
    for (unsigned int i = 0; i < s.size(); i++) {
        char c = s.at(i);
        s.at(i) = tolower(c);
    }
}

bool connectedGraph(vector<int> &inDegree) {
    for (int i : inDegree) {
        if (i > 0) {
            return true;
        }
    }
    cout << "Invalid input." << endl;
    return false;
}

void topologicalSort(unordered_map<char, unordered_set<char>> &graph, vector<int> &inDegree) {
    vector<char> keys;
    keys.reserve(graph.size());
    for (auto &it : graph) {
        keys.push_back(it.first);
    }
    queue<char> q;
    for (char c : keys) {
        if (inDegree[c - 'a'] == 0) {
            q.push(c);
        }
    }
    vector<char> topOrder;
    while (!q.empty()) {
        char c = q.front();
        q.pop();
        topOrder.push_back(c);
        for (char child : graph[c]) {
            inDegree[child - 'a']--;
            if (inDegree[child - 'a'] == 0) {
                q.push(child);
            }
        }
    }
    // if the vector with chars isn't the same size as the original graph, then there is a cycle somewhere
    if (topOrder.size() != graph.size()) {
        cout << "Invalid input." << endl;
        return;
    }
    for (unsigned int i = 0; i < topOrder.size(); ++i) {
        cout << topOrder[i];
        if (i != topOrder.size() - 1) {
            cout << "->";
        }
    }
    cout << endl;
}

int main() {
    int numberOfWords;
    cin >> numberOfWords;
    vector<string> words;
    while (numberOfWords > 0) {
        string s;
        cin >> s;
        toLowercase(s);
        words.push_back(s);
        numberOfWords--;
    }
    unordered_map<char, unordered_set<char>> graph;
    // for all 26 chars in the alphabet
    vector<int> inDegree(26);
    for (const string &word : words) {
        for (char c : word) {
            unordered_set<char> newSet;
            graph.insert({c, newSet});
        }
    }

    for (unsigned int i = 1; i < words.size(); i++) {
        string word1 = words[i - 1];
        string word2 = words[i];
        int size = max((int) word1.size(), (int) word2.size());
        unsigned int j = 0;
        while (j < word1.size() && j < word2.size()) {
            char c1 = word1.at(j);
            char c2 = word2.at(j);
            if (c1 != c2) {
                if (graph[c1].find(c2) == graph[c1].end()) {
                    graph[c1].insert(c2);
                    // subtract 'a' to represent char as an int
                    inDegree[c2 - 'a']++;
                }
                // use j to break the loop
                j = size;
            }
            j++;
        }
    }
    if (connectedGraph(inDegree)) {
        topologicalSort(graph, inDegree);
    }
    return 0;
}