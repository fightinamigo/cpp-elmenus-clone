cmake_minimum_required(VERSION 3.20)
project(ASSIGNMENT2)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled1
        Elmenus.cpp
        fooditem.cpp
        fooditem.h
        user.cpp
        user.h
        customer.cpp
        customer.h
        delivery_driver.cpp
        delivery_driver.h
        order.cpp
        order.h
        OrderStatus.h
        UserType.h
)
