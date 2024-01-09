#include "Order.h"
#include "Item.h"
#include "ItemList.h"
#include "Appetiser.h"
#include <fstream>
#include <sstream>
#include<iostream>
#include <vector>
#include <iomanip>
//default constructor for order
Order::Order() {
	total = 0;
	discount = 0;
	offers = 0;
}
pair <double, double> Order::calculateTotal(){
	total = 0;
	discount = 0;
	offers = 0;
	//calculates the total price of the order
	for (int x = 0; x < order.size(); x++) {
		//uses a pointer to the items price
		total = total + order[x]->price;
		
	}
	//iterates through the order to check for appetisers
	for (int x = 0; x < order.size(); x++) {
		if (order[x]->itemType() == 'a') {
			//sets the item as a pointer to the appetiser class so that twoForOne can be accessed
			const Appetiser* appetiser = dynamic_cast<const Appetiser*> (order[x]);
			//checks if the item is part of the twoForOne offer
			if (appetiser->twoForOne == true) {
				offers = offers + 1;
				offer.push_back(order[x]);
				//if there are two offers in the offer vector it removes the lowest value from total
				if (offers == 2){
					if (offer[0]->price > offer[1]->price) {
						total = total - offer[1]->price;
						discount = discount + offer[1]->price;
						offer.clear();
						offers = 0;
					}
					else if (offer[0]->price < offer[1]->price) {
						total = total - offer[0]->price;
						discount = discount + offer[0]->price;
						offer.clear();
						offers = 0;
					}
					else
					{
					total = total - offer[0]->price;
						discount = discount + offer[0]->price;
						offer.clear();
						offers = 0;
					}
				}				
			}			
		}
	}
	//returns both the value of total and discount as a pair
	return make_pair( total, discount);
}
//writes the receipt to a file
void Order::printReceipt() {
	ofstream receipt("receipt.txt");
	receipt << toString();
}

string Order::toString() {
	pair <double, double> result = calculateTotal();
	ostringstream p;
	ostringstream x;
	//formats total and discount to two decimal places
	total = result.second;
	p << fixed << setprecision(2) << discount;
	discountString = p.str();
	total = result.first;
	x << fixed << setprecision(2) << total;
	totalString = x.str();
	//create a string of the checout details
	checkout = "";
	
	checkout += "\t=======Checkout=======\t\n";
	//adds all the items in the order to string checkout
	for (int a = 0; a < order.size(); a++) {
		string orderString = "";
		orderString = order[a]->toString();
		checkout += '(' + to_string(a+1) + ")" + orderString + "\n";
	}
	checkout += "\t--------------------\t\n";
	if (discount > 0) {
		checkout += "2-4-1 Discount applied! Savings: \x9c" + discountString + "\n";
	}
	checkout += "Total: \x9c" + totalString + "\n";
	//returns the entire string checkout ready to be outputted
	return checkout;
}
void Order::add(Item* item) {
	//adds the item to the order
	order.push_back(item);
	cout << item->itemName() + " added to order!\n";

}
void Order::remove(Item* item) {
		//ensures the order isn't empty before attempting to remove an item
		
		if (!order.empty()) {
			//finds the item in the order
			auto it = find(order.begin(), order.end(), item);
			//makes sure the item is present in the order
			if (it != order.end()) {
				//removes the item from the order
				order.erase(it);
			}
			else {
				cout << "Item not found in order\n";
			}
		}
		else {
			cout << "Cannot remove anything from an empty order\n";
		}
	
		
}

