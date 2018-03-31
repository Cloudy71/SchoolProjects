//
// Created by User on 26.03.2018.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include "Bank.h"
#include "Client.h"
#include "Transaction.h"

class Account {
private:
    int    _number;
    double _balance;
    double _interestRate;

    Bank   *_bank;
    Client *_owner;
    Client *_partner;
public:
    Account(int accountNumber, Bank *bank, Client *client);

    Account(int accountNumber, Bank *bank, Client *client, double ir);

    Account(int accountNumber, Bank *bank, Client *client, Client *partner);

    Account(int accountNumber, Bank *bank, Client *client, Client *partner, double ir);

    int getNumber();

    Bank *getBank();

    double getBalance(Transaction * transaction);

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
