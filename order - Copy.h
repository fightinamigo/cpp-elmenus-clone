//Omar Rashad 20247008
//Amr Zaki 20245040
#pragma once
#ifndef UNTITLED_ORDER_H
#define UNTITLED_ORDER_H
#include <iostream>
#include <string>
#include "customer.h"
#include "delivery_driver.h"
#include "fooditem.h"
#include "OrderStatus.h"
using namespace std;

class order {
private:
    string orderid;
    customer *client;
    delivery_driver *driver;
    fooditem *items;//arr
    int itemCount;
    int capacity;
    OrderStatus status ;
    static int totalOrders;
public:
    order();
    order(customer& a,string o );
    order (const order& a);
    ~order();
    void additem( fooditem&item);
    void assignDriver(delivery_driver* drv);
    void updateStatus(OrderStatus newStatus);
    int calculateTotal();
    void displayOrder();
    // getters
    int getTotalOrders();
    string getOrderID();
    customer getClient();
    delivery_driver getDriver();
    int getitemcount();
    OrderStatus getStatus();
    //operators
    order& operator+=( fooditem& item);
    order& operator +(const order& other);
    friend ostream& operator << (ostream& os, const order& a);
    friend bool operator >(const order& a,const order& b);
    fooditem& operator [](const int& x);
    void setcapacity(int newcapacity);

};


#endif //UNTITLED_ORDER_H