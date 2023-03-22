#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//calculate tax based on income, occupation, and number of children
double CalculateTax (double income, string occupation, int numChildren)
{
    double taxAmount = 0.00;   
    double initialIncome = income;

//for first taxable income of 55000
    if(income <= 55000) 
    {
        taxAmount = .04 * income;
    }
    else
    {
        taxAmount = .04 * 55000;
    }
    income = income - 55000;

//for second taxable income of 125000
    if (income > 0)
    {
        double taxPercent;
        if(occupation == "nurse" || occupation == "teacher")
        {
            taxPercent = .05;
        }
        else 
        {
            taxPercent = .07;
        }
        if (income <= 70000)
        {
            taxAmount = taxAmount + taxPercent * income;
        }
        else
        {
            taxAmount = taxAmount + taxPercent * 70000;
        }
        income -= 70000;
    }

//for third taxable income of > 125000
    if (income > 0)
    {
        taxAmount = taxAmount + income * .093;
    }

// for deducting tax based on number of children
    if (initialIncome < 125000)
    {
        taxAmount = taxAmount - 200 * numChildren;
    }

    if (taxAmount < 0)
    {
        taxAmount = 0;
    }
    
    return taxAmount;
}
int main()
{
    string name;
    double income;
    string occupation;
    int numChildren;
    
    cout << "Name: ";
    getline(cin, name);

    if (name == "")
    {
        cout << "---" << endl;
        cout << "You must enter a name";
        return 1;
    }

    
    cout << "Taxable income: ";
    cin >> income;
    cin.ignore(10000, '\n');
    
    if (income < 0)
    {
        cout << "---" << endl;
        cout << "The taxable income must not be negative";
        return 1;
    }

    cout << "Occupation: ";
    getline(cin, occupation);

    if (occupation == "")
    {
        cout << "---" << endl;
        cout << "You must enter an occupation";
        return 1;
    }

    cout << "Number of children: ";
    cin >> numChildren;

    if (numChildren < 0)
    {
        cout << "---" << endl;
        cout << "The number of children must not be negative";
        return 1;
    }
    cout << "---" << endl;

    //set decimals to 2 places
    cout << fixed;
    cout << setprecision(2);
    double taxAmount = CalculateTax(income, occupation, numChildren);
    cout << name << " would pay $" << taxAmount << endl;
    
}

