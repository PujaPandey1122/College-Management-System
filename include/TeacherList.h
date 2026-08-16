#ifndef TEACHER_LIST_H
#define TEACHER_LIST_H

#include "Teacher.h"
#include <stdexcept>

class TeacherList {
private:
    struct Node {
        Teacher teacher;
        Node* next;

        Node(const Teacher& teacher);
    };

    Node* head;

public:
    TeacherList();
    ~TeacherList();

    void addTeacher(const Teacher& teacher);
    void displayTeachers() const;
    bool searchTeacher(int teacherId) const;
    bool deleteTeacher(int teacherId);

private:
    void clear();
};

#endif