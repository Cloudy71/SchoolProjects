//
// Created by User on 26.03.2018.
//

#include "Account.h"

Account::Account(int accountNumber, Client *client, Client *partner, double ir) {
    this->_number = accountNumber;
    this->_owner = client;
    this->_partner = partner;
    this->_interestRate = ir;
    this->_balance = 0.0;
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
}