//Omar Rashad 20247008
//Amr Zaki 20245040
#pragma once
#ifndef UNTITLED_HEADERS_H
#define UNTITLED_HEADERS_H
#include <string>
using namespace std;
class user {
protected:
    string id;
    string name;
    string phone_number;
    static int total_users;
public :
    user();
    user(const string& a,const string& b,const string& c);
    virtual void display() = 0;
    static int get_total_user();
    virtual double calculate_Earnings() = 0;
    string get_id();
    string getname();
    virtual ~user() = 0 ;
};

#endif //UNTITLED_HEADERS_H