#include <iostream>
using namespace std;

// Write a function named removeS that accepts one character pointer as a parameter and returns no value.
// The parameter is a C string.This function must remove all of the upper and lower case 's' letters from the string.
// The resulting string must be a valid C string.
// Your function must declare no more than one local variable in addition to the parameter;
// that additional variable must be of a pointer type.
// Your function must not use any square brackets and must not use any of the<cstring> functions such as strlen, strcpy, etc.

int main()
{
    int arr[3] = {5, 10, 15};
    int *ptr = arr;

    *ptr = 10;       // set arr[0] to 10
    *(ptr + 1) = 20;  // set arr[1] to 20
    ptr += 2;
    ptr[0] = 30; // set arr[2] to 30

    while (ptr >= arr)
    {
        cout << *ptr << endl; // print values
        ptr--;
    }
}