#include "KeyValue.h"
#include <iostream>

using namespace std;

KeyValue::KeyValue(int k, double v) {
    this->_key = k;
    this->_value = v;
    this->_next = nullptr;
}

KeyValue::~KeyValue() {
    cout << "deleting " << this->_key << endl;
    if (this->_next != nullptr) {
        delete this->_next;
    }
}

int KeyValue::getKey() {
    return this->_key;
}

double KeyValue::getValue() {
    return this->_value;
}

KeyValue* KeyValue::getNext() {
    return this->_next;
}

void KeyValue::createNext(int k, double v) {
    this->_next = new KeyValue(k, v);
}

bool KeyValue::hasNext() {
    return this->_next!=nullptr;
}
