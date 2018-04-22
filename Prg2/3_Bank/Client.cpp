//
// Created by User on 26.03.2018.
//

#include "Client.h"

Client::Client(int clientCode, string clientName) {
    this->_code = clientCode;
    this->_name = clientName;
}

int Client::getCode() {
    return this->_code;
}

string Client::getName() {
    return this->_name;
}