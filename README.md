# E-Commerce System

A modern, full-stack e-commerce platform built with React, Node.js, and MongoDB.

## Features

- 🛍️ Product catalog with search and filtering
- 🛒 Shopping cart functionality
- 👤 User authentication and profiles
- 💳 Secure payment processing
- 📱 Responsive design
- 🔍 Advanced search and filtering
- 📊 Admin dashboard for product management

## Tech Stack

### Frontend
- React 18
- TypeScript
- Tailwind CSS
- React Router
- Axios for API calls

### Backend
- Node.js
- Express.js
- MongoDB with Mongoose
- JWT for authentication
- bcrypt for password hashing

## Project Structure

```
e-commerce/
├── frontend/          # React frontend application
├── backend/           # Node.js backend API
├── shared/            # Shared types and utilities
└── docs/             # Documentation
```

## Getting Started

### Prerequisites
- Node.js (v18 or higher)
- MongoDB
- Git

### Installation

1. Clone the repository:
```bash
git clone <your-github-repo-url>
cd e-commerce
```

2. Install dependencies:
```bash
# Install backend dependencies
cd backend
npm install

# Install frontend dependencies
cd ../frontend
npm install
```

3. Set up environment variables:
```bash
# Backend (.env)
cp backend/.env.example backend/.env
# Edit the .env file with your configuration

# Frontend (.env)
cp frontend/.env.example frontend/.env
```

4. Start the development servers:
```bash
# Start backend (from backend directory)
npm run dev

# Start frontend (from frontend directory)
npm start
```

## Development

- Backend runs on: http://localhost:5000
- Frontend runs on: http://localhost:3000

## Contributing

1. Fork the repository
2. Create a feature branch: `git checkout -b feature-name`
3. Commit your changes: `git commit -m 'Add feature'`
4. Push to the branch: `git push origin feature-name`
5. Submit a pull request

## License

This project is licensed under the MIT License. 