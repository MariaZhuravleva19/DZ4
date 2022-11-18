#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Convert_start(int end_base, int n) 
{
    string alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res;
    while (n > 0)
    {
        res = alpha[n % end_base] + res;
        n = n / end_base;
    }
    return res;
}

int main()
{
    string date,D,M,Y,answer;
    int i = 0;

    int day = 0;
    int month = 0;
    int year = 0;

    ifstream file1;
    file1.open("790in.txt");
    ofstream file2;
    file2.open("790out.txt");

    file1 >> date;


    while (isdigit(date[i]))
    {
        D += date[i];
        i++;
    }
    i++;
    while (isdigit(date[i]))
    {
        M += date[i];
        i++;
    }
    i++;
    while (isdigit(date[i]))
    {
        Y += date[i];
        i++;
    }

    day = stoi(D); 
    month = stoi(M);
    year = stoi(Y);
    D = Convert_start(day + 1, day); 
    M = Convert_start(day + 1, month);
    Y = Convert_start(day + 1, year);

    answer = D + "/" + M + "/" + Y;
    file2 << answer;

    file1.close();
    file2.close();
}