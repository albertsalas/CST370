/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw1/challenges/max-events/submissions/code/1320108807
 * Title: hw1_2.cpp
 * Abstract: Reads the time information of events in a convention center
 *           and displays the maximum number of concurrent events in the convention center
 * Author: Albert Salas
 * ID: 7777
 * Date: 01/29/2020
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int events;
    cin >> events;
    vector<int> start(events);
    vector<int> end(events);

    for (int i = 0; i < events; i++) {
        cin >> start[i];
        cin >> end[i];
    }
    int maxEvents = 0;
    for (int i = 0; i < events; i++) {
        int currentMax = 0;
        for (int j = 0; j < events; j++) {
            if (start[i] >= start[j] && start[i] <= end[j]) {
                currentMax++;
            }
        }
        if (currentMax > maxEvents) {
            maxEvents = currentMax;
        }
    }
    cout << "Answer:";
    cout << maxEvents;
}