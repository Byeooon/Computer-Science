#include <iostream>
using namespace std;
void printDiamond(int size)
{
    int x,y,radius = size /2;

    for(y = radius; y >= -radius; y--)
    {
        int abs_y = abs(y);
        for(x = -radius; x <= 0; x++)
        {
            if(x >= abs_y - radius)
                cout << "+";
            else
                cout << "*";
        }

        for(; x <= radius; x++)
        {
            if(x <= -abs_y + radius)
                cout << "+";
            else
                cout << "*";
        }
        cout << endl;
    }

}

int main()
{
    int size;
    cin >> size;
    printDiamond(size);
    return 0;
}