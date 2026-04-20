//Omar Rashad 20247008
//Amr Zaki 20245040
#include<string>
#include<iostream>
#include "delivery_driver.h"
using namespace std;

delivery_driver::delivery_driver() {
    vehicleType = "" ;
    completedDeliveries = 0 ;
    totalEarnings = 0 ;
}

delivery_driver::delivery_driver(string a,string b,string c, string v ):user(a,b,c)
{
    vehicleType = v ;
    completedDeliveries =0 ;
    totalEarnings = 0 ;

}

void delivery_driver::display() {
    cout << vehicleType << " " << completedDeliveries << " " << totalEarnings << endl ;
}

double delivery_driver::calculate_Earnings() {
    return totalEarnings;
}



void delivery_driver::completedDelivery(double orderValue) {
     totalEarnings += orderValue * 0.15 ;

}

int delivery_driver::getCompletedDeliveries() {
    return completedDeliveries ;
}

delivery_driver delivery_driver :: operator++() {
    completedDeliveries++ ;
    return *this ;

}

delivery_driver delivery_driver :: operator++(int) {
    completedDeliveries++ ;
    return *this ;

}




