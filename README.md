🛒 Grocery Store Inventory & Sales Management System (C Project)
This is a console-based C application for managing a small-scale grocery store's operations, including inventory management, sales processing, stock tracking, and reporting. It is designed with a modular structure and features role-based access for admin and cashier users.

🔧 Features
👤 User Authentication
Admin Login: Username: admin, Password: 240221677

Cashier Login: Username: cashier, Password: cash

Maximum 3 login attempts allowed.

📦 Inventory Management (Admin)
Add, update, remove, and view items.

Items include ID, name, category, price, stock level, and reorder threshold.

Inventory is saved to and loaded from inventory.txt.

💰 Sales Handling (Cashier)
Process sales with item selection and quantity.

Automatic stock updates after each sale.

Generates a receipt (receipt.txt) showing item-wise bill and total.

📉 Reporting & Stock Management
Generate a complete sales report from receipt.txt.

Identify items that are low in stock compared to their reorder levels.

Restock inventory for selected items.


| File Name     | Purpose                                   |
| ------------- | ----------------------------------------- |
| `main.c`      | Entry point; handles user login and menus |
| `auth.c`      | Handles user authentication               |
| `inventory.c` | Manages inventory CRUD and file I/O       |
| `sales.c`     | Manages sales transactions and receipts   |
| `reporting.c` | Displays sales report                     |
| `stock.c`     | Handles stock alerts and restocking       |
