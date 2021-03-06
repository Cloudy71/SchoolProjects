//
// Created by User on 26.03.2018.
//

#include "Account.h"

int    Account::_objectsCount        = 0;
double Account::_defaultInterestRate = 1.0;

Account::Account(int accountNumber, Client *client, double ir) {
    this->_number       = accountNumber;
    this->_owner        = client;
    this->_interestRate = ir;
    this->_balance      = 0.0;

    Account::_objectsCount++;
}

Account::~Account() {
    Account::_objectsCount--;
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

bool Account::canWithdraw(double amount) {
    return this->_balance >= amount * this->_interestRate;
}

void Account::deposit(double amount) {
    this->_balance += amount;
}

bool Account::withdraw(double amount) {
    if (this->_balance >= amount) {
        this->_balance -= amount;
        return true;
    }
    return false;
}

void Account::addInterest() {
    // Something will happen..
    this->_balance += this->_balance * this->_interestRate;
}

int Account::getObjectsCount() {
    return Account::_objectsCount;
}

double Account::getDefaultInterestRate() {
    return Account::_defaultInterestRate;
}

void Account::setDefaultInterestRate(double ir) {
    Account::_defaultInterestRate = ir;
}
