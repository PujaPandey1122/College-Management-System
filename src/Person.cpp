#include "../include/Person.h"

Person::Person(int id, const std::string& name, const std::string& email)
    : id(id), name(name), email(email) {
}

int Person::getId() const {
    return id;
}