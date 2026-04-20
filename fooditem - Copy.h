//Omar Rashad 20247008
//Amr Zaki 20245040
#pragma once
#ifndef UNTITLED_FOODITEM_H
#define UNTITLED_FOODITEM_H

using namespace std ;

class fooditem {
private:
    string itemName ;
    double price;
    int quantity;
    static int totalitem;
public:
    fooditem();
    fooditem(string i, double p , int q);
    string getItemName();
    double getPrice();
    int getQuantity();
    void setItemName(string i);
    void setPrice(double p);
    void setQuantity(int q);
    int calculateitemTotal();
    void displayitem();
    friend istream& operator >>(istream& in ,  fooditem& other);
    fooditem operator=( fooditem& other);
};


#endif //UNTITLED_FOODITEM_H