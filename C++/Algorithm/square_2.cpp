#include <iostream>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i++)
    {
        int size;
        cin >> size; //정사각형 크기
        int x, y, radius = size / 2;

        for(y = radius; y >= -radius; y--)
        {
            for(x = -radius; x <= radius; x++)
            {
                if(abs(y) == radius)
                    if(abs(x) == radius || x == 0)   cout << "+";
                    else                             cout << "-";
                else if(y == 0)
                    if(abs(x) == radius)             cout << "+";
                    else if (x == 0)                 cout << "*";
                    else                             cout << "-";
                else
                    if(abs(x) == radius || x == 0)   cout << "|";
                    else if(y == x)                  cout << "/";
                    else if(y == -x)                 cout << "\\";
                    else                             cout << ".";
            }
            cout << endl;
        }
    }
    return 0;
}