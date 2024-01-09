#pragma once
#include <iostream>
#include "Item.h"
using namespace std;
class ItemList {
public:
	virtual string toString() = 0;
	vector<Item*> Items;
private:
	
};