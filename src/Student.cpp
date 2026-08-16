#include "../include/Student.h"
#include <iostream>

Student::Student(int id,
                 const std::string& name,
                 const std::string& email,
                 const std::string& course,
                 int semester)
    : Person(id, name, email),
      course(course),
      semester(semester) {
}

void Student::display() const {
    std::cout << "Student ID: " << id << '\n';
    std::cout << "Name: " << name << '\n';
    std::cout << "Email: " << email << '\n';
    std::cout << "Course: " << course << '\n';
    std::cout << "Semester: " << semester << '\n';
}