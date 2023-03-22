#include <iostream>
#include <string>

using namespace std;

const int MAXSODA = 100;
class Soda
{
public:
    Soda();
    void setName(string name);
    string getName() const;

private:
    string name;
};
Soda::Soda()
{
    // TODO: set name = "NA" to signal Not Available (5 points)
    name = "NA";
}
void Soda::setName(string name)
{
    this -> name = name;
    // TODO: set Soda’s name as the name passed in. (5 points)
}
string Soda::getName() const
{
    return name;
    // TODO: return Soda’s name. (5 points)
}

class VM
{
public:
    VM(int n);
    ~VM();
    void restock(string name, int quantity);
    Soda *getSoda(string name);
    bool buySoda(string name);

private:
    Soda *inventory[MAXSODA];
    int quantity[MAXSODA];
    int numSoda;
};
VM::VM(int n)
{
    numSoda = n;
    for (int i = 0; i < numSoda; i++)
        inventory[i] = new Soda();
}
VM::~VM()
{
    for (int i = 0; i < numSoda; i++)
        delete inventory[i];
    // TODO: (10 points)
    // Delete the storage pointed to by Soda pointers in inventory array
}
void VM::restock(string name, int quantity)
{
    for (int i = 0; i < numSoda; i++)
        if (inventory[i]->getName() == "NA")
        {
            inventory[i] -> setName(name);
            this -> quantity[i] = quantity;
            break;
            // TODO: (10 points)
            // 1. If we found a Soda that has the name "NA", we set
            // this Soda to have the name we passed into this function.
            // 2. Set the quantity for that Soda.
            // 3. Break out of this loop.
        }
}
Soda *VM::getSoda(string name)
{
    for (int i = 0; i < numSoda; i++)
        if (inventory[i]->getName() == name)
            return inventory[i];
    return nullptr;
    // TODO: (10 points)
    // Search all Soda Objects to see if there’s a matching Soda by name
    // If there is a matching soda by name, return that Soda object.
    // Return nullptr if there’s no matching Soda by name.
}
bool VM::buySoda(string name)
{
    for (int i = 0; i < numSoda; i++)
    {
        if (inventory[i]->getName() == name)
        {
            if (quantity[i] > 0)
            {
                quantity[i]--;
                return true;
            }
            return false;
        }
    }
    return false;
    // TODO: (15 points)
    // 1. Search through all Soda objects to find matching Soda by name
    // If there is a matching soda by name, and if the quantity is > 0.
    // then we decrease quantity for the Soda by 1 and return true
    // If there is a matching soda by name, but the quantity is <= 0
    // then we return false.
    // If there is no matching soda name, return false.
}

int main()
{
    int arr[12] = {1, 3, 5, 0, 7, 2, 0, 4, 4, 0, 8, 8};
    int count = 0;
    for (int i = 0; i < 11; i++)
    {
        if (arr[i] = arr[i + 1])
            count++;
        else
            count--;
    }
    cout << count << endl;
}