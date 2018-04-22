//
// Created by mil0068 on 11-Mar-18.
//

#include "Person.h"

Person::Person(string name, string address) {
    this->name    = name;
    this->address = address;
}

string Person::getName() {
    return this->name;
}

string Person::getAddress() {
    return this->address;
}