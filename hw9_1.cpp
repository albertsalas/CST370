/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw9/challenges/max-heap-1-2/submissions/code/1322884765
 * Title: hw9_1
 * Abstract: Implements heap and its operations as an array.
 * Author: Albert Salas
 * ID: 7777
 * Date: 04/19/2020
 */
#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
public:
    vector<int> nums;

    void heapify() {
        // last non-leaf node
        int lastParentIndex = (nums.size() - 2) / 2;
        int i = lastParentIndex;
        while (i >= 0) {
            i = min(i, lastParentIndex);
            int leftChildIndex = (2 * i) + 1;
            int rightChildIndex = leftChildIndex + 1;
            int biggestChildIndex;
            // check to see the the last non-leaf node has only one child
            if (rightChildIndex >= nums.size()) {
                biggestChildIndex = leftChildIndex;
            } else {
                if (nums[leftChildIndex] > nums[rightChildIndex]) {
                    biggestChildIndex = leftChildIndex;
                } else {
                    biggestChildIndex = rightChildIndex;
                }
            }
            if (nums[biggestChildIndex] > nums[i]) {
                int temp = nums[i];
                nums[i] = nums[biggestChildIndex];
                nums[biggestChildIndex] = temp;
                i = biggestChildIndex;
            } else {
                i--;
            }
        }
//        display();
    }

    void checkHeap() {
        for (int i = 1; i < nums.size(); i++) {
            int parentIndex = (i - 1) / 2;
            if (nums[i] > nums[parentIndex]) {
                cout << "This is NOT a heap." << endl;
                heapify();
                return;
            }
        }
        cout << "This is a heap." << endl;
    }

    void displayMax() {
        cout << nums[0] << endl;
    }

    void insert(int n) {
        nums.push_back(n);
        heapify();
    }

    void deleteMax() {
        nums[0] = nums[nums.size() - 1];
        nums.pop_back();
        heapify();
    }

    void deleteNum(int n) {
        for (int &num : nums) {
            if (num == n) {
                num = nums[nums.size() - 1];
                nums.pop_back();
                heapify();
                return;
            }
        }
    }

    void update(int index, int n) {
        nums[index] = n;
        heapify();
    }

    void display() {
        for (int i : nums) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    int length;
    cin >> length;
    MaxHeap maxHeap;
    for (int i = 0; i < length; ++i) {
        int temp;
        cin >> temp;
        maxHeap.nums.push_back(temp);
    }

    int numberOfCommands;
    cin >> numberOfCommands;
    cin.ignore();
    vector<string> commands(numberOfCommands);
    for (int i = 0; i < numberOfCommands; ++i) {
        string s;
        getline(cin, s);
        commands[i] = s;
    }

    maxHeap.checkHeap();

    for (const string &s : commands) {
        if (s == "displayMax") {
            maxHeap.displayMax();
        } else if (s.find("insert") != string::npos) {
            int n = stoi(s.substr(6, s.size()));
            maxHeap.insert(n);
        } else if (s == "deleteMax") {
            maxHeap.deleteMax();
        } else if (s.find("delete") != string::npos) {
            int n = stoi(s.substr(6, s.size()));
            maxHeap.deleteNum(n);
        } else if (s.find("update") != string::npos) {
            int index = stoi(s.substr(6, 8));
            int n = stoi(s.substr(8, s.size()));
            // use index - 1 b/c he's using 1 based indexing
            maxHeap.update(index - 1, n);
        } else if (s == "display") {
            maxHeap.display();
        }
    }

    return 0;
}