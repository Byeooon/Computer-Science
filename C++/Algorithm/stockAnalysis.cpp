#include <iostream>
using namespace std;

int main()
{
    int yesterday, today, tomorrow, days, testcase;
    

    cin >> testcase;

    while(testcase--)
    {
        int high_count = 0 ; //local
        cin >> days >> tomorrow;
        yesterday = tomorrow;
        cin >> tomorrow;
        today = tomorrow; //2일치

        for(int j = 2; j < days; j++)
        {
            cin >> tomorrow;
            if(today == tomorrow)
                continue;
            if((today > yesterday) && (today > tomorrow))
            {
                high_count++;
            }
            yesterday = today;
            today = tomorrow;
        }
        cout << high_count << endl;
    }
    
    return 0;
}