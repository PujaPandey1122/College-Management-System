#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

class Teacher : public Person {
private:
    std::string department;
    std::string specialization;

public:
    Teacher(int id,
            const std::string& name,
            const std::string& email,
            const std::string& department,
            const std::string& specialization);

    void display() const override;
};

#endif