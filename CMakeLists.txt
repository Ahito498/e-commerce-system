cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        main.cpp
        Product/DigitalProduct.h
        Product/Product.h
        Product/ShippableProduct.cpp
        Product/Product.cpp
        Customer/CartItem.h
        Admin/Admin.h
        Admin/Complaint.h
        Order/OrderStorage.h
        iv/InputValidator.h
        iv/InputValidator.cpp
        main.cpp
        Admin/Admin.cpp
        Product/DigitalProduct.cpp
        Admin/Complaint.cpp
        Product/ProductStorage.h
        Product/ProductStorage.cpp
        Customer/Customer.h
        Customer/Customer.cpp
        Customer/CustomerStorage.h
        Customer/CustomerStorage.cpp
        Shipping/ShippingService.cpp
        Customer/CartItem.cpp
        Customer/Cart.h
        Customer/Cart.cpp
        Order/OrderStorage.cpp)
