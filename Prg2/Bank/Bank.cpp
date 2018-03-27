//
// Created by User on 26.03.2018.
//

#include "Bank.h"

Bank::Bank() {
    this->_clients  = new Client *[0];
    this->_accounts = new Account *[0];

    this->_clientCount  = 0;
    this->_accountCount = 0;
}

Bank::~Bank() {
    for (int i = 0; i < this->_clientCount; i++) {
        delete this->_clients[i];
    }
    delete this->_clients;

    for (int i = 0; i < this->_accountCount; i++) {
        delete this->_accounts[i];
    }
    delete this->_accounts;
}

Client *Bank::getClient(int clientCode) {
    for (int i = 0; i < this->_clientCount; i++) {
        Client *client = this->_clients[i];
        if (client->getCode() == clientCode) {
            return client;
        }
    }
    return nullptr;
}

Account *Bank::getAccount(int accountNumber) {
    for (int i = 0; i < this->_accountCount; i++) {
        Account *account = this->_accounts[i];
        if (account->getNumber() == accountNumber) {
            return account;
        }
    }
    return nullptr;
}

Client *Bank::createClient(int clientCode, string clientName) {
    Client *client = new Client(clientCode, clientName);

    this->_clientCount++;
    this->_clients = (Client **) realloc(this->_clients, sizeof(Client **) * this->_clientCount);

    return client;
}