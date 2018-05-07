//
// Created by User on 26.03.2018.
//

#include "Client.h"

int Client::_objectsCount = 0;

Client::Client(int clientCode, string clientName) {
    this->_code = clientCode;
    this->_name = clientName;
    Client::_objectsCount++;
}

Client::~Client() {
    Client::_objectsCount--;
}

int Client::getCode() {
    return this->_code;
}

string Client::getName() {
    return this->_name;
}

int Client::getObjectsCount() {
    return Client::_objectsCount;
}