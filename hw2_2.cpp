/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw2/challenges/time-difference-2/submissions/code/1320312136
 * Title: hw2_2
 * Abstract: Reads two timestamps of two events from a user and displays the difference between the two timestamps
 * Author: Albert Salas
 * ID: 7777
 * Date: 02/03/2020
 */

#include <iostream>
#include <string> 
#include <iomanip>
using namespace std;
int main() {
  int hh, mm, ss;
  cin >> hh;
  cin.ignore(2,':');
  cin >> mm;
  cin.ignore(2,':');
  cin >> ss;
  int time1 = (hh * 3600) +  (mm * 60) + ss;
  cin >> hh;
  cin.ignore(2,':');
  cin >> mm;
  cin.ignore(2,':');
  cin >> ss;
  int time2 = (hh * 3600) +  (mm * 60) + ss;
  int duration = time2 - time1;
  if (duration < 0){
      duration = duration + 86400;
  }
  hh = duration / 3600;
  duration %= 3600;
  mm = duration / 60;
  duration %= 60;
  ss = duration;

  cout << setw(2) << setfill('0') << hh << ':' << setw(2) << setfill('0') << mm << ':' << setw(2) << setfill('0') << ss;
}