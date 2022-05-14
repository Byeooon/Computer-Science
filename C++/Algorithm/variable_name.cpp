#include<iostream>
#include<string>
using namespace std;
 
/*
ASCII TABLE
65 - 90 : A - Z
97 - 122 : a - z
0 - 9 : 0 - 9
95 : _(underLine)
*/

int isNum(string tmp, int index)
{
    if(tmp[index] >= '0' && tmp[index] <= '9')
        return 1;
    else
        return 0;
}
int isAlpha(string tmp, int index)
{
    if((tmp[index] > 64 && tmp[index] < 91) || (tmp[index] > 96 && tmp[index] < 123))
        return 1;
    else
        return 0;
}
int isUnder(string tmp, int index)
{
    if(tmp[index] == 95)
        return 1;
    else
        return 0;
}

int main()
{
    int testcase;
    int varlen;
    int output;
    cin >> testcase;
    while (testcase--)
    {
        string var;
        cin >> var;
        varlen = var.length();
        if((isNum(var,0)) || ((isUnder(var,0) != 1) && (isAlpha(var,0) != 1)))
            cout << 0 << "\n";
        else
        {
            for(int i = 1; i < varlen; i++)
            {
                cout << var[i] << endl;
                if((isNum(var,i)) || (isUnder(var,i)) || (isAlpha(var,i)))
                    output = 1;
                else
                {
                    output = 0;
                    break;
                }
    
                cout << "output : " <<output << "\n";
            }
            cout << "output : " << output << "\n";
        } 
    }
    return 0;
}