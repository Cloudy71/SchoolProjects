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

    double _interestRate;

    Client *_owner;
protected:
    int    _number;
    double _balance;
public:
    Account(int accountNumber, Client *client, double ir);

    Account(int accountNumber, Client *client) : Account(accountNumber, client, _defaultInterestRate) {}

    ~Account();

    int getNumber();

    double getBalance();

    double getInterestRate();

    Client *getOwner();

    virtual bool canWithdraw(double amount);

    void deposit(double amount);

    virtual bool withdraw(double amount);

    void addInterest();

    static int getObjectsCount();

    static double getDefaultInterestRate();

    static void setDefaultInterestRate(double ir);
};


#endif //BANK_ACCOUNT_H
