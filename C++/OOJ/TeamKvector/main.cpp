//main.cpp
#include <iostream>
#include "team.h"
#include "Kvector.h"
using namespace std;

int main(int argc, char *argv[])
{
    Kvector<Team> league1(2, Team()), league2(2, Team());
    cout << "league1 : " << league1 << endl;
    cout << "league2 : " << league2 << endl;
    league1[0] = Team("Twins", 10);
    league1[1] = Team("Bears", 5);
    league2[0] = Team("Twins", 80);
    league2[1] = Team("Bears", 81);
    cout << "league1 : " << league1 << endl;
    cout << "league2 : " << league2 << endl;
    cout << "league1 == league2 : " << (league1 == league2) << endl;
    league2[0] = Team("Bulls", 80);
    league2[1] = Team("Warriors", 81);
    cout << "league1 : " << league1 << endl;
    cout << "league2 : " << league2 << endl;
    cout << "league1.sum() : " << league1.sum() << endl;
    cout << "league2.sum() : " << league2.sum() << endl;
}
