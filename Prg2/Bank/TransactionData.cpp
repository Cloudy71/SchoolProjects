//
// Created by User on 26.03.2018.
//

#include "TransactionData.h"
#include "Transaction.h"

TransactionData::TransactionData() {
    this->_type = TRANSACTION_NOT_DEFINED;
    this->_data = nullptr;
}

TransactionData::~TransactionData() {
    delete this->_data;
}

int TransactionData::getType() {
    return this->_type;
}

template<class T>
T TransactionData::getData() {
    return (T) this->_data;
}

template<class T>
TransactionData *TransactionData::generate(int type, T data) {
    this->_type = type;
    this->_data = data;

    return this;
}