#pragma once
#include <iostream>
#include "Item.h"
using namespace std;
class Appetiser : public Item {
public:
	string toString() override;
	char virtual itemType() override { return 'a'; }
	bool shareable;
	bool twoForOne;
	Appetiser( string Name, double Price, int Calories, bool Shareable, bool TwoForOne);
	bool  two41()  ;
private:
	string appetisers;
	string share;
	string two4one;
	
};