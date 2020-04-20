/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw4/challenges/partitioning-numbers/submissions/code/1321053383
 * Title: hw4_2
 * Abstract: Puts all negative numbers in front of all positive numbers.
 * Author: Albert Salas
 * ID: 7777
 * Date: 02/20/2020
 */

#include <iostream>
#include <vector>


using namespace std;

int main() {
    int length;
    cin >> length;
    vector<int> nums(length);
    vector<int> secondNums(length);
    for (int i = 0; i < length; ++i) {
        int temp;
        cin >> temp;
        nums[i] = temp;
        secondNums[i] = temp;
    }

    int start = 0;
    int end = length - 1;
    while (start < end) {
        if (nums[start] >= 0 && nums[end] < 0) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            ++start;
            --end;
        }
        if (nums[start] < 0) {
            ++start;
        }
        if (nums[end] >= 0) {
            --end;
        }
    }
    int i = 0;
    int j = 1;
    while (j < length) {
        if (secondNums[i] >= 0 && secondNums[j] < 0) {
            swap(secondNums[i], secondNums[j]);
            ++i;
            ++j;
        }
        if (secondNums[i] < 0 && secondNums[j] < 0){
            ++i;
            ++j;
        }
        if (secondNums[i] < 0) {
            ++i;
        }
        if (secondNums[j] >= 0) {
            ++j;
        }
    }
    for (int &n : nums) {
        cout << n << ' ';
    }
    cout << endl;
    for (int &n : secondNums) {
        cout << n << ' ';
    }
    return 0;
}