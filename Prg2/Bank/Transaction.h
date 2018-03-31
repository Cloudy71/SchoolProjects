//
// Created by User on 26.03.2018.
//

#ifndef BANK_TRANSACTION_H
#define BANK_TRANSACTION_H

#define TRANSACTION_DEPOSIT     0x0
#define TRANSACTION_WITHDRAW    0x1
#define TRANSACTION_BALANCE     0x2
#define TRANSACTION_NOT_DEFINED 0x4

#define TRANSACTION_STATUS_PENDING    0x5
#define TRANSACTION_STATUS_COMMITED   0x6
#define TRANSACTION_STATUS_ROLLEDBACK 0x7

#include "Bank.h"
#include "TransactionData.h"

class Transaction {
private:
    Bank            *_bank;
    Account         *_account;
    TransactionData *_data;
    string          _resultMessage;
    bool            _committed;
    bool            _rolledBack;
public:
    Transaction(Bank *bank, Account *account, TransactionData *transactionData);

    Bank *getBank();

    Account *getAccount();

    int getStatus();

    template<class T>
    bool commit(T &ret);

    bool commit();

    bool rollback();

    string getResultMessage();

    bool isType(int type);
};


#endif //BANK_TRANSACTION_H
