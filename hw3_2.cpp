/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw3/challenges/equal-groups/submissions/code/1320670963
 * Title: hw3_2
 * Abstract: Partitions n positive integers into two disjoint sets with the same sum
 * Author: Albert Salas
 * ID: 7777
 * Date: 02/12/2020
 */

#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int length;
    int sum = 0;
    cin >> length;

    vector<int> nums(length);
    for (int i = 0; i < length; ++i){
        int temp;
        cin >> temp;
        sum += temp;
        nums[i] = temp;
    }
    if (length <= 1){
        cout << "Equal Set: 0" << endl;
        return 0;
    }

    if (sum % 2 != 0){
        cout << "Equal Set: 0" << endl;
        return 0;
    }
    sort(nums.begin(), nums.end());

    int permutations = pow(2, length);
    int i = 1;
    while(permutations > 0){
        int temp = i;
        vector<int> v(length);
        fill(v.begin(), v.end(), 0);
        int index = length - 1;
        while (temp > 0 && index > 0) {
            v[index] = temp % 2;
            index--;
            temp = temp / 2;
        }
        int tempSum = 0;
        set<int> s;
        for (int j = 0; j < v.size(); ++j){
            if (v[j] == 1){
                tempSum += nums[j];
                s.insert(nums[j]);
                if (tempSum == (sum / 2)){
                    set<int> t;
                    for (int n : nums){
                        if (s.find(n) == s.end()){
                            t.insert(n);
                        }
                    }
                    cout << "Equal Set: ";
                    if (*s.begin() < *t.begin()){
                        for (int n : s){
                            cout << n << " ";
                        }
                    } else {
                        for (int n : t){
                            cout << n << " ";
                        }
                    }

                    return 0;
                }
            }
        }
        --permutations;
        ++i;
    }

    cout << "Equal Set: 0" << endl;
    return 0;
}


