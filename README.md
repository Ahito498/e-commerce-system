# E-Commerce System (C++ Console Application)

A modern console-based e-commerce platform built with C++ for efficient and fast performance.

## Features

- 🛍️ Product catalog with search and filtering
- 🛒 Shopping cart functionality
- 👤 User authentication and profiles
- 💳 Secure payment processing simulation
- 📊 Admin dashboard for product management
- 🔍 Advanced search and filtering
- 📱 Clean console-based user interface

## Tech Stack

### Core Technologies
- **C++17/20** - Modern C++ with advanced features
- **Standard Template Library (STL)** - For data structures and algorithms
- **File I/O** - For data persistence
- **Console UI** - Clean and intuitive interface

### Libraries Used
- `<iostream>` - Console input/output
- `<vector>` - Dynamic arrays for products and users
- `<map>` - Key-value storage for efficient lookups
- `<string>` - String manipulation
- `<fstream>` - File operations for data persistence
- `<algorithm>` - Sorting and searching algorithms
- `<chrono>` - Time-based operations
- `<random>` - For generating IDs and random data

## Project Structure

```
e-commerce-cpp/
├── src/                 # Source files
│   ├── main.cpp        # Entry point
│   ├── Product.cpp     # Product class implementation
│   ├── User.cpp        # User class implementation
│   ├── Cart.cpp        # Shopping cart functionality
│   ├── Admin.cpp       # Admin operations
│   └── Utils.cpp       # Utility functions
├── include/            # Header files
│   ├── Product.h       # Product class definition
│   ├── User.h          # User class definition
│   ├── Cart.h          # Cart class definition
│   ├── Admin.h         # Admin class definition
│   └── Utils.h         # Utility function declarations
├── data/               # Data files
│   ├── products.txt    # Product database
│   ├── users.txt       # User database
│   └── orders.txt      # Order history
├── docs/               # Documentation
└── tests/              # Unit tests
```

## Getting Started

### Prerequisites
- **C++ Compiler** (GCC 7+, Clang 6+, or MSVC 2017+)
- **Make** or **CMake** for building
- **Git** for version control

### Installation

1. Clone the repository:
```bash
git clone https://github.com/Ahito498/e-commerce-system.git
cd e-commerce-system
```

2. Build the project:
```bash
# Using Make
make

# Or using CMake
mkdir build && cd build
cmake ..
make
```

3. Run the application:
```bash
./ecommerce
```

## Features Overview

### User Features
- **Registration & Login**: Secure user account management
- **Product Browsing**: View all available products with details
- **Search & Filter**: Find products by name, category, or price range
- **Shopping Cart**: Add/remove items, view cart, checkout
- **Order History**: View past orders and their status

### Admin Features
- **Product Management**: Add, edit, delete products
- **User Management**: View and manage user accounts
- **Order Management**: Process and track orders
- **Sales Reports**: View sales statistics and analytics

### Technical Features
- **Data Persistence**: All data saved to text files
- **Input Validation**: Robust error handling and validation
- **Clean UI**: Well-organized console interface
- **Modular Design**: Easy to extend and maintain

## Development

### Building from Source
```bash
# Debug build
make debug

# Release build
make release

# Clean build
make clean
```

### Running Tests
```bash
make test
```

## Contributing

1. Fork the repository
2. Create a feature branch: `git checkout -b feature-name`
3. Commit your changes: `git commit -m 'Add feature'`
4. Push to the branch: `git push origin feature-name`
5. Submit a pull request

## Code Style

- Follow C++ Core Guidelines
- Use meaningful variable and function names
- Add comments for complex logic
- Keep functions small and focused
- Use const correctness where appropriate

## License

This project is licensed under the MIT License. 