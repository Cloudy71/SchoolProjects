//
// Created by User on 26.03.2018.
//

#ifndef BANK_CLIENT_H
#define BANK_CLIENT_H

#include <iostream>

using namespace std;

class Client {
private:
    static int _objectsCount;

    int        _code;
    string     _name;
public:
    Client(int, string);

    ~Client();

    int getCode();

    string getName();

    static int getObjectsCount();
};


#endif //BANK_CLIENT_H
