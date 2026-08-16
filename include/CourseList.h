#ifndef COURSE_LIST_H
#define COURSE_LIST_H

#include "Course.h"
#include <stdexcept>

class CourseList {
private:
    struct Node {
        Course course;
        Node* next;

        Node(const Course& course);
    };

    Node* head;

public:
    CourseList();
    ~CourseList();

    void addCourse(const Course& course);
    void displayCourses() const;
    bool searchCourse(int courseId) const;
    bool deleteCourse(int courseId);

private:
    void clear();
};

#endif