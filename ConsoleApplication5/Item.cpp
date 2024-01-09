#include <iostream>
#include <string>
#include <sstream> 
#include <iomanip>
#include "Item.h"
using namespace std;
Item::Item(string Name, double Price, int Calories) : name(Name), price(Price), calories(Calories){}
Item::~Item(){}
string Item::toString() {
	
	ostringstream p;
	p << fixed << setprecision(2) << price;
	string cost = p.str();
	return name + "," + " \x9c" + cost + ", " + to_string(calories) + "cal";
}
string Item::itemName() {
	return name;
}