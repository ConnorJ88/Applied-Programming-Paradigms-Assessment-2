#include <iostream>
#include <string>
#include "MainCourse.h"
using namespace std;
//constructor for maincourse
MainCourse::MainCourse(string Name, double Price, int Calories) 
	: Item(Name, Price, Calories) {}
