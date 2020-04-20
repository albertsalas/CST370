/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw5/challenges/palindrome-check-10/submissions/code/1321377198
 * Title: hw5_1
 * Abstract: Checks if an input string is a palindrome or not.
 * Author: Albert Salas
 * ID: 7777
 * Date: 03/01/2020
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool checkPalindrome(string s, int start, int end) {
    if (start == end) {
        return true;
    }
    if (s.at(start) == s.at(end)) {
        return checkPalindrome(s, start + 1, end - 1);
    }
    return false;
}

int main() {
    string s;
    getline(std::cin, s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalpha(c) && !isdigit(c); }),
            s.end()); // https://stackoverflow.com/questions/28491954/remove-non-alphabet-characters-from-string-c
    if (s.length() <= 1) {
        cout << "TRUE";
        return 0;
    }
    if (checkPalindrome(s, 0, s.length() - 1)) {
        cout << "TRUE";
    } else {
        cout << "FALSE";
    }
    return 0;
}