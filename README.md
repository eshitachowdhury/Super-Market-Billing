# Super-Market-Billing
Supermarket Billing System
A C++ console-based application that simulates a supermarket checkout system. It allows users to add items, calculate totals, and print a formatted bill — with file-based item storage. Built using object-oriented programming and file handling.

Features:
Add items with name, rate, and quantity

Store and retrieve item data using a .txt file (Bill.txt)

Print a formatted bill with itemized pricing and quantities

Persistent item storage even after program closes

Menu-based user interaction

Print Bill Feature:
Reads all saved items from Bill.txt

Displays item name, rate, quantity, and total price for each item

Calculates and displays the grand total of the bill

Formats the output like a real receipt

Example:

markdown
Copy
Edit
------------ BILL ------------
Item        Rate    Quantity    Total
-------------------------------------
Apple        50         2        100
Bread        30         1         30
-------------------------------------
Total Amount: 130
-------------------------------
Technologies Used:
Language: C++

Concepts: File Handling, Classes & Objects, Loops, Conditionals

Environment: Code::Blocks / Dev C++ / Turbo C++

File Structure:

supermarket-billing-system/
├── supermarket.cpp       # Main C++ source file
├── Bill.txt              # File used to store item data
└── README.md             # Project documentation
How to Run:
Clone or download the repo.

Open supermarket.cpp in your preferred C++ IDE.

Compile and run the program.

Use the menu to:

Add items

Print the bill (from stored items)

Exit the system

Make sure Bill.txt is in the same folder as the .exe or .cpp. It will be created if it doesn't exist.

Notes:
Fully console-based — no GUI.

Ideal for learning file handling and OOP in C++.

You can expand it with features like:

Item deletion/editing

Tax or discount calculation

Unique bill ID generation

Author:
Eshita Chowdhury
