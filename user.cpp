//Omar Rashad 20247008
//Amr Zaki 20245040
#include "user.h"
#include <iostream>
#include <string>

using namespace std ;

int user:: total_users =0;
user :: user(const string& a,const string& b,const string& c) {
    id = a;
    name = b;
    phone_number = c;
    total_users++;
}
user ::  user()
{
    total_users++;
};
int user :: get_total_user() {
    return total_users;
};

string user ::  get_id()
{
    return id;
}
string user :: getname()
{
    return name;
}
user :: ~user() {
    total_users--;
}