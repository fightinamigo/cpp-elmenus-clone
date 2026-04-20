//Omar Rashad 20247008
//Amr Zaki 20245040
#include <iostream>
#include <string>
#include "fooditem.h"
using namespace std ;
int fooditem :: totalitem=0;
fooditem::fooditem()
{
    itemName = "";
    price = 0;
    quantity = 0;
    ++totalitem;
}

fooditem::fooditem(string i, double p, int q) {
    itemName = i;
    price = p;
    quantity = q;
    ++totalitem;
}

string fooditem::getItemName() {
    return itemName;
}

int fooditem::getQuantity() {
    return  quantity;
}

void fooditem::setQuantity(int q) {
   quantity = q;
}

void fooditem::setItemName(string i) {
    itemName = i;
}


double fooditem:: getPrice() {
    return price ;
}

int fooditem::calculateitemTotal() {
    return totalitem;
}


void fooditem::displayitem() {
    cout << "Item's name : "<< itemName << endl
    << "price : " << price << endl
    << "quantity : " << quantity << endl;
}
istream&  operator >>(istream& in, fooditem& other) {
    cout << "enter item name : ";
    in >> other.itemName;
cout << "enter item quantity : ";
    in >> other.quantity;
    return in;
}

fooditem fooditem:: operator=( fooditem& other) {
    itemName = other.itemName;
    price = other.price;
    quantity = other.quantity;
    return *this;
}








