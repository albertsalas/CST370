/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw2/challenges/reverse-number-13/submissions/code/1320311717
 * Title: hw2_1
 * Abstract: Reads a positive integer number from a user and displays the reverse of the number. 
 * Author: Albert Salas
 * ID: 7777
 * Date: 02/03/2020
 */
#include <iostream> 
#include <string> 
using namespace std;
int main(){
    string input;
    cin >> input;
    string output;
    for (int i = input.length() - 1; i >= 0; i--){
        output += input.at(i);
    }
    int num = stoi(output);
    cout << num;
}