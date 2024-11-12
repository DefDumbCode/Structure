#include <iostream>
#include <string>
#include<windows.h>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include <sstream>
#include "Sidorov.h"
using namespace std;


int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream fout;
    ifstream fin;

    int a = Stroka("DATA.txt");
    int b = Probeli("DATA.txt");
    cout << "Stroka = " << a
        << " Probeli = " << b << endl;
    int c = a + b;
    fin.open("DATA.txt");

    vector<string> student;
    for (size_t i = 0; i < c; i++)
    {
        string s1;
        fin >> s1;
        student.push_back(s1);
    }
    fin.close();


    // алгоритм Филина Дмитрия Антоновича и Сидорова Дмитрия Александровича
    vector <int> vozr;
    int Num = 10;
    for (int i = Num - 6; i < student.size(); i = i += Num)
    {
        if (student[i] != "0")
        {
            vozr.push_back(stoi(student[i].c_str()));
        }
    }

    vector<int> Array;
    vozr.swap(Array);
    vector<int> M;
    for (size_t i = 0; i < Array.size(); i++)
    {
        cout << Array[i] << " ";
    }
    cout << endl;


    fin.open("DATA.txt");
    vector<int> predm;
    int predm_s = 0;
    vector<int> Mark;
    for (int j = 1; j < 5; j++)
    {
        for (int i = Num - 5 + j; i < student.size(); i = i += Num)
        {
            predm_s++;
            if (student[i] != "0")
            {
                predm.push_back(stoi(student[i].c_str()));
            }
        }
        vector<int> Marks;
        predm.swap(Marks);
        for (size_t i = 0; i < Marks.size(); i++)
        {
            Mark.push_back(Marks[i]);
        }
    }


    vector<float> SRED;
    vector<float> Summa_t;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Summa_t.push_back(Mark[i + j * a]);
        }

        float Sum = 0;
        for (size_t su = 0; su < Summa_t.size(); su++)
        {
            Sum += Summa_t[su];
        }
        SRED.push_back(Sum / Summa_t.size());
        Summa_t.erase(Summa_t.begin(), Summa_t.end());
    }


    for (size_t i = 0; i < SRED.size(); i++)
    {
        cout << SRED[i] << " | ";
    }


}