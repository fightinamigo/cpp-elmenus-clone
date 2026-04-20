//Omar Rashad 20247008
//Amr Zaki 20245040
#pragma once
#ifndef UNTITLED_DELIVERY_DRIVER_H
#define UNTITLED_DELIVERY_DRIVER_H
#include "user.h"


class delivery_driver : public user {
private :
    string vehicleType;
    int completedDeliveries;
    double totalEarnings ;
public :
    delivery_driver();
    delivery_driver(string a,string b,string c, string v );
    void display();
    double calculate_Earnings();
    void completedDelivery(double orderValue); // btzwd 15% 3la floos el order
    string getVehicleType();
    int getCompletedDeliveries();
    double getTotalEarnings();
    delivery_driver operator ++ ();
    delivery_driver operator ++ (int);

};


#endif //UNTITLED_DELIVERY_DRIVER_H