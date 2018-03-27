//
// Created by User on 26.03.2018.
//

#include "Transaction.h"

Transaction::Transaction(int id, Bank *bank, Account *account, TransactionData *transactionData) {
    this->_id            = id;
    this->_bank          = bank;
    this->_account       = account;
    this->_data          = transactionData;
    this->_status        = TRANSACTION_STATUS_PENDING;
    this->_resultMessage = "";
    this->_commited      = false;
    this->_rolledBack    = false;
}

int Transaction::getId() {
    return this->_id;
}

Bank *Transaction::getBank() {
    return this->_bank;
}

Account *Transaction::getAccount() {
    return this->_account;
}

int Transaction::getStatus() {
    return this->_status;
}

template<class T>
bool Transaction::commit(T &ret) {
    if (this->_data == nullptr || this->_data->getType() == TRANSACTION_NOTDEFINED) {
        this->_resultMessage = "No data have been set.";
        ret = nullptr;
        return false;
    }
}

bool Transaction::commit() {
    return commit<void>((void &) nullptr);
}

bool Transaction::rollback() {

}

string Transaction::getResultMessage() {
    return this->_resultMessage;
}