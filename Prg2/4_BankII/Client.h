//
// Created by User on 26.03.2018.
//

#ifndef BANK_CLIENT_H
#define BANK_CLIENT_H

#include <iostream>

using namespace std;

class Client {
private:
    int    _code;
    string _name;
public:
    Client(int, string);

    int getCode();

    string getName();
};


#endif //BANK_CLIENT_H
