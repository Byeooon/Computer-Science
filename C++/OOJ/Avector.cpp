#include <iostream>
using namespace std;
#define N 3

class Kvector
{
protected:    
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

class Avector : public Kvector{
    char table[N];
public:
    Avector(int sz=0, int v=0, const char *t="abc"); //default
    void setTable(const char *t);
    void print() const;
friend std::ostream& operator <<(ostream& os, const Avector& v);
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
    cout << this << " : Kvector(" << sz << "," << value << ")\n";
    if(!sz){m = nullptr; return;}
    m = new int[sz];
    for(int i = 0; i < sz; i++)
        m[i] = value;
}
Kvector::Kvector(const Kvector &obj)
{
    cout << this << " : Kvector(* " << &obj << ")\n";
    len = obj.len;
    if(!len){m = nullptr; return;}
    m = new int[len];
    for(int i = 0; i < len; i++)
        m[i] = obj.m[i];
}

Avector::Avector(int sz, int v, const char *t): Kvector(sz, v)
{
    cout << this << " : Avector(" << sz <<"," << v <<","<<t<<")\n";
    for(int i = 0; i < N; i++) table[i] = t[i];
    
}
void Avector::setTable(const char *t)
{
    for (int i = 0; i < N; i++) table[i] = t[i];
}
void Avector::print()const
{
    cout << "Avector with table : " << table <<endl;
    for (int i = 0; i < len; i++) cout << m[i] <<" ";
    cout << endl;
}

ostream& operator <<(ostream&os , const Avector& v)
{
    for(int i = 0; i < v.len; i++) 
        os << v.table[v.m[i]%N] << " ";
    return os;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "usage : ./avector pqr\n";
        return 1;
    }

    Avector v1(3); v1.print();
    Avector v2(2, 1, "xyz"); v2.print();
    Avector v3(v2); v3.print();
    cout << "v1 == v2 : "<< (v1 == v2) << endl;
    cout << "v3 == v2 : "<< (v3 == v2) << endl;
    v3 = v2 = v1; //assign
    cout << "v1 : "<< v1 << endl;
    v1.print();
    cout << "v2 : "<< v2 << endl;
    v2.print();
    cout << "v3 : "<< v3 << endl;
    v3.print();
    cout << "v3 != v2 : " << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    v1.setTable(argv[1]);
    cout << "v1 : " << v1 << "v2 : " << v2 << "v3 : " << v3 << endl;
    v1.print();
    v2.print();
    v3.print();
    return 0;
}
