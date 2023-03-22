#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <bits/stdc++.h>
using namespace std;

// Convert letters to uppercase.
string ConvertToUppercase(string convert)
{
    transform(convert.begin(), convert.end(), convert.begin(), ::toupper);
    return convert;
}

// Split poll data into poll data segments for each state. 
vector<string> SplitPollData(string pollData)
{
    int endPosition = pollData.find(",");
    vector<string> splitList = {};
    if (endPosition < 0)
    {
        splitList.push_back(pollData);
    }
    else
    {
        int startPosition = 0;
        string section;
        while (endPosition >= 0)
        {
            section = pollData.substr(startPosition, endPosition - startPosition);
            splitList.push_back(section);
            startPosition = endPosition + 1;
            endPosition = pollData.find(",", startPosition);
        }
        section = pollData.substr(startPosition, pollData.length() - startPosition);
        splitList.push_back(section);
    }
    return splitList;
}

// Determine if each state poll data is valid.
bool IsValidStatePollString(string statePollString)
{

    vector<string> stateCodeList{"AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "FL", "GA", "HI", "ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MA", "MD", "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "OH", "OK", "OR", "PA", "RI", "SC", "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY"};
    
    statePollString = ConvertToUppercase(statePollString);
    string stateCode = statePollString.substr(0, 2);
    vector<string>::iterator it;
    // Verifies first two chars as state code.
    it = find(stateCodeList.begin(), stateCodeList.end(), stateCode);
    if (it == stateCodeList.end())
    {
        return false;
    }

    int position = 2;
    // Used to check consecutive letters.
    string letter = "";
    while (position < statePollString.length())
    {
        char x = statePollString.at(position);
        // Convert character to ASCII value.
        int xASCII = int(x);
        // If character is number.
        if (xASCII >= 48 && xASCII <= 57)
        {
            if (position == (statePollString.length() - 1))
            {
                return false;
            }
            letter = "";
        }
        // If character is in alphabet.
        else if (xASCII >= 65 && xASCII <= 90)
        {
            // If there are two consecutive letters or a letter comes after state code.
            if (letter != "" || position == 2)
            {
                return false;
            }
            letter = string(1, x);
        }
        else
        {
            return false;
        }
        position++;
    }
    return true;
}

//Determine if poll data is valid
bool isValidPollString(string pollData)
{
    if(pollData == "")
    {
        return true;
    }
    vector<string> statePollStrings = SplitPollData(pollData);

    for (int i = 0; i < statePollStrings.size(); i++)
    {
        string statePollString = statePollStrings.at(i);
        if (!IsValidStatePollString(statePollString))
        {
            return false;
        }
    }
    return true;
}

// Count total seats for given party given poll data.
int countSeats(string pollData, char party, int &seatCount)
{
    int voteCount = 0;
    pollData = ConvertToUppercase(pollData);

    if (!isValidPollString(pollData))
    {
        return 1;
    }
    // Check if party parameter is not a letter in alphabet.
    if (!((int(party) >= 65 && int(party) <= 90) || (int(party) >= 97 && int(party) <= 122)))
    {
        return 2;
    }

    vector<string> pollStrings = SplitPollData(pollData);
    string uppercaseParty = string(1, party);
    uppercaseParty = ConvertToUppercase(uppercaseParty);

    for (int i = 0; i < pollStrings.size(); i++)
    {
        string stateString = pollStrings.at(i);
        int partyPosition = stateString.find(uppercaseParty);

        // Checks if party is found. 
        if (partyPosition < 0)
        {
            continue;
        }

        // Scans string for number after finding party. 
        // Starts two places to the left of the party character because the string is valid.
        // Scans numbers to the left until it hits a letter.
        int currentPosition = partyPosition - 2;
        while (int(stateString[currentPosition]) >= 48 && int(stateString[currentPosition] <= 57))
        {
            currentPosition--;
        }

        voteCount += stoi(stateString.substr(currentPosition + 1, partyPosition - currentPosition - 1));
    }
    seatCount = voteCount;

    return 0;
}

void TestPollData(string pollData, bool expectedResult)
{
    bool actualResult = isValidPollString(pollData);
    if (actualResult == expectedResult)
    {
        cout << pollData << " || success" << endl;
    }
    else
    {
        cout << pollData << " || FAIL ############" << endl;
    }
}

void RunTestCases()
{
    TestPollData("NY8d8r91f", true);
    TestPollData("NY8d8r91f,CA4d51r", true);
    TestPollData("Ny 8d3f", false);
    TestPollData("NY8d81r,CA4d51r,NV12R", true);
    TestPollData("NY8d8r91f", true);
    TestPollData("ct5d,ny9r17d1i", true);
    TestPollData("NY$d", false);
    TestPollData("NY9d12r", true);
    TestPollData("5d,ny9d", false);
    TestPollData("!NY4d", false);
    TestPollData("NY9d31f", true);
    TestPollData("ny9d3", false);
}

void TestCountSeats(string pollString, char party, int expRetValue, int expCount)
{
    int actCount;
    int actRetVal = countSeats(pollString, party, actCount);
    if(actRetVal > 0)
    {
        expCount = actCount;
    }
    if (actRetVal == expRetValue && actCount == expCount)
    {
        cout << pollString << " || success" << endl;
    }
    else
    {
        if (actRetVal != expRetValue)
        {
            cout << actRetVal << " || " << expRetValue << " || return value (act, exp) fail !!!!!!!!!!!!" << endl;
        }
        else
        {
            cout << actCount << " || " << expCount << " || count (act, exp) FAIL !!!!!!!!!!!!" << endl;
        }
    }
}

void RunCountSeats()
{
    TestCountSeats("NY8d8r91f", 'd', 0, 8);
    TestCountSeats("NY8d8r91f,CA4d51r", 'd', 0, 12);
    TestCountSeats("Ny 8d3f", 'd', 1, 0);
    TestCountSeats("NY8d81r,CA4d51r,NV12R", 'R', 0, 144);
    TestCountSeats("NY8d8r91f", 'F', 0, 91);
    TestCountSeats("ct5d,ny9r17d", 'I', 0, 0);
    TestCountSeats("NY$d", 'd', 1, 0);
    TestCountSeats("NY9d12r", 'f', 0, 0);
    TestCountSeats("5d,ny9d", 'D', 1, 0);
    TestCountSeats("!NY4d", 'd', 1, 0);
    TestCountSeats("NY9d31f", '$', 2, 0);
    TestCountSeats("ny9d3", 'd', 1, 0); 
    TestCountSeats("ny1912d,ca421d", 'd', 0, 2333);
    TestCountSeats("NY8d81r, Ca4d51r, nv12r", 'R', 1, 0);
    TestCountSeats("NY9d3rCA8d4r", 'R', 1, 0);
    TestCountSeats("", 'd', 0, 0);
    TestCountSeats("ny4s", ' ', 2, 0);
    TestCountSeats("NY,", 'd', 1, 0);
}

int main()
{
    RunTestCases();
    cout << "--------------------------------------" << endl;
    RunCountSeats();
}