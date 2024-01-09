#pragma once
#include <iostream>
#include "ItemList.h"
using namespace std;
class Order : public ItemList {
public:
	Order();
	string toString() override ;
	pair <double, double> calculateTotal(void);
	void printReceipt(void);
	void add(Item* item);
	void remove(Item* item);
private:
	vector <Item*> order;
	double total;
	double discount;
	int offers;
	vector<Item*> offer;
	string checkout;
	string totalString;
	string discountString;
};