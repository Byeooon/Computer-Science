//BitSet.h
#include <iostream>
#include "Bvector.h"

class BitSet : public Bvector{
    public:
        BitSet(int sz=32);

void insert(int v);

friend class IncompatibleException;
friend BitSet operator+(const BitSet& v1, const BitSet& v2);
friend std::ostream& operator <<(std::ostream& os, const BitSet& s);
};

class IncompatibleException : public std::exception 
{
public:    
    int nbits1;
    int nbits2;

    IncompatibleException(const BitSet& v1, const BitSet& v2) : nbits1(v1.NBITS), nbits2(v2.NBITS){};

    const char* print() 
    {
        return "In + operation, the operands are not compatible";
    }
};