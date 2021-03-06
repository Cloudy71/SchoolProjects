//
// Created by User on 26.03.2018.
//

#ifndef BANK_BANK_H
#define BANK_BANK_H

#include <iostream>
#include "Client.h"
#include "Account.h"
#include "PartnerAccount.h"

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
    Account *createAccount(int accountNumber, Client *client, double ir);

    Account *createAccount(int accountNumber, Client *client) {
        return createAccount(accountNumber, client, Account::getDefaultInterestRate());
    }

    PartnerAccount *createAccount(int accountNumber, Client *client, Client *partner, double ir);

    PartnerAccount *createAccount(int accountNumber, Client *client, Client *partner) {
        return createAccount(accountNumber, client, partner, Account::getDefaultInterestRate());
    }

    // Getters
    int getClientCount();

    int getAccountCount();
};


#endif //BANK_BANK_H
