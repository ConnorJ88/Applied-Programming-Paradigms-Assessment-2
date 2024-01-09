#pragma once
#include <iostream>
#include "Item.h"
using namespace std;
class Beverage : public Item {
public:
	string toString() override;
	char virtual itemType() override { return 'b'; }	
	Beverage(string Name, double Price, int Calories, int Volume, float Abv);
	
	int volume;
	float abv;
private:
	string beverages;
	string alcohol;
	bool isAlcoholic();
};