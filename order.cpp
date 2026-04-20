//Omar Rashad 20247008
//Amr Zaki 20245040
#include <iostream>
#include <string>
#include "order.h"
using namespace std;
int order :: totalOrders=0;
order :: order () {
    capacity=10;
    items = new fooditem [capacity];
    itemCount = 0;
    totalOrders++;
    client = nullptr;
    driver = nullptr;
    status = PENDING;
}
order :: order (customer& s,string o) {
    client=&s;
    orderid=o;
    capacity=1;
    itemCount = 0;
    items = new fooditem [capacity];
    totalOrders++;
    status = PENDING;
}
order :: ~order ()
{
    delete[] items;
    totalOrders--;}

order :: order (const order& a)
{
    orderid =a.orderid;
    client=a.client;
    totalOrders++;
    capacity=a.capacity;
    status=a.status;
    driver=a.driver;
    items = new fooditem [capacity];
    for (int i = 0 ; i < capacity ; i++) {
        items[i]=a.items[i];
    }
    itemCount=a.itemCount;
}
order& order::operator+=(  fooditem& item) {
     this->additem(item);
     return *this;
 }

void order::additem( fooditem& item) {
    if (itemCount < capacity) {
        items[itemCount] = item;
        itemCount++;
    } else {
        cout << "Order is full!" << endl;
    }
}

void order::assignDriver(delivery_driver *drv) //points on the delivery and the user ??
{
    this-> driver =drv ;
    cout << "this operation is done" << endl ;
}

void order::updateStatus(OrderStatus newStatus) {

    status = newStatus;
    if (status == DELIVERED) {
        driver++;
        client+=1;
    }
    cout << "status updated" << endl;
}

int order::calculateTotal() {
    int sum;
    for (int i = 0 ; i < capacity ; i++) {
        sum+=items[i].getQuantity();
    }
    return sum;

}

void order::displayOrder() {
    for (int i = 0 ; i < capacity ; i++) {
        cout << "name :"<< items[i].getItemName() << "    " ;
        cout <<  "quantity :" <<items[i].getQuantity() << "    " ;
        cout <<  "price : :" <<items[i].getPrice() << endl;
    }
}

int order::getTotalOrders() {
    return totalOrders ;
}

string order::getOrderID() {
    return orderid;
}

customer order::getClient() {
    return *client;
}

delivery_driver order::getDriver() {
    return *driver;
}

int order::getitemcount() {
    return itemCount;
}

OrderStatus order::getStatus() {
    return status;
}



order& order::operator+(const order& other) {
    order CombinedOrder;
    for (int i = 0 ; i < capacity ; i++) {
        CombinedOrder.additem(this->items[i]);
    }
    for (int i = 0 ; i < other.capacity ; i++) {
        CombinedOrder.additem(other.items[i]);
    }
    return CombinedOrder;
}

ostream& operator<<(ostream& os, const order& a) {
    os << "order id :"<<a.orderid<< endl
    << "customer :" <<a.client << endl
    << "delivery :" << a.driver << endl;
    for (int i = 0 ; i < a.capacity ; i++) {
        os << "name :"<< a.items[i].getItemName() << "    " ;
        os <<  "quantity :" <<a.items[i].getQuantity() << "    " ;
        os <<  "price : :" <<a.items[i].getPrice() << endl;
    }
    return os ;
}
bool  operator >(const order& a,const order& b) {
    return a.orderid < b.orderid;
}

fooditem& order::operator[](const int& index) {
 return items[index];
}
void order ::setcapacity(int newcapacity) {
    capacity=newcapacity;
}





