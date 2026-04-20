//Omar Rashad 20247008
//Amr Zaki 20245040
#pragma once
#ifndef UNTITLED_CUSTOMER_H
#define UNTITLED_CUSTOMER_H
#include "user.h"

class customer : public user {
private:
    string delivery_address;
    int loyalty_points;
public:
    customer();
    customer(string a,string b,string c,string d );


    void display();
    double calculate_Earnings();
    string get_delivery_address();
    void set_delivery_address(string d);
    double getloyalty_points();
    void setloyalty_points(int e);
    customer operator +=(const customer& other);
    customer operator ++();
};


#endif //UNTITLED_CUSTOMER_H