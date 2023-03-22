#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

vector<string> cardList{"placeholder"}; // list of cards with placeholder at index 0
int playerAceElevenCounter = 0;
int dealerAceElevenCounter = 0;
string PlayerDecision = "h";

void CreateCardList()
// function for creating a list of cards
{
    vector<int> numberList{2, 3, 4, 5, 6, 7, 8, 9, 10};               // list of numbers in cards
    vector<string> JQKAList{"Jack", "Queen", "King", "Ace"};          // list of face cards
    vector<string> CDHSList{"Clubs", "Diamonds", "Hearts", "Spades"}; // list of suits

    for (int i = 0; i < numberList.size(); i++) // for loop for naming number cards
    {
        for (int j = 0; j < CDHSList.size(); j++)
        {
            cardList.push_back(to_string(numberList.at(i)) + " of " + CDHSList.at(j));
        }
    }

    for (int i = 0; i < JQKAList.size(); i++) // for loop for naming face cards
    {
        for (int j = 0; j < CDHSList.size(); j++)
        {
            cardList.push_back((JQKAList.at(i)) + " of " + CDHSList.at(j));
        }
    }

    /*for (int i = 1; i < cardList.size(); i++) // print card list test
    {
        cout << cardList.at(i);
    }*/
}

int RandInt(int lowest, int highest) // function for producing random number
{
    static random_device rd;
    static default_random_engine generator(rd());
    uniform_int_distribution<> distro(lowest, highest);
    return distro(generator);
}

string CardSelection() // function for choosing random card
{
    string chosenCard = cardList.at(RandInt(1, 52));
    return chosenCard;
}

int AssignValue(string selectedCard) // function for assigning blackjack value to cards
{
    int cardValue;
    vector<string>::iterator it = find(cardList.begin(), cardList.end(), selectedCard);
    int place = distance(cardList.begin(), it);
    // cout << place << endl;
    if (place < 37)
    {
        cardValue = ceil((place - 1) / 4 + 2);
    }
    else if (place > 48)
    {
        cardValue = 11;
    }
    else
    {
        cardValue = 10;
    }
    return cardValue;
}

vector<int> DetermineAceValue(int currentHandValue, int aceElevenCounter)
{
    if (aceElevenCounter < 1)
    {
        currentHandValue = currentHandValue;
    }
    else if (aceElevenCounter > 0 && currentHandValue > 21)
    {
        currentHandValue = currentHandValue - 10;
        aceElevenCounter--;
    }
    vector<int> handEleven{currentHandValue, aceElevenCounter};
    return handEleven;
}

vector<int> Bust(int currentHandValue, int aceElevenCounter)
{
    if (aceElevenCounter > 0)
    {
        currentHandValue = currentHandValue - 10;
        aceElevenCounter--;
    }
    vector<int> handEleven{currentHandValue, aceElevenCounter};
    return handEleven;
}

int DealerProtocol(int dealerFirstTwo)
{
    int dealerHandValue;
    dealerHandValue = dealerFirstTwo;
    while (dealerHandValue < 17)
    {
        string newDealerCard = CardSelection();
        cout << "The dealer drew " << newDealerCard << "." << endl;
        dealerHandValue = dealerHandValue + AssignValue(newDealerCard);

        if (AssignValue(newDealerCard) == 11)
        {
            dealerAceElevenCounter++;

            vector<int> tempDealer = DetermineAceValue(dealerHandValue, dealerAceElevenCounter);
            dealerHandValue = tempDealer.at(0);
            dealerAceElevenCounter = tempDealer.at(1);
        }
        if (dealerHandValue > 21 && dealerAceElevenCounter > 0)
        {
            vector<int> tempBustDealer = Bust(dealerHandValue, dealerAceElevenCounter);

            dealerHandValue = tempBustDealer.at(0);
            dealerAceElevenCounter = tempBustDealer.at(1);
        }

        if (dealerHandValue > 17)
        {
            break;
        }
    }
    return dealerHandValue;
}

int PlayerProtocol(int playerFirstTwo)
{
    int playerHandValue;
    playerHandValue = playerFirstTwo;
    while (playerHandValue < 21)
    {
        cout << "Do you want to hit or stand? (Type 'h' to hit, 's' to stand)" << endl;
        cin >> PlayerDecision;
        if (PlayerDecision == "h")
        {
            string newPlayerCard = CardSelection();
            cout << "Your card is " << newPlayerCard << "." << endl;
            playerHandValue = playerHandValue + AssignValue(newPlayerCard);

            if (AssignValue(newPlayerCard) == 11)
            {
                playerAceElevenCounter++;

                vector<int> tempPlayer = DetermineAceValue(playerHandValue, playerAceElevenCounter);
                playerHandValue = tempPlayer.at(0);
                playerAceElevenCounter = tempPlayer.at(1);
            }
            if (playerHandValue > 21 && playerAceElevenCounter > 0)
            {
                vector<int> tempBustPlayer = Bust(playerHandValue, playerAceElevenCounter);

                playerHandValue = tempBustPlayer.at(0);
                playerAceElevenCounter = tempBustPlayer.at(1);
            }
        }
        if (PlayerDecision == "s" || (playerHandValue >= 21 && playerAceElevenCounter < 1) || playerHandValue == 21)
        {
            break;
        }
    }
    return playerHandValue;
}

void Winner(int dealerFinalValue, int playerFinalValue)
{
    if (playerFinalValue > 21)
    {
        cout << "You lose..." << endl;
    }
    else if (dealerFinalValue == playerFinalValue)
    {
        cout << "You tied." << endl;
    }
    else if (dealerFinalValue > 21 && playerFinalValue <= 21)
    {
        cout << "You win!" << endl;
    }
    else if (dealerFinalValue > playerFinalValue)
    {
        cout << "You lose..." << endl;
    }
}

int main()
{
    CreateCardList();

    string playerFirstCard = CardSelection();

    /*int p1card;
    cout << "enter player first card: " << p1card << endl;
    cin >> p1card;
    string playerFirstCard = cardList.at(p1card);
    cout << playerFirstCard << endl;*/

    cout << "Your first card is " << playerFirstCard << ".\n";

    string dealerFirstCard = CardSelection();

    /*int d1card;
    cout << "enter dealer first card: " << d1card << endl;
    cin >> d1card;

    string dealerFirstCard = cardList.at(d1card);
    cout << dealerFirstCard << endl;*/

    cout << "The dealer's first card is " << dealerFirstCard << ".\n";

    string playerSecondCard = CardSelection();

    /*int p2card;
    cout << "enter player second card: " << p2card << endl;
    cin >> p2card;
    string playerSecondCard = cardList.at(p2card);
    cout << playerSecondCard << endl;*/

    cout << "Your second card is " << playerSecondCard << ".\n";

    string dealerSecondCard = CardSelection();

    /*int d2card;
    cout << "enter dealer second card: " << d2card << endl;
    cin >> d2card;

    string dealerSecondCard = cardList.at(d2card);
    cout << dealerSecondCard << endl;*/

    int dealerHandValue = AssignValue(dealerFirstCard) + AssignValue(dealerSecondCard);
    int playerHandValue = AssignValue(playerFirstCard) + AssignValue(playerSecondCard);

    if (AssignValue(dealerFirstCard) == 11)
    {
        dealerAceElevenCounter++;
        vector<int> tempD1 = DetermineAceValue(dealerHandValue, dealerAceElevenCounter);
        dealerHandValue = tempD1.at(0);
        dealerAceElevenCounter = tempD1.at(1);
    }
    if (AssignValue(dealerSecondCard) == 11)
    {
        dealerAceElevenCounter++;
        vector<int> tempD2 = DetermineAceValue(dealerHandValue, dealerAceElevenCounter);
        dealerHandValue = tempD2.at(0);
        dealerAceElevenCounter = tempD2.at(1);
    }
    if (AssignValue(playerFirstCard) == 11)
    {
        playerAceElevenCounter++;
        vector<int> tempP1 = DetermineAceValue(playerHandValue, playerAceElevenCounter);
        playerHandValue = tempP1.at(0);
        playerAceElevenCounter = tempP1.at(1);
    }
    if (AssignValue(playerSecondCard) == 11)
    {
        playerAceElevenCounter++;
        vector<int> tempP2 = DetermineAceValue(playerHandValue, playerAceElevenCounter);
        playerHandValue = tempP2.at(0);
        playerAceElevenCounter = tempP2.at(1);
    }

    if (playerHandValue == 21 && dealerHandValue != 21)
    {
        cout << "The dealer's second card was " << dealerSecondCard << ".\n";
        cout << "You win!" << endl;
    }
    else if (playerHandValue == 21 && dealerHandValue == 21)
    {
        cout << "The dealer's second card was " << dealerSecondCard << ".\n";
        cout << "You tied." << endl;
    }
    int finalDealerValue;
    int finalPlayerValue;

    if (playerHandValue < 21)
    {
        finalPlayerValue = PlayerProtocol(playerHandValue);
    }

    if (dealerHandValue < 21)
    {   
        finalDealerValue = DealerProtocol(dealerHandValue);
        cout << "The dealer's second card was " << dealerSecondCard << ".\n";
    }

    Winner(finalDealerValue, finalPlayerValue);
}
