//
// Created by User on 26.03.2018.
//

#ifndef BANK_TRANSACTION_H
#define BANK_TRANSACTION_H

#define TRANSACTION_DEPOSIT  0x0
#define TRANSACTION_WITHDRAW 0x1
#define TRANSACTION_SHOW     0x2

#include "Bank.h"
#include "TransactionData.h"

class Transaction {
private:
    int             _id;
    Bank            *_bank;
    Account         *_account;
    TransactionData *_data;
public:
    Transaction(int, Bank *, Account *);

    void setAmount();

    int getId();

    Bank *getBank();

    Account *getAccount();

    void *commit();

    void rollback();
};


#endif //BANK_TRANSACTION_H
