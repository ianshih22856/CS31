#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <bits/stdc++.h>
#include <experimental/iterator>
using namespace std;

bool CheckIntParam(int n)
{
    return n >= 0;
}

int appendToAll(string a[], int n, string value)
{
    if (!CheckIntParam(n))
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] + value;
    }
    return n;
}

int lookup(const string a[], int n, string target)
{
    if (!CheckIntParam(n))
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int positionOfMax(const string a[], int n)
{
    if (!CheckIntParam(n))
    {
        return -1;
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int rotateLeft(string a[], int n, int pos)
{
    if (!CheckIntParam(n) || !CheckIntParam(pos))
    {
        return -1;
    }
    if (pos >= n)
    {
        return -1;
    }
    string target = a[pos];
    for (int i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    a[n - 1] = target;

    return pos;
}

int countRuns(const string a[], int n)
{
    if (!CheckIntParam(n))
    {
        return -1;
    }

    int consecutiveCounter = 0;
    int i = 0;
    while (i < n)
    {
        if (a[i] == a[i + 1] && i + 1 < n)
        {
            int index = 2;
            while (a[i] == a[i + index] && i + index < n)
            {
                index++;
            }

            i = i + index;
            consecutiveCounter++;
        }
        else
        {
            consecutiveCounter++;
            i++;
        }
    }
    return consecutiveCounter;
}

int flip(string a[], int n)
{
    if (!CheckIntParam(n))
    {
        return -1;
    }

    for (int i = 0; i < n / 2; i++)
    {
        string temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
    return n;
}

int differ(const string a1[], int n1, const string a2[], int n2)
{
    if (!CheckIntParam(n1) || !CheckIntParam(n2))
    {
        return -1;
    }
    int index;
    if (n1 > n2)
    {
        index = n2;
    }
    else
    {
        index = n1;
    }

    for (int i = 0; i < index; i++)
    {
        if (a1[i] != a2[i])
        {
            return i;
        }
    }
    return index;
}

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    if (!CheckIntParam(n1) || !CheckIntParam(n2) || n1 == 0)
    {
        return -1;
    }
    else if (n2 == 0)
    {
        return n2;
    }
    else
    {
        int index = -1;
        for (int i = 0; i < n1; i++)
        {
            if (a2[0] == a1[i])
            {
                index = i;
                // a1 does not contain a2 and n2 contains more than 1 element
                if (i == n1 - 1 && n2 > 1)
                {
                    return -1;
                }
                else
                {
                    if (n2 == 1)
                    {
                        return index;
                    }
                    for (int j = 1; j < n2; j++)
                    {
                        if (a2[j] != a1[i + j])
                        {
                            index = -1;
                            break;
                        }
                        else
                        {
                            // if a2 has gone through every element
                            if (j == n2 - 1)
                            {
                                return index;
                            }
                        }
                    }
                }
            }
            // if loop reaches last element and no subsequence has been found
            else if (i == n1 - 1 && index == -1)
            {
                return -1;
            }
        }
        return index;
    }
}

int lookupAny(const string a1[], int n1, const string a2[], int n2)
{

    if (!CheckIntParam(n1) || !CheckIntParam(n2))
    {
        return -1;
    }
    if (n2 == 0)
    {
        return -1;
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a1[i] == a2[j])
            {
                return i;
            }
        }
    }
    return -1;
}

int split(string a[], int n, string splitter)
{
    if (!CheckIntParam(n))
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= splitter)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (a[j] >= a[j + 1])
                {
                    string temp;
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    temp.clear();
                }
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        if (a[k] >= splitter)
        {
            return k;
        }
    }
    return n;
}

int main()
{
    // string b[4] = {"rishi", "margaret", "liz", "theresa"};
    // assert(appendToAll(b, 4, "?") == 4 && b[0] == "rishi?" && b[3] == "theresa?");
    // string b1[4] = {"rishi", "margaret", "liz", "theresa"};
    // assert(appendToAll(b1, 0, "?") == 0 && b1[0] == "rishi" && b1[3] == "theresa");
    // assert(appendToAll(b1, -2, "?") == -1);
    // string b2[4] = {"rishi", "margaret", "liz", "theresa"};
    // assert(appendToAll(b1, 2, "?") == 2 && b1[0] == "rishi?" && b1[3] == "theresa");

    // string h[9] = {"rishi", "margaret", "gordon", "tony", "", "john", "liz","gordon", "joe"};

    // assert(lookup(h, 7, "john") == 5);
    // assert(lookup(h, 8, "gordon") == 2);
    // assert(lookup(h, 2, "gordon") == -1);
    // assert(lookup(h, 3, "rishi") == 0);
    // assert(lookup(h, 9, "joe") == 8);
    // assert(lookup(h, 0, "joe") == -1);
    // assert(lookup(h, -2, "joe") == -1);

    // string v[9] = {"", "margaret", "tony", "tony", "", "john", "liz", "gordon", "zeus"};

    // assert(positionOfMax(h, 7) == 3);
    // assert(positionOfMax(h, 0) == 0);
    // assert(positionOfMax(h, 3) == 0);
    // assert(positionOfMax(h, 3) == 0);

    // assert(positionOfMax(v, 1) == 0);
    // assert(positionOfMax(v, 9) == 8);
    // assert(positionOfMax(v, 5) == 2);
    // assert(positionOfMax(v, -2) == -1);

    // string g[4] = {"rishi", "margaret", "liz", "theresa"};
    // assert(rotateLeft(g, 4, 1) == 1 && g[1] == "liz" && g[3] == "margaret");
    // assert(rotateLeft(g, 3, 1) == 1 && g[1] == "liz" && g[3] == "theresa");
    // assert(rotateLeft(g, -2, 1) == -1);
    // assert(rotateLeft(g, 1, -1) == -1);
    // assert(rotateLeft(g, 4, 0) == 0 && g[0] == "margaret" && g[3] == "rishi");
    // assert(rotateLeft(g, 4, 3) == 3 && g[0] == "rishi" && g[3] == "theresa");
    // assert(rotateLeft(g, 0, 2) == -1 && g[0] == "rishi" && g[2] == "liz");
    // assert(rotateLeft(g, 3, 4) == -1);

    // string d[5] = {"margaret", "margaret", "margaret", "tony", "tony"};
    // assert(countRuns(d, 5) == 2);
    // assert(countRuns(d, 3) == 1);
    // assert(countRuns(d, -1) == -1);
    // assert(countRuns(d, 0) == 0);

    // string d1[9] = {"tony", "boris", "rishi", "rishi", "gordon", "gordon", "gordon", "rishi", "rishi"};
    // assert(countRuns(d1, 9) == 5);

    // string d2[5] = {"gordon", "gordon", "gordon", "gordon", "gordon"};
    // assert(countRuns(d2, 5) == 1);

    // string f[3] = {"liz", "gordon", "tony"};
    // assert(flip(f, 3) == 3 && f[0] == "tony" && f[2] == "liz");
    // assert(flip(f, 2) == 2 && f[0] == "gordon" && f[2] == "tony");
    // assert(flip(f, 0) == 0 && f[0] == "liz" && f[2] == "tony");
    // assert(flip(f, 1) == 1 && f[0] == "liz" && f[2] == "tony");
    // assert(flip(f, -3) == -1);

    // string h1[7] = {"rishi", "margaret", "gordon", "tony", "", "john", "liz"};
    // string g1[4] = {"rishi", "margaret", "liz", "theresa"};
    // string g2[6] = {"rishi", "margaret", "liz", "theresa", "hi", "test"};
    // string g3[4] = {"rishi", "margaret", "liz", "diff"};
    // string g4[3] = {"test", "4", "2"};
    // assert(differ(h1, 4, g1, 4) == 2);
    // assert(differ(h1, -3, g1, 4) == -1);
    // assert(differ(h1, 4, g1, -2) == -1);
    // assert(differ(g1, 4, g2, 6) == 4);
    // assert(differ(g1, 4, g3, 6) == 3);
    // assert(differ(g1, 4, g4, 6) == 0);
    // assert(differ(g1, 0, g4, 6) == 0);
    // assert(differ(g1, 4, g4, 0) == 0);

    // string h2[9] = {"rishi", "margaret", "gordon", "tony", "", "john", "liz", "gordon", "joe"};
    // string h3[8] = {"rishi", "margaret", "gordon", "tony",  "john", "liz", "margaret", "gordon"};
    // string e[4] = {"gordon", "tony", "", "john"};
    // string e1[4] = { "gordon", "tony", "", "joe"};
    // string e2[2] = {"margaret", "gordon"};
    // string e3[3] = {"margaret", "gordon", "joe"};
    // string e4[1] = {"rishi"};
    // string e5[1] = {"margaret"};
    // string e6[3] = {"gordon", "joe", ""};

    // assert(subsequence(h2, 7, e, 4) == 2);
    // assert(subsequence(h2, -7, e, 4) == -1);
    // assert(subsequence(h2, 7, e, -4) == -1);
    // assert(subsequence(h2, 0, e, 4) == -1);
    // assert(subsequence(h2, 7, e, 0) == 0);
    // assert(subsequence(h2, 7, e1, 4) == -1);
    // assert(subsequence(h3, 8, e2, 2) == 1);
    // assert(subsequence(h3, 7, e3, 3) == -1);
    // assert(subsequence(h3, 8, e4, 1) == 0);
    // assert(subsequence(h3, 8, e5, 1) == 1);
    // assert(subsequence(h2, 9, e6, 3) == -1);
    // assert(subsequence(h2, 9, e6, 2) == 7);

    // string l[7] = {"rishi", "margaret", "gordon", "tony", "", "john", "liz"};
    // string m[3] = {"liz", "gordon", "tony"};
    // string m1[3] = {"l1iz", "gordo1n", "tony1"};
    // string m2[1] = {"rishi"};
    // assert(lookupAny(l, 7, m, 3) == 2);
    // assert(lookupAny(l, -1, m, 3) == -1);
    // assert(lookupAny(l, 7, m, -3) == -1);
    // assert(lookupAny(l, 0, m, 3) == -1);
    // assert(lookupAny(l, 7, m, 0) == -1);
    // assert(lookupAny(l, 7, m1, 3) == -1);
    // assert(lookupAny(l, 7, m, 1) == 6);
    // assert(lookupAny(l, 7, m2, 1) == 0);

    // string n[7] = { "rishi", "margaret", "gordon", "tony", "", "john", "liz" };
    // string o[7] = {"john", "margaret", "liz", "tony", "", "john", "liz"};
    // assert(split(n, 7, "liz") == 3);
    // assert(split(n, -1, "liz") == -1);
    // assert(split(n, 7, "no") == 5);
    // assert(split(n, 0, "no") == 0);
    // assert(split(o, 7, "liz") == 3);
    // assert(split(o, 6, "john") == 1);
    // assert(split(o, 7, "") == 0);
    // assert(split(o, 7, "tony") == 6);

    // cout << "All tests succeeded" << endl;
}