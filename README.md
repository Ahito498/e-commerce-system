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
├─ admin/               # Admin session logic (product management, complaints)
├─ cart/                # CartItem, Cart implementation
├─ customer/            # Customer auth, session, order history
├─ products/            # Product hierarchy & storage
├─ shipping/            # ShippingService
├─ orders/              # OrderStorage
├─ io/                  # InputValidator, ConsolePrinter
├─ data/                # SQLite-like .txt storage files
│   ├ customers.txt
│   ├ products.txt
│   ├ orders.txt
│   └ complaints.txt
├─ tests/               # Test case documentation
│   ├ TC001_add_to_cart.md
│   ├ TC002_checkout_insufficient_funds.md
│   └ screenshots/      # Screenshots for test cases
├─ main.cpp             # Entry point & menu
└─ README.md            # Project documentation
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

#### data/customers.txt
```
ahmed123
pass123
500

sara_hasan
sara2024
750.5
```

#### data/products.txt
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

#### data/complaints.txt
```
ahmed123: Late product delivery.
sara_hasan: Item arrived expired.
```

#### data/orders.txt
(Initially empty; populated after checkout.)

---

### 🧪 Test Cases

Place your manual test scenarios (as .md files) under a `/tests/` folder, like so:

```
tests/
  TC001_add_to_cart.md
  TC002_checkout_insufficient_funds.md
  screenshots/
    TC001_screenshot1.png
    TC002_screenshot1.png
```

Each test case file should include:

```markdown
# TC001: Add to Cart – Valid Product

**Precondition:** Logged in as `ahmed123`  
**Steps:**  
1. Go to "Add Product to Cart"  
2. Choose product #1  
3. Add quantity 2  

**Expected:**  
- Product added successfully  
- Cart lists item with correct quantity

**Screenshot:** `screenshots/TC001_screenshot1.png`
```

GitHub will display these for testers. You can also import them into TestRail or GitHub Issues/Projects if desired. These files should be committed alongside your code—they document your project's test coverage.

---

### 🧼 Cleanup Checklist (Pre-Publish)
- ✅ Ensure all .txt files exist in data/
- ✅ Remove any absolute paths (use relative data/)
- ✅ No auto types — all loops explicit
- ✅ No temporary/test stubs in main()
- ✅ Confirm README + .gitignore are present

---

### ⏭ What's Next?
- Add unit tests (e.g., GoogleTest)
- Enable CI via GitHub Actions
- Add support for product search/filtering

---

### 📄 License

This project is licensed under the MIT License.

---

### 📌 Where to Upload Test Cases?
- Create a `tests/` folder at the repo root.
- Add `.md` files for each test scenario.
- Include a note in README linking to them.
- CI workflows can later run these as manual checks.

### 📸 Screenshots Location
- Place all test case screenshots in `tests/screenshots/`
- Reference them in your test case `.md` files
- Use descriptive names like `TC001_login_success.png` 