# Birthday Lookup System using Binary Search Tree (BST)

This program implements a Birthday Lookup System using a binary search tree data structure in C++. It allows users to add, list, and look up birthdays, as well as save and load entries from a file.


#### **Here's an overview of the code structure and its functionality:**

1. `a4_birthdaylib.hpp`:
   * Defines the `Birthday` struct that represents a single birthday entry.
   * Provides function declarations for creating, deleting, and printing birthday entries.
2. `a4_birthdayBST.hpp`:
   * Includes the necessary header files and namespaces.
   * Defines the `BirthdayBSTreeNode` struct, which represents a node in the BST.
   * Defines the `BirthdayBST` class, which represents the binary search tree.
   * Declares private member variables and helper functions for the BST operations.
   * Declares public member functions for inserting, removing, finding, and printing nodes in the BST.
3. `a4_birthdayBST.cpp`:
   * Implements the member functions of the `BirthdayBST` class declared in `a4_birthdayBST.hpp`.
   * Provides the actual logic for inserting, removing, finding, and printing nodes in the BST.
   * Includes helper functions such as `newNode`, `minSuccessor`, and recursive functions for tree traversal.
4. `main()` function:
   * The entry point of the program.
   * Creates an instance of the `BirthdayBST` class and initializes it as the root of the BST.
   * Displays a menu to the user and accepts their input to perform different operations.
   * Uses a loop to continuously prompt the user for input until they choose to terminate the program.
   * Calls the appropriate member functions of the `BirthdayBST` class based on the user's input.



## Features

- Add Birthday: Users can add new birthday entries by providing the year, month, day, name, and known for a birthday. The program stores the entries in a binary search tree for efficient retrieval.
- List Birthdays: The program displays all the stored birthdays in ascending order of their month and day, allowing users to see the upcoming birthdays.
- Lookup Birthday: Users can search for birthdays matching a specific month and day. The program finds and prints the matching entries stored in the binary search tree.
- Save Entries: Users can save all the birthday entries to a file by specifying a filename. This feature enables the preservation of data between program executions.
- Load Entries: Users can load birthday entries from a file into the binary search tree. This functionality allows the program to start with pre-existing data.
- Quit Program: Users can terminate the program at any time.

## Skills Demonstrated

- Data Structures: The program utilizes a binary search tree (BST) to efficiently store and retrieve birthday entries. It demonstrates proficiency in implementing BST operations such as insertion, removal, and searching.
- File Handling: The program showcases the ability to read from and write to files in C++. Users can save and load birthday entries to/from external files, ensuring data persistence.
- User Interaction: The program provides a user-friendly interface that prompts for input and provides clear instructions. Users can easily navigate through the available options and interact with the system.
- Error Handling: The program includes error handling mechanisms to address potential issues, such as detecting and preventing duplicate entries or handling file not found situations.
- Algorithms and Logic: The program demonstrates the ability to design and implement algorithms for key operations in a BST, including inserting, removing, and finding nodes. It showcases problem-solving skills and logical thinking.

## Usage

To run the Birthday Lookup System, follow these steps:

1. Compile the source code using a C++ compiler. For example:
2. Run the compiled executable:
3. Follow the on-screen instructions to navigate through the system and perform operations such as adding birthdays, listing birthdays, looking up birthdays, saving entries, and loading entries.

## Contributing

Contributions to the Birthday Lookup System are welcome. If you encounter any bugs or have suggestions for improvements, please submit an issue or a pull request.
