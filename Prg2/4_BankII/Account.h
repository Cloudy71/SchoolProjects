//
// Created by User on 26.03.2018.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include "Client.h"

class Account {
private:
    static int    _objectsCount;
    static double _defaultInterestRate;

    int    _number;
    double _balance;
    double _interestRate;

    Client *_owner;
    Client *_partner;
public:
    Account(int accountNumber, Client *client, Client *partner, double ir);

    Account(int accountNumber, Client *client) : Account(accountNumber, client, nullptr, _defaultInterestRate) {}

    Account(int accountNumber, Client *client, double ir) : Account(accountNumber, client, nullptr, ir) {}

    Account(int accountNumber, Client *client, Client *partner) : Account(accountNumber, client, partner,
                                                                          _defaultInterestRate) {}

    ~Account();

    int getNumber();

    double getBalance();

    double getInterestRate();

    Client *getOwner();

    Client *getPartner();

    bool canWithdraw(double amount);

    void deposit(double amount);

    bool withdraw(double amount);

    void addInterest();

    static int getObjectsCount();

    static double getDefaultInterestRate();

    static void setDefaultInterestRate(double ir);
};


#endif //BANK_ACCOUNT_H
