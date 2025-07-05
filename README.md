# 🛍️ Console E‑Commerce System in C++

A C++ console application simulating a simple e-commerce flow with:

- **Admin & Customer** roles
- File-based **data persistence**
- **Cart, checkout, and shipping**
- **Order history** and **complaints** features

---

### 📁 Project Structure

```
/FawryTask
│
├─ Admin/                # Admin session logic (product management, complaints)
│   ├─ Admin.cpp
│   ├─ Admin.h
│   ├─ Complaint.cpp
│   └─ Complaint.h
├─ Customer/             # Customer auth, session, order history
│   ├─ Customer.cpp
│   ├─ Customer.h
│   ├─ Cart.cpp
│   ├─ Cart.h
│   ├─ CartItem.cpp
│   ├─ CartItem.h
│   ├─ CustomerStorage.cpp
│   └─ CustomerStorage.h
├─ Product/              # Product hierarchy & storage
│   ├─ Product.cpp
│   ├─ Product.h
│   ├─ DigitalProduct.cpp
│   ├─ DigitalProduct.h
│   ├─ ShippableProduct.cpp
│   ├─ ShippableProduct.h
│   ├─ ProductStorage.cpp
│   └─ ProductStorage.h
├─ Shipping/             # ShippingService
│   ├─ ShippingService.cpp
│   └─ ShippingService.h
├─ Order/                # OrderStorage
│   ├─ OrderStorage.cpp
│   └─ OrderStorage.h
├─ iv/                   # InputValidator
│   ├─ InputValidator.cpp
│   └─ InputValidator.h
├─ include/              # Additional header files
├─ Data/                 # Data files (.txt storage)
│   ├─ customers.txt
│   ├─ products.txt
│   ├─ orders.txt
│   └─ complaints.txt
├─ main.cpp              # Entry point & menu
├─ CMakeLists.txt        # Build configuration
└─ README.md             # Project documentation
```

---

### 🚀 Getting Started

#### Prerequisites

- C++20 compiler (e.g. GCC, Clang)
- CMake 3.15+

#### Build & Run

```bash
git clone https://github.com/Ahito498/e-commerce-system.git
cd e-commerce-system
mkdir build && cd build
cmake ..
make
./main
```

---

### ✅ Features

#### Admin Flow
- Login (password protected, 3 attempts)
- Add / Remove / Restock products
- Change price or apply discount
- Remove expired products
- View complaints

#### Customer Flow
- Sign-up / Login (username & password)
- Browse products (digital/shippable, expiry-aware)
- Add/remove items to/from cart
- Checkout:
  - Stock, expiry & balance validation
  - Subtotal, shipping, order summary
  - Balance deduction, order saved
- View personal order history

#### Utilities
- Input validation for all menus
- File-based persistence for customers, products, orders, complaints
- Shipping logs via ShippingService

---

### 📚 Sample Test Data

#### Data/customers.txt
```
ahmed123
pass123
500

sara_hasan
sara2024
750.5
```

#### Data/products.txt
```
shippable
Power Bank
350
10
0.8
2025-12-01

digital
Vodafone Recharge 50EGP
50
100
0
2026-05-01
```

#### Data/complaints.txt
```
ahmed123: Late product delivery.
sara_hasan: Item arrived expired.
```

#### Data/orders.txt
(Initially empty; populated after checkout.)

---

### 🧪 Testing

The project includes manual test cases in the `tests/` directory. Each test case is documented with:
- Preconditions
- Step-by-step instructions
- Expected results
- Screenshots (when applicable)

Test cases are located in:
- `tests/TC001_add_to_cart.md`
- `tests/TC002_checkout_insufficient_funds.md`
- `tests/screenshots/` - for test case screenshots

---

### 🧪 Console Test Cases

Below are comprehensive test cases captured from the actual console application:

#### **Test Case 1: Customer Login and Product Viewing**

**Scenario:** Customer login and initial product browsing

```
=============================
 Welcome to E-Commerce System
=============================
1. Admin Login
2. Customer Login
3. Customer Sign Up
4. Exit
Enter your choice: > 2
Enter your username: ahmed123
Enter your password: pass123
Login successful.
Username: ahmed123, Balance: 500

--- Customer Menu ---
1. View Products
2. Add Product to Cart
3. View Cart
4. Remove Item from Cart
5. Checkout
6. View Order History
0. Logout
> 1
No products available.
```

**Expected Result:** Customer successfully logs in and can view the menu, but no products are initially available.

---

#### **Test Case 2: Adding Products to Cart**

**Scenario:** Customer adds products to shopping cart

```
> 2
----- All Products -----
[1] Power Bank 10000mAh | Price: 350 | Quantity: 10
[2] Vodafone Recharge 50EGP | Price: 50 | Quantity: 100
[3] USB-C Charger | Price: 80 | Quantity: 20 | EXPIRED
[4] 200 | Price: 5 | Quantity: 0 | EXPIRED
Select product number to add: > 2
Enter quantity to add: > 30
Added to cart.
```

**Expected Result:** Product successfully added to cart with specified quantity.

---

#### **Test Case 3: Viewing Cart Contents**

**Scenario:** Customer views current cart contents

```
> 3
----- Your Cart -----
[1] Vodafone Recharge 50EGP | Price: 50 | Quantity: 30 | Subtotal: 1500
```

**Expected Result:** Cart displays all items with correct pricing and quantities.

---

#### **Test Case 4: Checkout with Insufficient Balance**

**Scenario:** Customer attempts checkout with insufficient funds

```
> 5
Subtotal: 1500
Shipping: 0
Total:    1500
Insufficient balance.
```

**Expected Result:** System correctly detects insufficient balance and prevents checkout.

---

#### **Test Case 5: Removing Items from Cart**

**Scenario:** Customer removes items from shopping cart

```
> 4
----- Your Cart -----
[1] Vodafone Recharge 50EGP | Price: 50 | Quantity: 30 | Subtotal: 1500
Enter item number to remove: > 1
Item removed.
```

**Expected Result:** Item successfully removed from cart.

---

#### **Test Case 6: Successful Checkout**

**Scenario:** Customer completes checkout with sufficient balance

```
> 2
----- All Products -----
[1] Power Bank 10000mAh | Price: 350 | Quantity: 10
[2] Vodafone Recharge 50EGP | Price: 50 | Quantity: 100
[3] USB-C Charger | Price: 80 | Quantity: 20 | EXPIRED
[4] 200 | Price: 5 | Quantity: 0 | EXPIRED
Select product number to add: > 2
Enter quantity to add: > 1
Added to cart.

> 5
Subtotal: 50
Shipping: 0
Total:    50

========== ORDER SUMMARY ==========
- Vodafone Recharge 50EGP | Quantity: 1 | Price: 50 | Subtotal: 50
-----------------------------------
Shipping: 0
Total Paid: 50
New Balance: 450
===================================

Order placed successfully.
```

**Expected Result:** Order successfully processed with correct balance deduction.

---

#### **Test Case 7: Viewing Updated Product List**

**Scenario:** Customer views products after successful purchase

```
> 1
----- Product List -----
[1] Digital Product - Power Bank 10000mAh, Price: 350, Quantity: 10, Expiry: 2025-12-01 (Instant Delivery)
[2] Digital Product - Vodafone Recharge 50EGP, Price: 50, Quantity: 99, Expiry: 2026-05-01 (Instant Delivery)
[3] Digital Product - USB-C Charger, Price: 80, Quantity: 20 (EXPIRED) (Instant Delivery)
[4] Digital Product - 200, Price: 5, Quantity: 0 (EXPIRED) (Instant Delivery)
```

**Expected Result:** Product quantities updated after purchase, expired products marked.

---

#### **Test Case 8: Viewing Order History**

**Scenario:** Customer views their order history

```
> 6

--- Order ---
Customer: ahmed123
Shipping: 0
Total: 50
-----------------------------
```

**Expected Result:** Order history displays correctly with customer details and order information.

---

#### **Test Case 9: Customer Logout**

**Scenario:** Customer logs out of the system

```
> 0
0
Logged out.
```

**Expected Result:** Customer successfully logged out and returned to main menu.

---

#### **Test Case 10: Admin Login with Multiple Attempts**

**Scenario:** Admin login with password validation

```
=============================
 Welcome to E-Commerce System
=============================
1. Admin Login
2. Customer Login
3. Customer Sign Up
4. Exit
Enter your choice: > 1
Enter admin password: admin1234
Invalid password. Attempts left: 2
Enter admin password: admin123
```

**Expected Result:** System correctly validates admin password with attempt counting.

---

#### **Test Case 11: Admin Product Management**

**Scenario:** Admin adds new product to the system

```
----------------------------
 Admin Menu
----------------------------
1. Add Product
2. Remove Product
3. Restock Product
4. Change Product Price
5. Apply Discount
6. Remove Expired Products
7. View Complaints
8. View All Products
9. Logout
Enter your choice: > 1
Enter product name: chips
Enter price: > 2
Enter quantity: > 100
Is the product shippable?
1. Yes
2. No (Digital Product)
> 1
Enter product weight (kg): > 0.2
Does the product have an expiry date?
1. Yes
2. No
> 1
Enter expiry date (YYYY-MM-DD): 2025-11-18
Product added successfully.
```

**Expected Result:** New product successfully added with all required details.

---

#### **Test Case 12: Admin Viewing All Products**

**Scenario:** Admin views complete product inventory

```
> 8
----- Product List -----
[1] Digital Product - Power Bank 10000mAh, Price: 350, Quantity: 10, Expiry: 2025-12-01 (Instant Delivery)
[2] Digital Product - Vodafone Recharge 50EGP, Price: 50, Quantity: 100, Expiry: 2026-05-01 (Instant Delivery)
[3] Digital Product - USB-C Charger, Price: 80, Quantity: 20 (EXPIRED) (Instant Delivery)
[4] Digital Product - 200, Price: 5, Quantity: 0 (EXPIRED) (Instant Delivery)
[5] Shippable Product - chips, Price: 2, Quantity: 100, Weight: 0.2kg, Expiry: 2025-11-18
```

**Expected Result:** Complete product list displayed with all details including newly added products.

---

#### **Test Case 13: Input Validation**

**Scenario:** System handles invalid input gracefully

```
Enter your choice: > Input out of range. Must be between 1 and 4.
```

**Expected Result:** System provides clear error message for invalid input.

---

#### **Test Case 14: Admin Logout**

**Scenario:** Admin logs out of the system

```
> 9
Logging out...
```

**Expected Result:** Admin successfully logged out and returned to main menu.

---

#### **Test Case 15: System Exit**

**Scenario:** User exits the application

```
=============================
 Welcome to E-Commerce System
=============================
1. Admin Login
2. Customer Login
3. Customer Sign Up
4. Exit
Enter your choice: > 4
Exiting the program.

Process finished with exit code 0
```

**Expected Result:** Application exits cleanly with proper termination message.

---

### 🧼 Development Checklist

#### ✅ Completed
- ✅ Project structure created with all directories
- ✅ Basic main.cpp with menu system implemented
- ✅ Sample data files created (customers.txt, products.txt, complaints.txt, orders.txt)
- ✅ CMakeLists.txt configured for C++20
- ✅ .gitignore file created
- ✅ README.md documentation complete
- ✅ Test case structure created

#### 🔄 In Progress
- ⏳ Implement proper class structure (Product, User, Cart, Admin)
- ⏳ Replace placeholder functions with actual functionality
- ⏳ Add file I/O for data persistence
- ⏳ Implement authentication system
- ⏳ Add shopping cart functionality
- ⏳ Create admin management features

#### 📋 TODO
- [ ] Implement Product class hierarchy (DigitalProduct, ShippableProduct)
- [ ] Implement User/Customer authentication system
- [ ] Implement Cart and CartItem classes
- [ ] Implement Admin management features
- [ ] Add input validation and error handling
- [ ] Implement file-based data persistence
- [ ] Add order processing and history
- [ ] Implement shipping service
- [ ] Add comprehensive test cases
- [ ] Add unit tests with GoogleTest
- [ ] Set up CI/CD with GitHub Actions

#### 🚨 Issues to Fix
- [ ] Remove hardcoded credentials from main.cpp
- [ ] Replace global variables with proper class instances
- [ ] Add proper error handling for file operations
- [ ] Implement proper authentication instead of hardcoded checks
- [ ] Add input validation for all user inputs
- [ ] Replace "coming soon" messages with actual functionality

---

### ⏭ What's Next?

- Add unit tests (e.g., GoogleTest)
- Enable CI via GitHub Actions
- Add support for product search/filtering
- Implement advanced features like discounts and promotions

---

### 🤝 Contributing

1. Fork the repository
2. Create a feature branch: `git checkout -b feature-name`
3. Commit your changes: `git commit -m 'Add feature'`
4. Push to the branch: `git push origin feature-name`
5. Submit a pull request

### 📞 Support

For questions or issues, please open an issue on GitHub. 