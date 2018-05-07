//
// Created by Cloudy on 07-May-18.
//

#include "CreditAccount.h"

bool CreditAccount::canWithdraw(double amount) {
    return (this->getBalance() + this->_credit) >= amount;
}

bool CreditAccount::withdraw(double amount) {
    if (this->canWithdraw(amount)) {
        this->_balance -= amount;
        return true;
    }
    return false;
}

char CreditAccount::getNumberInChar() {
    return (char) this->_number;
}