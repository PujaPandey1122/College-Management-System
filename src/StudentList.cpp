
#include "../include/StudentList.h"
#include <iostream>

StudentList::Node::Node(const Student& student)
    : student(student), next(nullptr) {
}

StudentList::StudentList()
    : head(nullptr) {
}

StudentList::~StudentList() {
    clear();
}

void StudentList::addStudent(const Student& student) {
    if (searchStudent(student.getId())) {
        throw std::invalid_argument("Student ID already exists.");
    }

    Node* newNode = new Node(student);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}

void StudentList::displayStudents() const {
    if (head == nullptr) {
        std::cout << "No students available.\n";
        return;
    }

    Node* current = head;

    while (current != nullptr) {
        current->student.display();
        std::cout << "-------------------------\n";
        current = current->next;
    }
}

bool StudentList::searchStudent(int studentId) const {
    Node* current = head;

    while (current != nullptr) {
        if (current->student.getId() == studentId) {
            return true;
        }

        current = current->next;
    }

    return false;
}

bool StudentList::deleteStudent(int studentId) {
    if (head == nullptr) {
        return false;
    }

    if (head->student.getId() == studentId) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;

    while (current->next != nullptr) {
        if (current->next->student.getId() == studentId) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }

        current = current->next;
    }

    return false;
}

void StudentList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}