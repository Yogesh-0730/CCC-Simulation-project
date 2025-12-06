Student Management System (C Program)

This is a simple Student Management System implemented in C using a singly linked list.
It allows you to:

Add a new student

Display all students

Search a student by roll number

Delete a student

Exit the program

🚀 Features
1. Add Student

Takes roll number, name, and marks as input.

Adds the student to the end of the linked list.

2. Display Students

Prints all students in a formatted table.

3. Search Student

Searches using roll number.

Displays student details if found.

4. Delete Student

Deletes a student node from the linked list using roll number.

5. Exit

Exits the program safely.

🛠️ Technologies Used

C Language

Linked List Data Structure

Dynamic Memory Allocation (malloc)

📌 How to Compile and Run
For GCC users:
gcc main.c -o sms
./sms

For Windows (MinGW):
gcc main.c -o sms.exe
sms.exe

📂 File Structure
.
├── main.c      # Contains the full Student Management System code
└── README.md   # Documentation

📖 Program Flow
===== STUDENT MANAGEMENT SYSTEM =====
1. Add Student
2. Display Students
3. Search Student
4. Delete Student
5. Exit
Enter your choice:

🔗 Linked List Structure Used

Each student node contains:

struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student *next;
};

✔️ Example Output
Enter Roll Number: 101
Enter Name: John
Enter Marks: 85.5
Student added successfully!

Roll   Name   Marks
-----------------------
101    John   85.50

📜 License

This project is free to use, modify, and distribute.
