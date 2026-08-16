#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    int id;
    std::string name;
    std::string email;

public:
    Person(int id, const std::string& name, const std::string& email);

    virtual void display() const = 0;

    int getId() const;

    virtual ~Person() = default;
};

#endif