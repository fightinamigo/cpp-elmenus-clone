# 🍔 Elmenus Clone — C++ Food Delivery System

A fully functional food delivery management system built in C++ using Object-Oriented Programming principles. Inspired by Egypt's popular food ordering platform [Elmenus](https://www.elmenus.com), this project simulates the core backend logic of a real delivery platform.

> Built as part of a university OOP course assignment.  
> **Authors:** Omar Rashad (fightinamigo) & Amr Zaki (amrzaki274)

---

## 🚀 Features

- Register customers and delivery drivers
- Create and manage orders with dynamic item lists
- Assign drivers to orders
- Track order status (Pending → Preparing → Out for Delivery → Delivered → Canceled)
- Loyalty points system for customers
- Driver earnings tracker (15% commission per order)
- Save completed orders and driver statistics to `.txt` files
- Compare orders, display system statistics

---

## 🏗️ System Architecture

```
User (Abstract Base)
├── Customer     → loyalty points, delivery address
└── DeliveryDriver → vehicle type, earnings, completed deliveries

Order            → links Customer + DeliveryDriver + FoodItems[]
FoodItem         → name, price, quantity
```

---

## 💡 OOP Concepts Demonstrated

| Concept | Where Used |
|---|---|
| Inheritance | `Customer`, `DeliveryDriver` extend `User` |
| Polymorphism | `display()`, `calculate_Earnings()` overridden in subclasses |
| Abstract Classes | `User` has pure virtual methods |
| Operator Overloading | `+=`, `++`, `[]`, `<<`, `>>`, `>` |
| Dynamic Memory | `new`/`delete` with proper Rule of Three |
| Templates | `resizeArray<T>()` for dynamic capacity growth |
| File I/O | Saving reports to `completed_orders.txt`, `driver_stats.txt` |
| Static Members | `totalOrders`, `total_users` counters |
| Enums | `OrderStatus`, `UserType` |

---

## 🖥️ Menu Options

```
1.  Register New Customer
2.  Register New Delivery Driver
3.  Create New Order
4.  Add Items to Order
5.  Assign Driver to Order
6.  Update Order Status
7.  Display Order Details
8.  Display Customer Information
9.  Display Driver Information
10. Compare Two Orders
11. Display System Statistics
12. Save Completed Orders to File
13. Save Driver Statistics to File
14. Exit
```

---

## 🛠️ Build & Run

**Requirements:** C++20, CMake 4.0+, CLion or any C++ compiler

```bash
git clone https://github.com/YOUR_USERNAME/cpp-elmenus-clone
cd cpp-elmenus-clone
mkdir build && cd build
cmake ..
make
./Elmenus
```

---

## 📁 Project Structure

```
├── main.cpp / Elmenus.cpp   # Entry point & menu system
├── user.h / user.cpp        # Abstract base class
├── customer.h / customer.cpp
├── delivery_driver.h / delivery_driver.cpp
├── order.h / order.cpp
├── fooditem.h / fooditem.cpp
├── OrderStatus.h            # Enum
├── UserType.h               # Enum
└── CMakeLists.txt
```

---

## 📌 Notes

- Dynamic array resizing ensures the system scales with more users/orders
- Pointer-based relationships between `Order`, `Customer`, and `DeliveryDriver` simulate real database foreign keys
- File output enables basic persistence across sessions
