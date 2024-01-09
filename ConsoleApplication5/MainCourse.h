#pragma once
#include <iostream>
#include "Item.h"
using namespace std;
class MainCourse : public Item {
public:
	MainCourse(string Name, double Price, int Calories);
	char virtual itemType() override { return 'm'; }
	
};