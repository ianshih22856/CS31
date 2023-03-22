const char WORDFILENAME[] = "words.txt";

#define _CRT_SECURE_NO_DEPRECATE

#include "utilities.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <random>
#include <assert.h>
#include <stdio.h>
#include <utility>
#include <iomanip>
using namespace std;

// Check if value is in array
bool CheckValueInArray(int value, int valueArray[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        if (value == valueArray[i])
        {
            return true;
        }
    }
    return false;
}

// Count silvers and golds for word
void SilversAndGolds(char probeWord[], char hiddenWord[], int probeWordLength, int hiddenWordLength, int &goldCounter, int &silverCounter)
{
    goldCounter = 0;
    silverCounter = 0;
    //array to remember positions of gold characters
    int goldPositions[MAXWORDLEN + 1];
    int minLength;

    if (probeWordLength < hiddenWordLength)
    {
        minLength = probeWordLength;
    }
    else
    {
        minLength = hiddenWordLength;
    }
    //check for gold characters
    for (int i = 0; i < minLength; i++)
    {
        if (probeWord[i] == hiddenWord[i] && probeWord[i] != '\0')
        {
            goldPositions[goldCounter] = i;
            goldCounter++;
        }
    }

    // array of silver character positions
    int silverProbePositions[MAXWORDLEN + 1];
    // check for silver characters
    for (int i = 0; i < hiddenWordLength; i++)
    {
        if (CheckValueInArray(i, goldPositions, goldCounter))
        {
            continue;
        }
        for (int j = 0; j < probeWordLength; j++)
        {
            //if character is in gold position array
            if (CheckValueInArray(j, goldPositions, goldCounter))
            {
                continue;
            }
            //if character is already classified as silver
            if (CheckValueInArray(j, silverProbePositions, silverCounter))
            {
                continue;
            }
            //add into silver positions array
            if (hiddenWord[i] == probeWord[j])
            {
                // silverHiddenPositions[silverCounter] = i;
                silverProbePositions[silverCounter] = j;
                silverCounter++;
                break;
            }
        }
    }
}

// Checks user input and counts silvers and golds
int GameRoutine(char probeWord[], char hiddenWord[], const char words[][MAXWORDLEN + 1], int hiddenWordLength, int numWords)
{
    int probeWordLength = strlen(probeWord);
    if (probeWordLength > MAXWORDLEN || probeWordLength < MINWORDLEN)
    {
        cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
        return -1;
    }
    for (int i = 0; i < probeWordLength; i++)
    {
        // if invalid character or not lowercase
        if (!isalpha(probeWord[i]) || !islower(probeWord[i]))
        {
            cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
            return -1;
        }
    }

    bool wordFound = false;
    for (int i = 0; i < numWords; i++)
    {
        //if probe word is found in word list
        if (strcmp(words[i], probeWord) == 0)
        {
            wordFound = true;
            break;
        }
    }
    if (wordFound == false)
    {
        cout << "I don't know that word." << endl;
        return -1;
    }

    int goldCounter;
    int silverCounter;
    SilversAndGolds(probeWord, hiddenWord, probeWordLength, hiddenWordLength, goldCounter, silverCounter);
    if (strcmp(probeWord, hiddenWord) != 0)
    { 
        cout << "Golds: " << goldCounter << ", Silvers: " << silverCounter << endl;
    }
    return 0;
}

int playOneRound(const char words[][MAXWORDLEN + 1], int nWords, int wordnum)
{
    string tempString = words[wordnum];
    char hiddenWord[MAXWORDLEN + 1] = {};
    strcpy(hiddenWord, tempString.c_str());
    int hiddenWordLength = strlen(hiddenWord);

    char probeWord[1000] = {""};
    int scoreCounter = 0;

    if (nWords < 1 || wordnum < 0 || wordnum > nWords)
    {
        return -1;
    }
    while (strcmp(probeWord, hiddenWord) != 0)
    {

        cout << "Probe word: ";

        cin.getline(probeWord, '\n');
        // if probe word is valid input
        if (GameRoutine(probeWord, hiddenWord, words, hiddenWordLength, nWords) == 0)
        {
            scoreCounter++;
        }
    }
    return scoreCounter;
}

int main()
{
    char wordList[9000][MAXWORDLEN + 1];
    int numWords = getWords(wordList, 10000, WORDFILENAME);

    if (numWords < 1)
    {
        cout << "No words were loaded, so I can't play the game." << endl;
        return -1;
    }
    int userRounds;
    cout << "How many rounds do you want to play? ";
    cin >> userRounds;
    if (userRounds < 0)
    {
        cout << "The number of rounds must be positive." << endl;
        return -1;
    }
    cin.ignore(10000, '\n');
    cout << endl;

    int minimumScore;
    int maximumScore;
    int totalScore = 0;
    double averageScore;

    int currentRound = 1;
    while (currentRound <= userRounds)
    {
        int chosenNumber = randInt(0, numWords - 1);
        cout << "Round " << currentRound << endl;

        string tempString = wordList[chosenNumber];
        char hiddenWord[MAXWORDLEN + 1] = {};
        strcpy(hiddenWord, tempString.c_str());
        int hiddenWordLength = strlen(hiddenWord);

        // cout << "HIDDEN WORD: " << hiddenWord << endl;
        cout << "The hidden word is " << hiddenWordLength << " letters long." << endl;

        int roundScore = playOneRound(wordList, numWords, chosenNumber);
        if (roundScore == 1)
        {
            cout << "You got it in " << roundScore << " try." << endl;
        }
        // if parameter for playOneRound is invalid
        else if (roundScore < 0)
        {
            break;
        }
        else 
        {
            cout << "You got it in " << roundScore << " tries." << endl;
        }

        if (roundScore > maximumScore || currentRound == 1)
        {
            maximumScore = roundScore;
        }
        if (roundScore < minimumScore || currentRound == 1)
        {
            minimumScore = roundScore;
        }
        totalScore = totalScore + roundScore;
        averageScore = (double)totalScore / currentRound;

        cout << fixed;
        cout << setprecision(2);
        cout << "Average: " << averageScore << ", minimum: " << minimumScore << ", maximum: " << maximumScore << endl;
        cout << endl;
        currentRound++;
    }
}