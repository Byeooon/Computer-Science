//team.cpp
#include "team.h"

Team operator+(Team a, const Team& b)
{
    a += b;
    return a;
}
bool operator==(const Team& a, const Team& b)
{
    return (a.name == b.name); //Only Team name
}
bool operator !=(const Team& a, const Team& b)
{
    return !(a==b);
}
std::ostream& operator<<(std::ostream& os, const Team& a)
{
    os << a.name << "(" << a.wins << ")";
    return os;
}