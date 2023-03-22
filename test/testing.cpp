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

int main()
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string word = "";
    string target = "hello world";
    for (int i = 0; i < 11; i++)
    {
        cout << word << endl;
        if (i == 5)
        {
            word.push_back(' ');
            continue;
        }
        else 
        {
            word.push_back(alphabet[0]);
        }
        int charIndex = alphabet.find(tolower(target[i]));
        for (int j = 1; j <= charIndex; j++)
        {
            sleep_for(nanoseconds(20000000));
            cout << word << endl;
            if ((i == 0 || i == 6) && j == charIndex)
            {
                word[i] = toupper(alphabet[j]);
            }
            else
            {
                word[i] = alphabet[j];
            }
        }
    }
    cout << word << endl;
    word.push_back('!');
    cout << word << endl;
}