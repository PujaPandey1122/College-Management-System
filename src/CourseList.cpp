#include "../include/CourseList.h"
#include <iostream>

CourseList::Node::Node(const Course& course)
    : course(course), next(nullptr) {
}

CourseList::CourseList()
    : head(nullptr) {
}

CourseList::~CourseList() {
    clear();
}

void CourseList::addCourse(const Course& course) {
    if (searchCourse(course.getCourseId())) {
        throw std::invalid_argument("Course ID already exists.");
    }

    Node* newNode = new Node(course);

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

void CourseList::displayCourses() const {
    if (head == nullptr) {
        std::cout << "No courses available.\n";
        return;
    }

    Node* current = head;

    while (current != nullptr) {
        current->course.display();
        std::cout << "-------------------------\n";
        current = current->next;
    }
}

bool CourseList::searchCourse(int courseId) const {
    Node* current = head;

    while (current != nullptr) {
        if (current->course.getCourseId() == courseId) {
            return true;
        }

        current = current->next;
    }

    return false;
}

bool CourseList::deleteCourse(int courseId) {
    if (head == nullptr) {
        return false;
    }

    if (head->course.getCourseId() == courseId) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;

    while (current->next != nullptr) {
        if (current->next->course.getCourseId() == courseId) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }

        current = current->next;
    }

    return false;
}

void CourseList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}