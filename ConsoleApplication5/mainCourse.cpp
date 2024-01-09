#include <iostream>
#include <string>
#include "MainCourse.h"
using namespace std;
MainCourse::MainCourse(string Name, double Price, int Calories) 
	: Item(Name, Price, Calories) {}
