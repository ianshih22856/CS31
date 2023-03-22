#include <iostream>

using namespace std;

void helloworld(int x)
{

    cout << "hello world!" << x << endl;
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        helloworld(i);
    }
}