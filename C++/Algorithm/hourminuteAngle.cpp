#include <iostream>
using namespace std;
int angleClock(int h, int m);
float angleh;
float anglem;
int result;

int main(void)
{
    int testcase;
    int h, m;

    cin >> testcase;
    for(int i=0; i<testcase; i++)
    {
        cin >> h >> m;
        angleClock( h, m );

    }
    return 0;
}

int angleClock(int h, int m)
{
    angleh = m * 0.5 + h * 30.0; //시침 1분 -> 0.5° 1시간 -> 30°
    anglem = m * 6.0;            //분침 1분 -> 6.0°

    if (abs((angleh-anglem)) > 180)
    {
        result = 360 - abs(angleh - anglem);
        cout << result << endl;
    }
    else
    {
        result = abs(angleh - anglem);
        cout << result << endl;
    }
    return 0;
}