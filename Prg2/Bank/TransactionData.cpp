//
// Created by User on 26.03.2018.
//

#include "TransactionData.h"
#include "Transaction.h"

TransactionData::TransactionData() {
    this->_type = TRANSACTION_NOTDEFINED;
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