#include <iostream>
using namespace std;

class Kvector
{
int *m;
int len;
public:
    static int total_len;
    Kvector(const int sz = 0, const int value = 0);
    // Kvector(int sz = 0, int value = 0);
    Kvector(const Kvector& v);
    ~Kvector()
    {
        total_len -= len;
        cout << this << " : ~Kvector() \n";
        cout << len << " decrease -> " << "total_len = " << total_len << "\n";
        delete[] m;
    }
    void print() const
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

int Kvector::total_len = 0;

Kvector::Kvector(const int sz, const int value):len(sz)
{
    cout << this << " : Kvector(int)" << endl;
    if(!sz){m = nullptr; return;}
    m = new int[sz];
    for(int i = 0; i < sz; i++)
        m[i] = value;
    total_len += sz;
}
// Kvector::Kvector(int sz, int value):len(sz)
// {
//     serial = ++total_len;
//     cout << this << " : Kvector(int)" << endl;
//     if(!sz){m = nullptr; return;}
//     m = new int[sz];
//     for(int i = 0; i < sz; i++)
//         m[i] = value;
// }
Kvector::Kvector(const Kvector &obj)
{
    cout << this << " : Kvector(Kvector&)" << endl;
    len = obj.len;
    if(!len){m = nullptr; return;}
    m = new int[len];
    for(int i = 0; i < len; i++)
        m[i] = obj.m[i];
    total_len += len;
}

int main()
{
    Kvector v1(3); v1.print();
    const Kvector v2(2,9); v2.print();
    Kvector v3(v2); v3.print();
    
    cout << "total length = " << Kvector::total_len << endl;
    v2.print();
    v3.print();
    cout << "total length = " << Kvector::total_len << endl;
    return 0;
}