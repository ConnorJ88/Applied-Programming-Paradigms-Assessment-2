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
	//initialise variables
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	// continues until user inputs exit
	while (userCommand != "exit")
	{
		//resets userCommand
		userCommand = "";
		cout << "Enter Input";
		//gets userCommand from terminal
		getline(cin, userCommand);
		
		try {
			//ensures there is a user input
			if (!userCommand.empty() == true) {
				//tokenises input 
				char* cstr = new char[userCommand.length() + 1];
				strcpy(cstr, userCommand.c_str());

				char* token;
				token = strtok(cstr, " ");
				while (token != NULL)
				{
					parameters.push_back(token);
					token = strtok(NULL, " ");
				}
				//ensures parameters isn't empty
				if (!parameters.empty()) {
					//gets the command from parameters
					string command = parameters[0];
					//checks the command
					if (command.compare("menu") == 0) {
						//displays the menu from Menu::toString()
						cout << menu.toString();
					}
					else if (command.compare("add") == 0)
					{
						Item* choice = nullptr; 
						//checks there were enough values inputted from the user
						if (parameters.size() >= 1) {
							try {
								//converts the first value of parameters to an integer
								int index = stoi(parameters[1]) - 1;
								//instantiates the choice using menu 
								choice = menu.getItemIndex(index);
							}
							//catches exception if user enters index out of range
							catch (out_of_range& e) {
								throw runtime_error("Invalid Input: Index out of range");
							}
							//catches exception if user enters an invalid input after add e.g add x
							catch (invalid_argument& e) {
								throw runtime_error("Invalid Input: Please enter a valid integer");
							}
						}

						else {
							throw runtime_error("Invalid Input");
						}
						//ensures choice isn't empty
						if (choice != nullptr) {
							//adds choice to the order using Order::add()
							order.add(choice);
						}

					}
					//you may also wish to implement the ability to add multiple items at once!
					// e.g. add 1 5 9 

					else if (command.compare("remove") == 0)
					{
						Item* choice = nullptr; 
						//checks parameters isnt empty
						if (parameters.size() >= 1) {
							try {
								//attempts to convert the user input to int
								int index = stoi(parameters[1]) - 1;
								//gets item from the specified index
								choice = menu.getItemIndex(index);
							}
							catch (out_of_range& e) {
								throw runtime_error("Invalid Input: Index out of range");
							}
							catch (invalid_argument& e) {
								throw runtime_error("Invalid Input: Please enter a valid integer");
							}
						}

						else {
							throw runtime_error("Invalid Input");
						}
						//ensures choice isn't a null pointer
						if (choice != nullptr) {
							//removes the choice from the order
							order.remove(choice);
						}
					}
					else if (command.compare("checkout") == 0)
					{
						//displays order and asks for confirmation
						string check = "";				
						cout << order.toString();
						cout << "Do you want to place your order\n Type 'y' to checkout or 'n' to go back and modify it";
						getline(cin, check);
						if ( check == "y") {
							//calls printReceipt function to store receipt in a seperate text file
							order.printReceipt();
						}
						else {
							cout << "Continuing with order";
						}
					}
					else if (command.compare("help") == 0)
					{
						//displays the help menu
						string help = "";
						help += "\t=============Help=============\t\n";
						help += "'menu' - display the menu\n ";
						help += "'add' [INDEX] - add an item to the order\n ";
						help += "'remove' [INDEX] - remove item from order\n ";
						help += "'checkout - display the items in the order\n ";
						help += "'exit'\n";
						cout << help;

					}
					else {
						cout << "Invalid Input\n Type 'help' to see all commands ";
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
			parameters.clear();
		}
	}
		
		
		
	//closes the program
	cout << "Press any key to quit...";
	std::getchar();
	return 0;
}