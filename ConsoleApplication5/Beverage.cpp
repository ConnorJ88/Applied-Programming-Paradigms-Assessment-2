#include <iostream>
#include <string>
#include <sstream> 
#include <iomanip>
#include "Beverage.h"
using namespace std;
//constructor for beverages
Beverage::Beverage(string Name, double Price, int Calories, int Volume, float Abv)
    : Item(Name, Price, Calories), volume(Volume), abv(Abv) {}
string Beverage::toString()  {
    beverages = "";
    //checks if its alcoholic
    if (isAlcoholic() == true) {
        //sets abv to one decimal place
        ostringstream p;
        p << fixed << setprecision(1) << abv;
        alcohol = p.str();
        beverages += Item::toString() + " " + to_string(volume) + "ml, " + alcohol + "%" + "abv";
    }
    else {
        beverages += Item::toString() + " " + to_string(volume) + "ml";
    }
    
    return beverages;
}
//checks if drink is alcoholic
bool Beverage::isAlcoholic() {
    return abv > 0.0;
}