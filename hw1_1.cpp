/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw1/challenges/common-nums/submissions/code/1320046892
 * Title: hw1_1.cpp
 * Abstract: Reads two groups of numbers in which each group has random integer numbers with possible duplicates. 
 * Author: Albert Salas
 * ID: 7777
 * Date: 01/29/2020
 */

 #include <iostream>
using namespace std;
#include <bits/stdc++.h> 
#include <stdio.h>
#include <vector>


int main() {
	int len = 0;
	
	cin >> len;
	set<int> v; 
	while (len > 0){
		int temp;
		cin >> temp;
		v.insert(temp);
    	len--;
	}
	cin >> len;
	set<int> answer;
	while (len > 0){
		int temp;
		cin >> temp;
		if (v.find(temp) != v.end()){
			answer.insert(temp);
		}
    	len--;
	}

	if (answer.empty()){
		cout << "Answer:NONE";
	} else {
		cout << "Answer:";
		for (auto it=answer.begin(); it != answer.end(); ++it) {
			cout << *it << ' ';
		}
	}
	
}