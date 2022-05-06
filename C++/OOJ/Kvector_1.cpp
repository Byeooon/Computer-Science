#include <iostream>
using namespace std;

class Kvector
{
int *m;
int len;
public:
    Kvector(int sz = 0, int value = 0);
    Kvector(Kvector& v);
    ~Kvector()
    {
        cout << this << " : ~Kvector() \n";
        delete[] m;
    }
    void print()
    {
        for(int i = 0; i<len; i++) cout << m[i] << " ";
        cout << endl;
    }
    void clear()
    {
        delete[] m;
        m = nullptr;
        len = 0;
    }
    int size(){return len;}
};

Kvector::Kvector(int sz, int value):len(sz)
{
    cout << this << " : Kvector(int)" << endl;
    if(!sz){m = nullptr; return;}
    m = new int[sz];
    for(int i = 0; i < sz; i++)
        m[i] = value;
}
Kvector::Kvector(Kvector &obj)
{
    cout << this << " : Kvector(Kvector&)" << endl;
    len = obj.len;
    if(!len){m = nullptr; return;}
    m = new int[len];
    for(int i = 0; i < len; i++)
        m[i] = obj.m[i];
}
int main()
{
    Kvector v1(3); v1.print();
    Kvector v2(2,9); v2.print();
    Kvector v3(v2); v3.print();
    v2.clear();
    v2.print();
    v3.print();
    return 0;
}