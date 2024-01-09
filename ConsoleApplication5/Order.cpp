#include "Order.h"
#include "Item.h"
#include "ItemList.h"
#include "Appetiser.h"
#include <fstream>
#include <sstream>
#include<iostream>
#include <vector>
#include <iomanip>
Order::Order() {
	total = 0;
	discount = 0;
	offers = 0;
}
pair <double, double> Order::calculateTotal(){
	total = 0;
	discount = 0;
	offers = 0;
	for (int x = 0; x < order.size(); x++) {
		total = total + order[x]->price;
		
	}
	for (int x = 0; x < order.size(); x++) {
		if (order[x]->itemType() == 'a') {
			const Appetiser* appetiser = dynamic_cast<const Appetiser*> (order[x]);
			if (appetiser->twoForOne == true) {
				offers = offers + 1;
				offer.push_back(order[x]);
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
	return make_pair( total, discount);
}
void Order::printReceipt() {
	ofstream receipt("receipt.txt");
	receipt << toString();
}
string Order::toString() {
	pair <double, double> result = calculateTotal();
	ostringstream p;
	ostringstream x;
	total = result.second;
	p << fixed << setprecision(2) << discount;
	discountString = p.str();
	total = result.first;
	x << fixed << setprecision(2) << total;
	totalString = x.str();
	checkout = "";

	checkout += "\t=======Checkout=======\t\n";
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
	
	return checkout;
}
void Order::add(Item* item) {
	order.push_back(item);
	cout << item->itemName() + " added to order!\n";

}
void Order::remove(Item* item) {
	auto it = find(order.begin(), order.end(), item);
	order.erase(it);
	cout << "Removed " + item->itemName() + " from order";
}
