/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw4/challenges/matching-form/submissions/code/1321046399
 * Title: hw4_1
 * Abstract: Reads a string of brackets and check if it’s well-formed or not.
 * Author: Albert Salas
 * ID: 7777
 * Date: 02/20/2020
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    string p;
    cin >> p;
    if (p.size() % 2 != 0){
        cout << "FALSE" << endl;
        return 0;
    }
    stack<char> s;
    for (char c : p) {
        s.push(c);
    }
    unordered_map<char, int> count;
    count.insert({{'(', 0},
                  {')', 0},
                  {'[', 0},
                  {']', 0},
                  {'{', 0},
                  {'}', 0}});
    while (!s.empty()) {
        char temp = s.top();
        count[temp] += 1;
        s.pop();
        switch (temp) {
            case '(':
                if (count['('] > count[')']) {
                    cout << "FALSE" << endl;
                    return 0;
                }
            case '[':
                if (count['['] > count[']']) {
                    cout << "FALSE" << endl;
                    return 0;
                }
            case '{':
                if (count['{'] > count['}']) {
                    cout << "FALSE" << endl;
                    return 0;
                }
            default:
                continue;
        }
    }
    if (count['('] == count[')'] && count['['] == count[']'] && count['{'] == count['}']) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }
    return 0;
}