#include "../include/TeacherList.h"
#include <iostream>

TeacherList::Node::Node(const Teacher& teacher)
    : teacher(teacher), next(nullptr) {
}

TeacherList::TeacherList()
    : head(nullptr) {
}

TeacherList::~TeacherList() {
    clear();
}

void TeacherList::addTeacher(const Teacher& teacher) {
    if (searchTeacher(teacher.getId())) {
        throw std::invalid_argument("Teacher ID already exists.");
    }

    Node* newNode = new Node(teacher);

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

void TeacherList::displayTeachers() const {
    if (head == nullptr) {
        std::cout << "No teachers available.\n";
        return;
    }

    Node* current = head;

    while (current != nullptr) {
        current->teacher.display();
        std::cout << "-------------------------\n";
        current = current->next;
    }
}

bool TeacherList::searchTeacher(int teacherId) const {
    Node* current = head;

    while (current != nullptr) {
        if (current->teacher.getId() == teacherId) {
            return true;
        }

        current = current->next;
    }

    return false;
}

bool TeacherList::deleteTeacher(int teacherId) {
    if (head == nullptr) {
        return false;
    }

    if (head->teacher.getId() == teacherId) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;

    while (current->next != nullptr) {
        if (current->next->teacher.getId() == teacherId) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }

        current = current->next;
    }

    return false;
}

void TeacherList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}