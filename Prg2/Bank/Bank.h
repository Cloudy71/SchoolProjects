//
// Created by User on 26.03.2018.
//

#ifndef BANK_BANK_H
#define BANK_BANK_H

#include <iostream>
#include "Client.h"
#include "Account.h"

using namespace std;

class Bank {
private:
    Client  **_clients;
    int     _clientCount;
    Account **_accounts;
    int     _accountCount;
public:
    Bank();

    ~Bank();

    Client *getClient(int);

    Account *getAccount(int);

    // Client part
    Client *createClient(int, string);

    // Account part
    Account *createAccount(int, Client *);

    Account *createAccount(int, Client *, double);

    Account *createAccount(int, Client *, Client *);

    Account *createAccount(int, Client *, Client *, double);
};


#endif //BANK_BANK_H
