//
// Created by User on 26.03.2018.
//

#ifndef BANK_TRANSACTION_H
#define BANK_TRANSACTION_H

#define TRANSACTION_DEPOSIT    0x0
#define TRANSACTION_WITHDRAW   0x1
#define TRANSACTION_SHOW       0x2
#define TRANSACTION_NOTDEFINED 0x4

#define TRANSACTION_STATUS_PENDING    0x5
#define TRANSACTION_STATUS_COMMITED   0x6
#define TRANSACTION_STATUS_ROLLEDBACK 0x7
#define TRANSACTION_STATUS_FAILED     0x8

#include "Bank.h"
#include "TransactionData.h"

class Transaction {
private:
    int             _id;
    Bank            *_bank;
    Account         *_account;
    TransactionData *_data;
    int             _status;
    string          _resultMessage;
    bool            _commited;
    bool            _rolledBack;
public:
    Transaction(int, Bank *, Account *, TransactionData *);

    int getId();

    Bank *getBank();

    Account *getAccount();

    int getStatus();

    template<class T>
    bool commit(T &ret);

    bool commit();

    bool rollback();

    string getResultMessage();
};


#endif //BANK_TRANSACTION_H
