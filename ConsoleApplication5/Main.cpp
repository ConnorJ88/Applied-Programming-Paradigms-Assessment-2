#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	while (userCommand != "exit")
	{
		cout << "Enter Input";
		getline(cin, userCommand);
		
		try {
			if (!userCommand.empty() == true) {
				char* cstr = new char[userCommand.length() + 1];
				strcpy(cstr, userCommand.c_str());

				char* token;
				token = strtok(cstr, " ");
				while (token != NULL)
				{
					parameters.push_back(token);
					token = strtok(NULL, " ");
				}

				if (!parameters.empty()) {
					string command = parameters[0];

					if (command.compare("menu") == 0) {
						cout << menu.toString();
					}
					else if (command.compare("add") == 0)
					{
						Item* choice = nullptr; // you need to instantiate this using the menu object!

						if (parameters.size() >= 1) {
							try {
								int index = stoi(parameters[1]) - 1;
								choice = menu.getItemIndex(index);
							}
							catch (out_of_range& e) {
								throw runtime_error("Invalid Input");
							}
							catch (invalid_argument& e) {
								throw runtime_error("Invalid Input");
							}
						}

						else {
							throw runtime_error("Invalid Input");
						}

						if (choice != nullptr) {
							order.add(choice);
						}

					}
					//you may also wish to implement the ability to add multiple items at once!
					// e.g. add 1 5 9 

					else if (command.compare("remove") == 0)
					{
						Item* choice = nullptr; // you need to instantiate this using the menu object!
						if (parameters.size() >= 1) {
							try {
								int index = stoi(parameters[1]) - 1;
								choice = menu.getItemIndex(index);
							}
							catch (out_of_range& e) {
								throw runtime_error("Invalid Input");
							}
							catch (invalid_argument& e) {
								throw runtime_error("Invalid Input");
							}
						}

						else {
							throw runtime_error("Invalid Input");
						}

						if (choice != nullptr) {
							order.remove(choice);
						}
					}
					else if (command.compare("checkout") == 0)
					{
						string check = "";
						cout << order.toString();
						cout << "Do you want to place your order\n Type 'y' to checkout or 'n' to go back and modify it";
						cin >> check;
						if ( check == "y") {
							order.printReceipt();
						}
					}
					else if (command.compare("help") == 0)
					{
						string help = "";
						help += "\t=============Checkout=============\t\n";
						help += "\t'menu' - display the menu\n ";
						help += "\t'add' [INDEX] - add an item to the order\n ";
						help += "\t'remove' [INDEX] - remove item from order\n ";
						help += "\t'checkout - display the items in the order\n ";
						help += "\t'exit'\n";

					}
					else {
						cout << "Invalid Input\n";
					}
					parameters.clear();

				}
				else {
					throw runtime_error("Invalid Input");
				}
			}
		}
		catch(exception& e){
			cout << e.what() << endl;
		}
	}
		
		
		

	cout << "Press any key to quit...";
	std::getchar();
	return 0;
}