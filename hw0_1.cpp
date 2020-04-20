/*
 * hackerrank link: https://www.hackerrank.com/contests/cst370-s20-hw0/challenges/370-hw0-1/submissions/code/1319660897
 * Title: hw_01.cpp
 * Abstract: This program reads the user's input data and conducts sum and difference
 *           operations, depending on the command key.
 * Name: Albert Salas
 * ID: 7777
 * Date: 01/21/2019
 */

#include <iostream>
using namespace std;
#include <stdio.h>
#include <vector>

int main(){ 
    while(true){
        vector<int> v(3);
        for (int i = 0; i < 3; i++){
            cin >> v[i];
            if (v[0] == 9){
                return 0;
            }
        }
        if (v[0] == 1){
            cout << v[1] + v[2];
            cout << "\n";
        } else if (v[0] == 2){
            int result = v[1] - v[2];
            if (result < 0){
                result = result * -1;
            }
            cout << result;
            cout << "\n";
        }
    }
    
    return 0;
}