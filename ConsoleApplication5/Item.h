#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Item {
public:
	char virtual itemType() = 0;
	Item(string Name, double Price, int Calories);
	 ~Item(); 
	virtual string toString();
	
	string itemName();
	string name;
	int calories;
	double price;

	

};