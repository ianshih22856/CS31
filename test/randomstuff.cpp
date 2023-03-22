#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
#include <cctype>
using namespace std;

string CreateAcronym(string userPhrase)
{
    vector<string> acronymLetters;
    if (isupper(userPhrase[0]))
    {
        acronymLetters.push_back(string(1, userPhrase[0]));
    }
    for (int i = 1; i < userPhrase.size(); i++)
    {
        if (string(1, userPhrase[i]) == " " && isupper(userPhrase[i + 1]))
        {
            acronymLetters.push_back(string(1, userPhrase[i + 1]));
        }
    }

    string acronym = "";
    for (int j = 0; j < acronymLetters.size(); j++)
    {
        string letter = acronymLetters.at(j);
        acronym = acronym + letter + ".";
    }
    return acronym;
}

int main()
{
    string name;
    cout << "enter phrase: " << endl;
    getline(cin, name);

    string acronym = CreateAcronym(name);
    cout << acronym << endl;
}
