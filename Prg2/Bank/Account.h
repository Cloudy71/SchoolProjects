//
// Created by User on 26.03.2018.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H


#include "Client.h"

class Account {
private:
    int    _number;
    double _balance;
    double _interestRate;

    Client *_owner;
    Client *_partner;
public:
    Account(int, Client *);

    Account(int, Client *, double);

    Account(int, Client *, Client *);

    Account(int, Client *, Client *, double);

    int getNumber();

    double getBalance();

    double getInterestRate();

    Client *getOwner();

    Client *getPartner();

    bool canWithdraw(double);

    void deposit(double);

    bool withdraw(double);

    void addInterest();
};


#endif //BANK_ACCOUNT_H
