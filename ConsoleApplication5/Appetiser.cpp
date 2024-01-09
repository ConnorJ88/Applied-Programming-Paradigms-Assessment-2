#include <iostream>
#include <string>
#include "Appetiser.h"
using namespace std;
Appetiser::Appetiser(string Name, double Price, int Calories, bool Shareable, bool TwoForOne)
    : Item(Name, Price, Calories), shareable(Shareable), twoForOne(TwoForOne) {}
string Appetiser::toString()   {
    appetisers = "";
    if (to_string(shareable) == "1") {
        share = "Shareable";
    }
    else
    {
        share = "";
    }
    if (to_string(twoForOne) == "1") {
        two4one = "2-4-1";
    }
    else {
        two4one = "";
    }
    if (share != "" && two4one != "") {
        appetisers += Item::toString() + ", " + "(" + share + ", " + two4one + ") ";
    }
    else {
        appetisers += Item::toString() + ", " + "(" + share + two4one + ")" ;
    }
    return appetisers;
}
bool  Appetiser::two41()  {
    if (to_string(twoForOne) == "1") {
        return true;
    }
    else {
        return false;
    }
}
