//Omar Rashad 20247008
//Amr Zaki 20245040

#include "customer.h"
#include <iostream>

void customer :: display()
{
    cout <<  "name : " << name << endl
     << "id : " << id << endl
     << " phone number : " << phone_number << endl
    << " delivery address : " << delivery_address << endl
    << "loyalty points : " << loyalty_points*0.5 << endl;

};
customer::customer( string a,string b,string c,string d  ):user(a,b,c)
{
    delivery_address=d;
    loyalty_points=0;
}

double customer :: calculate_Earnings() {
    return loyalty_points * 0.5 ;
}
customer customer:: operator +=(const customer& other)
{
    loyalty_points += other.loyalty_points;
    return *this ;
}

void customer::set_delivery_address(string d) {
    delivery_address=d;
}

string customer::get_delivery_address() {
return delivery_address;
}

void customer::setloyalty_points(int e) {
    loyalty_points=e;
}


double customer::getloyalty_points() {
    return loyalty_points*0.5;
}
customer::customer ():user("","","") {
    delivery_address="";
    loyalty_points=0;

}
customer customer ::operator ++() {
    loyalty_points++;
}
