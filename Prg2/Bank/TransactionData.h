//
// Created by User on 26.03.2018.
//

#ifndef BANK_TRANSACTIONDATA_H
#define BANK_TRANSACTIONDATA_H


class TransactionData {
private:
    int  _type;
    void *_data;
public:
    TransactionData();

    ~TransactionData();

    int getType();

    template<class T>
    T getData();

    template<class T>
    void generate(int type, T data);
};


#endif //BANK_TRANSACTIONDATA_H
