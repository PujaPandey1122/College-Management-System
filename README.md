# College Management System

A menu-driven College Management System developed in C++ to demonstrate Object-Oriented Programming and fundamental data structures.

## Features

- Student Management
  - Add student
  - Display students
  - Search student
  - Delete student

- Teacher Management
  - Add teacher
  - Display teachers
  - Search teacher
  - Delete teacher

- Course Management
  - Add course
  - Display courses
  - Search course
  - Delete course

- Attendance Management
  - Mark students present or absent
  - View attendance records
  - Calculate attendance percentage

- File Handling
  - Basic saving and loading of data using text files

## Concepts Used

- C++
- Object-Oriented Programming
- Classes and Objects
- Encapsulation
- Inheritance
- Polymorphism
- Constructors and Destructors
- Exception Handling
- Dynamic Memory Management
- Arrays
- Singly Linked Lists
- Stack
- File Handling
- Menu-Driven Programming

## Data Structures

### Array

Arrays are used for attendance records and operation storage.

### Linked List

Linked lists are used to manage:

- Students
- Teachers
- Courses

### Stack

A simple stack is used to maintain recent operations using the LIFO principle.

## Project Structure

```text
College-Management-System/
│
├── include/
│   ├── Attendance.h
│   ├── CollegeManagementSystem.h
│   ├── Course.h
│   ├── CourseList.h
│   ├── FileManager.h
│   ├── Person.h
│   ├── Student.h
│   ├── StudentList.h
│   ├── Teacher.h
│   └── TeacherList.h
│
├── src/
│   ├── Attendance.cpp
│   ├── CollegeManagementSystem.cpp
│   ├── Course.cpp
│   ├── CourseList.cpp
│   ├── FileManager.cpp
│   ├── main.cpp
│   ├── Person.cpp
│   ├── Student.cpp
│   ├── StudentList.cpp
│   ├── Teacher.cpp
│   └── TeacherList.cpp
│
├── data/
│   └── college_data.txt
│
├── .gitignore
└── README.md