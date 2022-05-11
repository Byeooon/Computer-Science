#include <iostream>
using namespace std;

class Kvector
{
int *m;
int len;
public:
    Kvector(const int sz = 0, const int value = 0);
    Kvector(const Kvector& v);
    ~Kvector()
    {
        cout << this << " : ~Kvector() \n";
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
    Kvector& operator=(const Kvector& c);
    int& operator[](int idx) {return m[idx];}
    const int& operator[](int idx)const{return m[idx];}

    friend bool operator==(const Kvector& c, const Kvector& d);
    friend ostream& operator<<(ostream&os, const Kvector&c);
};

Kvector& Kvector::operator=(const Kvector& c)
{
    delete[] m;
    len = c.len;
    m = new int[len];
    for(int i = 0; i < len; i++)
        m[i] = c.m[i];
    return *this;
}
bool operator==(const Kvector& c, const Kvector& d)
{
    if(c.len != d.len) return false; //compare length first
    for(int i = 0; i < c.len; i++)
        if(c.m[i] != d.m[i]) return false;
    return true;
}
bool operator!=(const Kvector& c, const Kvector& d)
{
    return !(c == d); // !operator==
}
ostream& operator<<(ostream& os, const Kvector& c)
{
    for(int i = 0; i < c.len; i++)
        os << c.m[i] << " ";
    return os;
}

Kvector::Kvector(const int sz, const int value):len(sz)
{
    cout << this << " : Kvector(int)" << endl;
    if(!sz){m = nullptr; return;}
    m = new int[sz];
    for(int i = 0; i < sz; i++)
        m[i] = value;
}
Kvector::Kvector(const Kvector &obj)
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
    cout << (v1 == v2) << endl;
    cout << (v3 == v2) << endl;
    v3 = v2 = v1;
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    cout << "v1 : " << v1 << "v2 : " << v2 << "v3 : " << v3 << endl;
    return 0;
}
