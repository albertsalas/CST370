/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw7/challenges/apple-collection/submissions/code/1322199944
 * Title: hw7_1
 * Abstract: Collects the maximum number of apples in boxes
 * Author: Albert Salas
 * ID: 7777
 * Date: 03/27/2020
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    int l;
    cin >> l;
    vector<int> boxes(l);
    for (int i = 0; i < l; i++) {
        cin >> boxes[i];
    }
    int totalCombos = pow(2, l);
    int max = 0;
    for (int i = 1; i < totalCombos; i++) {
        int temp = i;
        bool validCombo = true;
        vector<int> combo(l);
        int index = l - 1;
        while (temp > 0 && index >= 0) {
            combo[index] = temp % 2;
            temp = temp / 2;
            if (combo[index] == 1 && temp % 2 == 1) {
                validCombo = false;
                break;
            }
            index--;
        }
        if (validCombo) {
            int sum = 0;
            for (int j = 0; j < combo.size(); j++) {
                if (combo[j] == 1) {
                    sum += boxes[j];
                }
            }
            if (sum > max) {
                max = sum;
            }
        }
    }
    cout << "Max Apples: " << max;
    return 0;
}