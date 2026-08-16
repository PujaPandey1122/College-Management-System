#include "../include/Course.h"
#include <iostream>

Course::Course(int courseId,
               const std::string& courseName,
               int credits)
    : courseId(courseId),
      courseName(courseName),
      credits(credits) {
}

void Course::display() const {
    std::cout << "Course ID: " << courseId << '\n';
    std::cout << "Course Name: " << courseName << '\n';
    std::cout << "Credits: " << credits << '\n';
}

int Course::getCourseId() const {
    return courseId;
}

std::string Course::getCourseName() const {
    return courseName;
}

int Course::getCredits() const {
    return credits;
}