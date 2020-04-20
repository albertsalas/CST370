/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw3/challenges/binary-numbs/submissions/code/1320628409
 * Title: hw3_1
 * Abstract: Reads elements and displays elements as binary numbers.
 * Author: Albert Salas
 * ID: 7777
 * Date: 02/11/2020
 */

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int main() {
    int length;
    cin >> length;
    if (length == 0){
        cout << "0:EMPTY" << endl;
        return 0;
    }
    vector<string> s(length);
    for (int i = 0; i < length; ++i){
        cin >> s[i];
    }

    for (int i = 0; i < pow(2, length); ++i) {
        int temp = i;
        vector<int> v(length);
        fill(v.begin(), v.end(), 0);
        int index = length -1;
        while (temp > 0) {
            v[index] = temp % 2;
            index--;
            temp = temp / 2;
        }
        string str;
        string binaryStr;
        for (int j = 0; j < s.size(); ++j){
            binaryStr.append(to_string(v[j]));
            if (v[j] == 1){
                str.append(s[j]);
                str.append(" ");
            }
        }
        binaryStr.append(":");
        if (str.empty()){
            cout << binaryStr << "EMPTY" << endl;
        } else {
            cout << binaryStr << str << endl;
        }
    }
    return 0;
}


