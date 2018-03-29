//
// Created by User on 26.03.2018.
//

#include "Transaction.h"

Transaction::Transaction(Bank *bank, Account *account, TransactionData *transactionData) {
    this->_bank          = bank;
    this->_account       = account;
    this->_data          = transactionData;
    this->_resultMessage = "";
    this->_committed     = false;
    this->_rolledBack    = false;
}

Bank *Transaction::getBank() {
    return this->_bank;
}

Account *Transaction::getAccount() {
    return this->_account;
}

int Transaction::getStatus() {
    return this->_rolledBack ? TRANSACTION_STATUS_ROLLEDBACK :
           this->_committed ? TRANSACTION_STATUS_COMMITED :
           TRANSACTION_STATUS_PENDING;
}

template<class T>
bool Transaction::commit(T &ret) {
    if (this->_committed || this->_rolledBack) {
        this->_resultMessage = "Not a valid transaction.";
        ret = nullptr;
        return false;
    } else if (this->_data == nullptr || this->_data->getType() == TRANSACTION_NOT_DEFINED) {
        this->_resultMessage = "No data have been set.";
        this->_committed     = false;
        this->_rolledBack    = false;
        ret = nullptr;
        return false;
    } else if (this->_bank->getAccount(this->_account->getNumber()) == nullptr) {
        this->_resultMessage = "Not a valid bank account.";
        this->_committed     = false;
        this->_rolledBack    = false;
        ret = nullptr;
        return false;
    }

    switch (this->_data->getType()) {
        case TRANSACTION_BALANCE:
            this->_resultMessage = "";
            this->_committed     = true;
            this->_rolledBack    = false;
            ret = this->_account->getBalance(this);
            return true;
        case TRANSACTION_DEPOSIT:

            break;
        case TRANSACTION_WITHDRAW:

            break;
    }

    this->_resultMessage = "Unknown transaction request.";
    this->_committed     = false;
    this->_rolledBack    = false;
    ret = nullptr;
    return false;
}

bool Transaction::commit() {
    return commit<void>((void &) nullptr);
}

bool Transaction::rollback() {

}

string Transaction::getResultMessage() {
    return this->_resultMessage;
}

bool Transaction::isType(int type) {
    return this->_data->getType() == type;
}