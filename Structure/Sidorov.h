#pragma once
#include <iostream>
#include <string>
#include<windows.h>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include <sstream>

using namespace std;

int Stroka(string s)
{
    int NumL = 0;
    string stroka;
    ifstream fin;
    fin.open(s);
    while (getline(fin, stroka))
    {
        if (!stroka.empty())
        {
            NumL++;
        }
    }
    return NumL;
}

int Probeli(string s)
{
    int NumL = 0;
    ifstream fin;
    fin.open(s);
    while (!fin.eof())
    {
        char  ch; fin.get(ch);
        if (ch == ' ') { NumL++; }
    }
    return NumL;
}

int Sum(int* arr, int n)
{
    int Sum = 0;
    for (size_t i = 0; i <= n - 1; i++)
    {
        Sum += arr[i];
    }
    return Sum;
}