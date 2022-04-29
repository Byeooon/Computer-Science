#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;

    while(testcase--)
    {
        int px1,py1,px2,py2; //사각형 1
        int qx1,qy1,qx2,qy2; //사각형 2
        cin >> px1 >> py1 >> px2 >> py2;
        cin >> qx1 >> qy1 >> qx2 >> qy2;

        /* 
                px2 py2              qx2 qy2
        
        px1 py1             qx1 qy1
        */
    
        if(px2 < qx1 || qx2 < px1 || qy2 < py1 || qy1 > py2) //겹치지 않는 경우
        {
            cout << abs(px2 - px1)*abs(py2-py1) + abs(qx2-qx1)*abs(qy2-qy1) << " "; //면적
            cout << 2*abs(px2 - px1) + 2*abs(py2-py1) + 2*abs(qx2-qx1) + 2*abs(qy2-qy1); //둘레
        }
        else //겹치는 경우(포함O)
        {
            cout << (abs(px2 - px1)*abs(py2-py1) + abs(qx2-qx1)*abs(qy2-qy1)) - ((min(px2,qx2) 
            - max(px1,qx1)) * (min(py2,qy2) - max(py1,qy1))) << " "; //면적
            cout << 2*abs(px2 - px1) + 2*abs(py2-py1) + 2*abs(qx2-qx1) + 2*abs(qy2-qy1) 
            - (2*(min(qx2,px2) - max(px1,qx1)) + 2*(min(py2,qy2) - max(py1,qy1))); //둘레
        }
        cout << endl;
    }
    return 0;
}