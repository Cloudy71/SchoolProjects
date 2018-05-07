//
// Created by Cloudy on 07-May-18.
//

#ifndef BANK_CREDITACCOUNT_H
#define BANK_CREDITACCOUNT_H


#include "Account.h"

class CreditAccount : public Account {
private:
    double _credit;
public:
    CreditAccount(int n, Client *o, double ir, double c) : Account(n, o, ir) {
        this->_credit = c;
    }

    CreditAccount(int n, Client *o, double c) : CreditAccount(n, o, Account::getDefaultInterestRate(), c) {}

    bool canWithdraw(double amount) override;

    bool withdraw(double amount) override;

    char getNumberInChar();
};


#endif //BANK_CREDITACCOUNT_H
