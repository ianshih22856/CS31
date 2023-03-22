#include <iostream>
using namespace std;

// void swap(int *ptrX, int *ptrY)
// {
//     int tempSwap = *ptrX;
//     *ptrY = *ptrX;
//     *ptrY = tempSwap;
// }

// int main()
// {
//     int x;
//     cout << "enter value for x: " << endl;
//     cin >> x;
//     int y;
//     cout << "enter value for y: " << endl;
//     cin >> y;

//     swap(x, y);
//     cout << "x = " << x << ", y = " << y << endl;
//     return 0;
// }

void swap (int &one, int &two)
{
    int tempSwap = one;
    one = two;
    two = tempSwap;
}

int main ()
{
    int x;
    cout << "enter value for x: " << endl;
    cin >> x;
    int y;
    cout << "enter value for y: " << endl;
    cin >> y;
    
    swap(x,y);
    cout << "x = " << x << ", y = " << y << endl;
    return 0;
}