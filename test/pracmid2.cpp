#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
#include <cctype>
#include <cstring>
#include <chrono>
#include <thread>
using namespace std;
using namespace this_thread;
using namespace chrono;

int updatePoints(int pos)
{
    if (pos == 3)
        return 1;
    if (pos == 1)
        return -1;
    if (pos == 5)
        return 2;
    if (pos == 2)
        return -2;
    return 0;
}
// DDURDDUR
int executeCommands(string cmdStr, int pos, int points)
{
    int i;
    for (i = 0; i < cmdStr.size(); i++)
    {
        if (cmdStr[i] !='U' && cmdStr[i] !='D' &&cmdStr[i] != 'L' && cmdStr[i] != 'R' )
        {
            return -1;
        }
        if (cmdStr[i] == 'R')
        {
            pos++;
        }
        else if (cmdStr[i] == 'L')
        {
            pos--;
        }
        points = points + updatePoints(pos);
        cout << "i: " << i << ", points = " << points << "||" << endl;
    }
    return points;
}
int main()
{
    // string command1 = "LULDR";
    // string command2 = "LRDULRDUXX";
    // string command3 = "UUDDLLRRBA";
    string command4 = "DDURDDUR";
    // cout << executeCommands(command1, 0, 0) << endl;
    // cout << executeCommands(command2, 1, 1) << endl;
    // cout << executeCommands(command3, 2, 2) << endl;
    cout << executeCommands(command4, 3, 3) << endl;
}