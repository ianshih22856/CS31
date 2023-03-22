#include <iostream>
#include <string>
using namespace std;

// struct Test 
// {
//     int x {};
//     int y {};
// };
int main()
{
    int x = 490;
    string test = to_string(x);
    string name = "hi " + test;
    cout << name << endl;
}