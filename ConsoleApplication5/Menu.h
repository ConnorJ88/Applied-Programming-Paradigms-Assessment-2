#pragma once
#include <iostream>
#include "ItemList.h"
using namespace std;
class Menu : public ItemList {
	

public:
	Menu(const string& fileName);
	void load(const string& fileName);
	string toString() override;
	Item* getItemIndex(int index);
};