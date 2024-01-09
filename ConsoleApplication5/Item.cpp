#include <iostream>
#include <string>
#include <sstream> 
#include <iomanip>
#include "Item.h"
using namespace std;
//constructor for item
Item::Item(string Name, double Price, int Calories) : name(Name), price(Price), calories(Calories){}
//destructor for item
Item::~Item(){}
//item toString method
string Item::toString() {
	
	ostringstream p;
	//sets price to two decimal places
	p << fixed << setprecision(2) << price;
	string cost = p.str();
	return name + "," + " \x9c" + cost + ", " + to_string(calories) + "cal";
}
//returns item name
string Item::itemName() {
	return name;
}