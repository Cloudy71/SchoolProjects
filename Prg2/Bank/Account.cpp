//
// Created by User on 26.03.2018.
//

#include "Account.h"

Account::Account(int accountNumber, Client *owner) {
    this->_number       = accountNumber;
    this->_owner        = owner;
    this->_partner      = nullptr;
    this->_balance      = 0.0;
    this->_interestRate = 0.0;
}

int Account::getNumber() {
    return this->_number;
}

double Account::getBalance() {
    return this->_balance;
}

double Account::getInterestRate() {
    return this->_interestRate;
}

Client *Account::getOwner() {
    return this->_owner;
}

Client *Account::getPartner() {
    return this->_partner;
}

bool Account::canWithdraw(double value) {
    return this->_balance >= value;
}

void Account::deposit(double value) {
    this->_balance += value;
}

bool Account::withdraw(double value) {
    if (this->_balance >= value) {
        this->_balance -= value;
        return true;
    }
    return false;
}

void Account::addInterest() {
    // Something will happen..
}