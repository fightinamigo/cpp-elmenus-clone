// Omar Rashad 20247008
// Amr Zaki 20245040


#include <iostream>
#include <string>
#include <fstream>
#include "customer.h"
#include "order.h"
#include "delivery_driver.h"
#include "fooditem.h"

using namespace std;

void txt(order& o);

customer** findcust (customer** cust, int custCount, string Id) {
    for (int i = 0; i < custCount; i++) {
        if (Id == cust[i]->get_id()) {
            return &cust[i];
        }
    }
    return nullptr;
}

delivery_driver** findDriver (delivery_driver** driv, int drivCount, string Id) {
    for (int i = 0; i < drivCount; i++) {
        if (Id == driv[i]->get_id()) {
            return &driv[i];
        }
    }
    return nullptr;
}

order** findorder (order** ord, int ordCount, string Id) {
    for (int i = 0; i < ordCount; i++) {
        if (Id == ord[i]->getOrderID()) {
            return &ord[i];
        }
    }
    return nullptr;
}

void saveCompletedOrders(order** orders, int ordCount) {
    ofstream outFile("completed_orders.txt");

    if (!outFile) {
        cout << "Error: Could not create file!" << endl;
        return;
    }

    cout << "\n--- REPORT: COMPLETED ORDERS ---" << endl;

    bool found = false;
    for (int i = 0; i < ordCount; i++) {
        if (orders[i]->getStatus() == DELIVERED) {
            found = true;

            cout << *orders[i];
            cout << "Total: " << orders[i]->calculateTotal() << " EGP" << endl;
            cout << "-----------------------------------" << endl;

            outFile << *orders[i];
            outFile << "Total: " << orders[i]->calculateTotal() << " EGP" << endl;
            outFile << "-----------------------------------" << endl;
        }
    }

    if (!found) {
        cout << "No completed orders found to save." << endl;
        outFile << "No completed orders found." << endl;
    } else {
        cout << ">> Data successfully saved to 'completed_orders.txt'" << endl;
    }

    outFile.close();
}

void saveDriverStats(delivery_driver** drivers, int drivCount) {
    ofstream outFile("driver_stats.txt");

    if (!outFile) {
        cout << "Error: Could not create file!" << endl;
        return;
    }

    cout << "\n--- REPORT: DRIVER STATISTICS ---" << endl;

    cout << "Name                          Deliveries              Earnings" << endl;
    cout << "------------------------------------------" << endl;
    outFile << "Name                        Deliveries              Earnings" << endl;
    outFile << "------------------------------------------" << endl;

    for (int i = 0; i < drivCount; i++) {
        cout << drivers[i]->getname() << "                          "
             << drivers[i]->getCompletedDeliveries() << "                          "
             << drivers[i]->calculate_Earnings() << " EGP" << endl;

        outFile << drivers[i]->getname() << "                          "
                << drivers[i]->getCompletedDeliveries() << "                          "
                << drivers[i]->calculate_Earnings() << " EGP" << endl;
    }

    cout << "\n>> Data successfully saved to 'driver_stats.txt'" << endl;
    outFile.close();
}


template<typename T>
T** resizeArray(T** arr, int& currentSize, int newSize) {
    T** newArr = new T*[newSize];
    for (int i = 0; i < currentSize; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    currentSize = newSize;
    return newArr;
}

int main()
{
    int custCapacity = 10;
    int drivCapacity = 10;
    int ordCapacity = 10;
    int custCount = 0;
    int drivCount = 0;
    int ordCount = 0;
    customer** customers = new customer*[custCapacity];
    delivery_driver** drivers = new delivery_driver*[drivCapacity];
    order** orders = new order*[ordCapacity];
    int choice;
    do{
        cout << "|                        ELMENUS MANAGEMENT SYSTEM v1.0                   |\n";
        cout << "--------------------------------------------------------------------------\n";
        cout << "|                              USER MANAGEMENT                            |\n";
        cout << "--------------------------------------------------------------------------\n";
        cout << "--------------------------------------------------------------------------\n";
        cout << "|  1. Register New Customer                                               |\n";
        cout << "|  2. Register New Delivery Driver                                        |\n";
        cout << "--------------------------------------------------------------------------\n";
        cout << "--------------------------------------------------------------------------\n";
        cout << "|                              ORDER MANAGEMENT                          |\n";
        cout << "--------------------------------------------------------------------------\n";
        cout << "|  3. Create New Order                                                   |\n";
        cout << "|  4. Add Items to Order                                                 |\n";
        cout << "|  5. Assign Driver to Order                                             |\n";
        cout << "|  6. Update Order Status                                                |\n";
        cout << "|  7. Display Order Details                                              |\n";
        cout << "--------------------------------------------------------------------------\n";
        cout << "|                           INFORMATION & REPORTS                        |\n";
        cout << "--------------------------------------------------------------------------\n";
        cout << "|  8. Display Customer Information                                       |\n";
        cout << "|  9. Display Driver Information                                         |\n";
        cout << "|  10. Compare Two Orders by Total                                        |\n";
        cout << "|  11. Display System Statistics                                          |\n";
        cout << "--------------------------------------------------------------------------\n";
        cout << "|                             FILE OPERATIONS                            |\n";
        cout << "--------------------------------------------------------------------------\n";
        cout << "| 12. Save Completed Orders to File                                      |\n";
        cout << "| 13. Save Driver Statistics to File                                     |\n";
        cout << "--------------------------------------------------------------------------\n";
        cout << "| 14. Exit System                                                        |\n";
        cout << "--------------------------------------------------------------------------\n";
        cin >> choice ;
        if (!cin)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore();
        switch (choice) {
            case 1 : {
                string a;string b;string c;string d ;
                cout << "Please enter your info:"<< endl
                << "ID :" ;
                getline(cin,a);
                cout << "Name :";
                getline(cin,b);
                cout << "Phone number :";
                getline(cin,c);
                cout << "Address :";
                getline(cin,d);


                if (custCount >= custCapacity) {
                    custCapacity *= 2;
                    customers = (customer**)resizeArray(customers, custCapacity, custCapacity);
                }

                customers[custCount] = new customer(a,b, c, d);
                custCount++;
            }
                break;

            case 2 : {
                string a ; string b ; string c ; string v ;
                cout << "Please enter your info:"<< endl
                << "ID :" ;
                getline(cin,a);
                cout << "Name :";
                getline(cin,b);
                cout << "Phone number :";
                getline(cin,c);
                cout << "vehicleType :";
                getline(cin,v);


                if (drivCount >= drivCapacity) {
                    drivCapacity *= 2;
                    drivers = (delivery_driver**)resizeArray(drivers, drivCapacity, drivCapacity);
                }

                drivers[drivCount] = new delivery_driver(a,b, c, v);
                drivCount++;
                cout << "driver added"<< endl;
            }
                break;

            case 3 : {
                string temp,id;
                cout << "please enter your customer's id :" ; getline(cin,temp);
                cout << "create your order's id :";getline(cin,id);
                customer** cust = findcust(customers, custCount, temp);
                if (cust != nullptr) {

                    if (ordCount >= ordCapacity) {
                        ordCapacity *= 2;
                        orders = (order**)resizeArray(orders, ordCapacity, ordCapacity);
                    }

                    orders[ordCount] = new order(**cust,id);
                    ordCount++;
                    **cust++;
                    cout << "alf alf mabrook el order etkariet"<< endl;
                }
                else {
                    cout << "there was an error try again" <<endl;
                }
            }
                break;

            case 4 : {
                string orderId; string itemName ; int price; int qty; int cap;
                cout << "Please enter your order's id :"; getline(cin,orderId);
                order** orderPtr = findorder(orders, ordCount, orderId);
                if (orderPtr != nullptr) {
                    cout << "Please enter your item's name :"; getline(cin,itemName);
                    cout << "Please enter your price :"; cin >> price;
                    cout << "Please enter your qty :"; cin >> qty;
                    fooditem newItem(itemName,price,qty);
                    (*orderPtr)->additem(newItem);
                    cout << "item added" << endl;
                }
                else {
                    cout << "Order not found" <<endl;
                }
            }
                break;

            case 5 : {
                string driverId; string orderId;
                cout << "Please enter your driver's id :"; getline(cin,driverId);
                cout << "please enter your order's id :"; getline(cin,orderId);
                order** orderPtr = findorder(orders, ordCount, orderId);
                delivery_driver** drv = findDriver(drivers, drivCount, driverId);
                if (orderPtr && drv) {
                    (*orderPtr)->assignDriver(*drv);
                    cout << "driver assigned" << endl;
                }
                else {
                    cout << "order or driver not found" << endl;
                }
            }
                break;

            case 6 : {
                string orderId; int statusChoice;
                cout << "Please enter your order's id :"; getline(cin,orderId);
                order** orderPtr = findorder(orders, ordCount, orderId);
                if (orderPtr) {
                    cout << "0-PENDING 1-PREPARING 2-OUT_FOR_DELIVERY 3-DELIVERED 4-CANCELED"<< endl;
                    cin >> statusChoice;
                    if (statusChoice >= 0 && statusChoice <= 4){
                        (*orderPtr)->updateStatus(static_cast<OrderStatus>(statusChoice));
                    }
                    else {
                        cout << "your choice is wrong" <<endl;
                    }
                }
                else {
                    cout << "order not found" <<endl;
                }
            }
                break;

            case 7 : {
                string orderid;
                cout << "please enter your order's id :"; getline(cin,orderid);
                order** orderPtr = findorder(orders, ordCount, orderid);
                if (orderPtr) {
                    (*orderPtr)->displayOrder();
                }
                else {
                    cout << "order not found" <<endl;
                }
            }
                break;

            case 8 : {
                string customerId;
                cout << "please enter your customer's id :"; getline(cin,customerId);
                customer** cust = findcust(customers, custCount, customerId);
                if (cust != nullptr) {
                    (*cust)->display();
                }
                else {
                    cout << "customer not found" <<endl;
                }
            }
                break;

            case 9 : {
                string driverId;
                cout << "please enter your driver's id :"; getline(cin,driverId);
                delivery_driver** drv = findDriver(drivers, drivCount, driverId);
                if (drv != nullptr) {
                    (*drv)->display();
                }
                else {
                    cout << "driver not found" <<endl;
                }
            }
                break;

            case 10 : {
                string id1; string id2;
                cout << "please enter order1 id :"; getline(cin,id1);
                cout << "please enter order2 id :"; getline(cin,id2);
                order** od1 = findorder(orders, ordCount, id1);
                order** od2 = findorder(orders, ordCount, id2);
                if (od1 && od2) {
                    if (*od1 > *od2) {
                        cout << "order " << id1 << " is bigger than " << "order " << id2 << endl;
                    }
                    else {
                        cout << "order " << id2 << " is bigger than or equal to " << "order " << id1 << endl;
                    }
                }
            }
                break;

            case 11 : {
                cout << "total users :" << user::get_total_user() << endl;
                cout << "total orders : " << ordCount <<endl ;
            }
                break;

            case 12 : {
                saveCompletedOrders(orders, ordCount);
                break;
            }

            case 13 : {
                saveDriverStats(drivers, drivCount);
                break;
            }

            default: {
                cout << "wrong choice\n";
                break;
            }
        }
    } while (choice<14 && choice>0 );


    for (int i = 0; i < custCount; i++) {
        delete customers[i];
    }
    delete[] customers;

    for (int i = 0; i < drivCount; i++) {
        delete drivers[i];
    }
    delete[] drivers;

    for (int i = 0; i < ordCount; i++) {
        delete orders[i];
    }
    delete[] orders;

    cout << "BYE";
    return 0 ;
}




















