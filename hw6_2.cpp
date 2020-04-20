/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw6/challenges/knapsack-8/submissions/code/1321764690
 * Title: hw6_2
 * Abstract:
 * Author: Solves the Knapsack problem
 * ID: 7777
 * Date: 03/13/2020
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
    // generate permutations totaling less than the capacity
    // return highest value permutation
    int items;
    int capacity;
    cin >> items;
    cin >> capacity;
    unordered_map<int, int> weightValue;
    vector<int> weights;
    for (int i = 0; i < items; ++i) {
        int weight, value;
        cin >> weight >> value;
        weightValue.insert({weight, value});
        weights.push_back(weight);
    }
    int maxValue = 0;
    vector<int> bestCombo;
    int bestComboWeight = 0;
    int totalCombos = pow(2, items); // how many different combinations there are
    for (int i = 1; i < totalCombos; ++i) {
        int temp = i;
        vector<int> combo(items);
        int index = items - 1;
        while (temp > 0 && index >= 0) {
            combo[index] = temp % 2;
            index--;
            temp = temp / 2;
        }
        int currentWeight = 0;
        int currentValue = 0;
        for (int j = 0; j < combo.size(); ++j) {
            if (combo[j] == 1) {
                currentWeight += weights[j];
                currentValue += weightValue[weights[j]];
            }
        }
        if (currentWeight <= capacity && currentValue > maxValue) {
            maxValue = currentValue;
            bestCombo = combo;
            bestComboWeight = currentWeight;
        }
    }
    cout << "Items:";
    if (bestCombo.empty()) {
        cout << endl << "Capacity:" << endl;
        cout << "Value:" << endl;
    } else {
        for (int j = 0; j < bestCombo.size(); ++j) {
            if (bestCombo[j] == 1) {
                cout << j + 1 << " ";
            }
        }
        cout << endl;
        cout << "Capacity:" << bestComboWeight << endl;
        cout << "Value:" << maxValue;
    }


    return 0;
}