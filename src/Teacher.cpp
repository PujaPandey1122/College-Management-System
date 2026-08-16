#include "../include/Teacher.h"
#include <iostream>

Teacher::Teacher(int id,
                 const std::string& name,
                 const std::string& email,
                 const std::string& department,
                 const std::string& specialization)
    : Person(id, name, email),
      department(department),
      specialization(specialization) {
}

void Teacher::display() const {
    std::cout << "Teacher ID: " << id << '\n';
    std::cout << "Name: " << name << '\n';
    std::cout << "Email: " << email << '\n';
    std::cout << "Department: " << department << '\n';
    std::cout << "Specialization: " << specialization << '\n';
}