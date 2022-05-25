//team.h
#include <iostream>
#include <string> 

class Team
{
    std::string name;
    //It's better not to put "using namespace std" in header file.
    int wins;
public :
    Team(const std::string& n = "teamX", int w=0) : name(n), wins(w){}
    Team& operator+=(const Team& rhs)
    {
        wins += rhs.wins;
        return *this;
    }
    friend Team operator+(Team a, const Team& b);
    friend bool operator==(const Team& a, const Team& b);
    friend bool operator!=(const Team& a, const Team& b);
    friend std::ostream& operator<<(std::ostream& os, const Team& a);
};