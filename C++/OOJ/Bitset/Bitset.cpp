//BitSet.cpp
#include <iostream>
#include "BitSet.h"
using namespace std;

BitSet::BitSet(int sz): Bvector(sz){}

// set the vth bit as true(1)
void BitSet::insert(int v){ set(v);}

BitSet operator+(const BitSet& v1, const BitSet& v2)
{
    if(v1.NBITS != v2.NBITS)
    {
        throw IncompatibleException(v1,v2);
    }
    BitSet r(v1.NBITS);
    for (int i=0; i<r.len; i++) r.u_m[i] = v1.u_m[i] |v2.u_m[i];
    return r;
}

// print out the true bit, which has value of 1
ostream& operator<<(ostream& os, const BitSet& s)
{
    os <<"{ ";
    for(int i=0; i<s.NBITS; i++) if(s[i]) os << i <<" ";
    os << "}";
    return os;
}

int main(int argc, char *argv[]){
    BitSet b1(131),b2(131);
    b1.insert(3); b1.insert(5); b1.insert(8);
    b2.insert(4); b2.insert(5); b2.insert(8); b2.insert(130);
    b1.print(); b2.print();

    cout << "b1 = " << b1 << endl;
    cout << "b2 = " << b2 << endl;
    try
    {
        cout << "b1 + b2 = " << b1 + b2 << endl;
    }
    catch(IncompatibleException& error) 
    {
        cout << error.print() << endl;
        cout << "the size of the first Bitset is " << error.nbits1 << endl;
        cout << "the size of the second Bitset is " << error.nbits2 << endl;
    }

    return 0;

}