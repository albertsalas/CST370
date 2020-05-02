/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw10/challenges/radix-sort-4-1/submissions/code/1323272712
 * Title: hw10_1
 * Abstract: Radix Sort
 * Author: Albert Salas
 * ID: 7777
 * Date: 05/01/2020
 */

#include <iostream>
#include <vector>

using namespace std;

void copyPrintArray(vector<int> &nums, vector<int> &nums2) {
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = nums2[i];
        cout << nums[i] << " ";
    }
    cout << endl;
}

void radixSort(vector<int> &nums, int maximum) {
    for (int position = 1; (maximum / position) > 0; position *= 10) {
        vector<int> newNums(nums.size());
        vector<int> buckets(10);

        for (int num : nums) {
            buckets[(num / position) % 10]++;
        }

        // cumulative sum of each bucket count
        for (int i = 1; i < buckets.size(); i++) {
            buckets[i] += buckets[i - 1];
        }

        for (int i = (int) nums.size() - 1; i >= 0; i--) {
            int newBucket = --buckets[(nums[i] / position) % 10];
            newNums[newBucket] = nums[i];
        }
        copyPrintArray(nums, newNums);
    }
}

int main() {
    int n;
    cin >> n;
    // store num with most digits
    int maximum = 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        maximum = max(nums[i], maximum);
    }
    radixSort(nums, maximum);
    return 0;
}