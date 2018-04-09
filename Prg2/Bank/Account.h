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
    Account(int accountNumber, Client *client, Client *partner, double ir);

    Account(int accountNumber, Client *client) : Account(accountNumber, client, nullptr, 0.0) {}

    Account(int accountNumber, Client *client, double ir) : Account(accountNumber, client, nullptr, ir) {}

    Account(int accountNumber, Client *client, Client *partner) : Account(accountNumber, client, partner, 0.0) {}

    int getNumber();

    double getBalance();

    double getInterestRate();

    Client *getOwner();

    Client *getPartner();

    bool canWithdraw(double amount);

    void deposit(double amount);

    bool withdraw(double amount);

    void addInterest();
};


#endif //BANK_ACCOUNT_H
