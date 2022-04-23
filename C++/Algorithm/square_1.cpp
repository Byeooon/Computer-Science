#include <iostream>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        int size;
        cin >> size;
        int x, y, radius = size / 2; 

        for(y = radius; y >= -radius; y --) //위에서 부터 훑는다.
        {
            int abs_y = abs(y);
            for(x = -radius; x<=0; x++) //x가 0이하일 때 까지
            {
                if(x < -abs_y) //절댓값 그래프 이용
                    if(x%2 == 0)    cout << 0; //x축 방향으로 선처리
                    else            cout << 1;
                else
                    if(y%2 == 0)    cout << 0; //y축 방향으로 후처리
                    else            cout << 1;
            }

            for( ; x <= radius; x++) 
            {
                if(x > abs_y)
                    if(x%2 == 0)    cout << 0;
                    else            cout << 1;
                else
                    if(y%2 == 0)    cout << 0;
                    else            cout << 1;
            }
            cout << endl;
        }
    }
    return 0;
} // y=x그래프와 좌표축 개념을 이용한 알고리즘