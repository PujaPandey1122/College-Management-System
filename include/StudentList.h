#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include "Student.h"
#include <stdexcept>

class StudentList {
private:
    struct Node {
        Student student;
        Node* next;

        Node(const Student& student);
    };

    Node* head;

public:
    StudentList();
    ~StudentList();

    void addStudent(const Student& student);
    void displayStudents() const;
    bool searchStudent(int studentId) const;
    bool deleteStudent(int studentId);

private:
    void clear();
};

#endif