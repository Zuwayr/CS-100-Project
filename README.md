# CS-100-Project
Inventory Management System that I made as the final project for CS 100 at LUMS

Problem Description:
The task was to create an inventory system. This inventory system should be able to provide a database for a stock holding. It should manage the stock and its attributes such as name, price and quantity. Furthermore, the system should provide manipulative features such as adding and removing items to and from the inventory. A fundamental part of the system is easy data retrieval, which would allow the user to easily search through the inventory using any attribute. The program should be designed in such a way that it retains data even after exiting the program. 

Problem Handling:
The problem was solved by the use of structures and file input/output functions. The inventory is kept saved in a text file named “inventory.txt”. When the program is run, it automatically copies the data from the text file to an internally managed vector “vec” of self defined structure “item”. The structure item handles the item’s name, price, quantity and serial. The program has add and delete functions which add and delete item to and from the vector respectively. The program also has modify function which allows the user to change any attribute of any stored item. The search function, handles four way searches, allowing user to find any stored item. Some functions allow for recursion so that the user can do multiple transactions of the same type quickly. The list of stored items is displayed with another function to neatly produce data on the output screen. The program features validation checks on user entered data and produces errors to help user understand the problem. After the user is done with the program, upon exiting, the program writes the vector of items back to the inventory text file in a manner that is readable by the program later. The program also features a login system to prevent unauthorized access. 

DEFAULT PASSWORD IS “letmein”

Further Improvements:
Currently, the program relies on spaces to read and save files so it does not save names with spaces in them. A user friendly graphical user interface would greatly add to the ease of use and appeal of the program. Another improvement would be to allow the user to add new attributes to the predefined structure. A more refined output scheme like in a spreadsheet program would allow the user to access data easily. An encrypted text file would ensure data security. A smart login system that allows certain actions to the user would also be very useful.
