#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{

    {

        string str;
        ifstream file1;
        ofstream file2;
        file1.open("600.2in.txt");
        file2.open("600out.txt");
        file1 >> str;
        int c = stoi(str);


        for (int i = 0; i < c; i++)
        {
            double count0 = 0, count1 = 0, count2 = 0;
            file1 >> str;
            for (int j = 0; j < str.size(); j++)
            {

                if (str[j] == '0')
                {
                    count0 += 1;
                }
                if (str[j] == '1')
                {
                    count1 += 1;
                }
                if (str[j] == '2')
                {
                    count2 += 1;
                }
            }
            bool b1 = false, b2 = false, b3 = false;

            if (count0 == count1 && count1 == count2)
            {
                for (int i = 0; i < count0; i++)
                {
                    if (str[i] != '0')
                    {
                        b1 == true;
                        break;
                    }
                }
                for (int i = count0; i < count0 + count1; i++)
                {
                    if (str[i] != '1')
                    {
                        b2 == true;
                        break;
                    }
                }
                for (int i = count0 + count1; i < count0 + count1 + count2; i++)
                {
                    if (str[i] != '2')
                    {
                        b3 == true;
                        break;
                    }
                }
                if (b1 == false && b2 == false && b3 == false)
                {
                    file2 << "YES" << endl;
                }
                else
                {
                    file2 << "NO" << endl;
                }

            }
            else
            {
                file2 << "NO" << endl;
            }
        }
        file1.close();
        file2.close();


    }
}