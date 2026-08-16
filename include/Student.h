#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
private:
    std::string course;
    int semester;

public:
    Student(int id,
            const std::string& name,
            const std::string& email,
            const std::string& course,
            int semester);

    void display() const override;
};

#endif