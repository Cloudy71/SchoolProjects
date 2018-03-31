//
// Created by User on 26.03.2018.
//

#include "Account.h"

Account::Account(int accountNumber, Bank *bank, Client *owner) {
    this->_number       = accountNumber;
    this->_bank         = bank;
    this->_owner        = owner;
    this->_partner      = nullptr;
    this->_balance      = 0.0;
    this->_interestRate = 0.0;
}

int Account::getNumber() {
    return this->_number;
}

Bank *Account::getBank() {
    return this->_bank;
}

double Account::getBalance(Transaction *transaction) {
    if (transaction->getStatus() != TRANSACTION_STATUS_PENDING || transaction->getAccount() != this ||
        !transaction->isType(TRANSACTION_BALANCE)) {
        return 0.0;
    }

    return this->_balance;
}

double Account::getBalance() {
    Transaction *transaction = new Transaction(this->_bank,
                                               this,
                                               (new TransactionData())->generate<void>(
                                                       TRANSACTION_BALANCE,
                                                       nullptr
                                               ));
    double      balance;
    transaction->commit<double>(balance);

    return balance;
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
    return this->_balance >= amount;
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