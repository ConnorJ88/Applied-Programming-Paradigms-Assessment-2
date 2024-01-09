#include "Menu.h"
#include "Item.h"
#include "Appetiser.h" 
#include "MainCourse.h"
#include "Beverage.h"
#include <fstream>
#include <sstream>
#include<iostream>

using namespace std;
Menu::Menu(const string& fileName) {
	load(fileName);
	
}
void Menu::  load(const string& fileName){
	ifstream menu;
	string line = "";
	
	menu.open(fileName);
	if (menu.fail()) {
		cout << "Failed to open file" << endl;
	}
	else {
		Items.clear();
		
		while (getline(menu, line)) {//goes through every line
			stringstream inputString(line);
			string type;
			string name;
			double price;
			int calories = 0;
			bool shareable;
			bool twoForOne;
			int volume;
			float abv;
			string tempstring;
			getline(inputString, type, ',');//checks the type of item
			if (type == "a") {
				getline(inputString, name, ',');
				getline(inputString, tempstring, ',');
				price = atof(tempstring.c_str());
				tempstring = "";
				getline(inputString, tempstring, ',');
				calories = atoi(tempstring.c_str());
				tempstring = "";
				getline(inputString, tempstring, ',');
				if (tempstring == "y") {
					shareable = true;
				}
				else
				{
					shareable = false;
				}
				tempstring = "";
				getline(inputString, tempstring, ',');
				if (tempstring == "y") {
					twoForOne = true;
				}
				else
				{
					twoForOne = false;
				}
				
				Items.push_back(new Appetiser(name, price,  calories,  shareable, twoForOne));
	
			}
			if (type == "m") {
				getline(inputString, name, ',');
				getline(inputString, tempstring, ',');
				price = atof(tempstring.c_str());
				
				tempstring = "";
				getline(inputString, tempstring, ',');
				calories = atoi(tempstring.c_str());
				Items.push_back(new MainCourse(name, price, calories));

			}

			if (type == "b") {
				getline(inputString, name, ',');
				getline(inputString, tempstring, ',');
				price = atof(tempstring.c_str());
				tempstring = "";
				getline(inputString, tempstring, ',');
				calories = atoi(tempstring.c_str());
				inputString.ignore();
				inputString.ignore();
				getline(inputString, tempstring, ',');
				
				volume = atof(tempstring.c_str());
				getline(inputString, tempstring, ',');
				abv = atof(tempstring.c_str());
				Items.push_back(new Beverage(name, price, calories, volume, abv));
				
			}
				
			
		}
	}
}
string Menu::toString()  {
	vector <string> main;
	vector <string> appetiser;
	vector <string> beverage;
	string menu = "";

	beverage.clear();
	main.clear();
	appetiser.clear();
	
	for (int a = 0; a < Items.size(); a++)
	{
		if (Items[a]->itemType() == 'a') {
			appetiser.push_back("(" + to_string(a + 1) + ")" + Items[a]->toString());		
			
			
		}	
		else if (Items[a]->itemType() == 'm') {
			main.push_back("(" + to_string(a + 1) + ")" + Items[a]->toString());
		}
		else if (Items[a]->itemType() == 'b') {
			beverage.push_back("(" + to_string(a + 1) + ")" + Items[a]->toString());
		}
		
	}
	menu += "\t________Appetisers_________\t\n";
	for (int a = 0; a < appetiser.size(); a++)
	{		
		menu += appetiser[a] + "\n";
	}
	menu += "\t________Mains_________\t\n";
	for (int a = 0; a < main.size(); a++)
	{
		menu += main[a] + "\n";
	}
	menu += "\t________Beverages_________\t\n";
	for (int a = 0; a < beverage.size(); a++)
	{
		menu += beverage[a] + "\n";
	}
	
	return menu;
	
}
Item* Menu::getItemIndex(int index)  {
	if (index >= 0 && index <= Items.size()) {
		return Items[index];
	}
	else {
		cout << "Error: Invalid Item Index";
		return nullptr;
	}
}
	
	
	
	
