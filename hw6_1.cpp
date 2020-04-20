/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw6/challenges/divide-and-conquer-max/submissions/code/1321701377
 * Title: hw6_1
 * Abstract: Displays the biggest number in an array with n integer numbers using a divide-and-conquer technique
 * Author: Albert Salas
 * ID: 7777
 * Date: 03/11/2020
 */

#include <iostream>
#include <vector>


using namespace std;
int findMax(vector<int> nums, int start, int end) {
    if (start == end) {
        return nums[start];
    }
    int mid = (end + start) / 2;
    int left = findMax(nums, start, mid);
    int right = findMax(nums, mid + 1, end);
    int m = max(left, right);
    return m;
}

int main() {
    int length;
    cin >> length;
    vector<int> nums;

    for (int i = 0; i < length; ++i) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    cout << findMax(nums, 0, length);
    return 0;
}