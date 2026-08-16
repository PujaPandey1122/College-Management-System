#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
private:
    int courseId;
    std::string courseName;
    int credits;

public:
    Course(int courseId,
           const std::string& courseName,
           int credits);

    void display() const;

    int getCourseId() const;
    std::string getCourseName() const;
    int getCredits() const;
};

#endif