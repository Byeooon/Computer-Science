//Kvector.h
#include <iostream>
#ifndef __KVECTOR__
#define __KVECTOR__
using namespace std;

template<class T>
class Kvector;
template<class T>
bool operator == (const Kvector<T> &v, const Kvector<T> & w);
template<class T>
bool operator != (const Kvector<T> &v, const Kvector<T> & w);
template<class T>
std::ostream& operator<<(std::ostream& os, const Kvector<T>& v);

template<class T>
class Kvector{
protected:
    T *m;
    int len;
public:
    Kvector<T>(int sz=0, T value=0);
    Kvector<T>(const Kvector<T>&v);
virtual ~Kvector<T>();
virtual void print() const {std::cout << "Kvector\n";}
    void clear() {delete[]m;  m=nullptr; len=0;}
    int size() const {return len;}
    T sum() const
    {
        if(!len) return T();
        T s = m[0];
        for(int i = 1; i < len; i++) s+=m[i];
        return s;
    } 
Kvector<T>& operator=(const Kvector<T>& v);
T& operator[](int idx){return m[idx];}
const T& operator[](int idx) const {return m[idx];}
friend bool operator==<>(const Kvector<T>&v , const Kvector& w);
friend bool operator!=<>(const Kvector<T>&v , const Kvector& w);
friend std::ostream& operator << <>(std::ostream&os, const Kvector<T>&v);
};

template<class T>
Kvector<T>::Kvector(int sz, T value): len(sz)
{
    std::cout << this <<" : Kvector(" << sz <<"," << value << ")\n";
    if(!sz) {m=NULL; return ;}
    m = new T [sz];
    for (int i=0; i<len; i++) m[i] =value;
}
template<class T>
Kvector<T>::Kvector(const Kvector<T>&v) {
    cout << this << " : Kvector(*" << &v <<")\n";
    len =v.len;
    if(!len) {m=NULL; return ;}
    m = new int[len];
    for (int i=0; i<len; i++) m[i] = v.m[i];
}
template<class T>
Kvector<T>::~Kvector(){
    cout << this << " : ~Kvector() \n";
    delete[] m;
}
template<class T>
Kvector<T>& Kvector<T>::operator=(const Kvector<T>&v)
{
    cout << "Kvector::operator=" << &v <<endl;
    delete[]m;
    len=v.len;
    m=new int[len];
    for(int i=0; i<len; i++) m[i] = v.m[i];
    return *this;
}
template<class T>
bool operator==(const Kvector<T>& v, const Kvector<T>& w){
    if (v.len != w.len) return false;
    for(int i=0; i<v.len; i++)
        if(v.m[i] !=w.m[i]) return false;
    return true;
}
template<class T>
bool operator!=(const Kvector<T>&v, const Kvector<T>& w){
    return !(v==w);
}
template<class T>
std::ostream& operator<<(std::ostream&os, const Kvector<T>& v){
    for (int i=0; i<v.len; i++) os <<v.m[i] <<" ";
    return os;
}
#endif