#ifndef SCHOOLPROJECT_PERSON_H
#define SCHOOLPROJECT_PERSON_H

#include <string>

using namespace std;

class Person {
private:
    string name;
    string address;
public:
    Person(string name, string address);

    string getName();

    string getAddress();
};


#endif //SCHOOLPROJECT_PERSON_H
