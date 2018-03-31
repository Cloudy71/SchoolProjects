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

    Client *getClient(int clientId);

    Account *getAccount(int accountNumber);

    // Client part
    Client *createClient(int clientId, string clientName);

    // Account part
    Account *createAccount(int accountNumber, Client *client);

    Account *createAccount(int accountNumber, Client *client, double ir);

    Account *createAccount(int accountNumber, Client *client, Client *partner);

    Account *createAccount(int accountNumber, Client *client, Client *partner, double ir);
};


#endif //BANK_BANK_H
