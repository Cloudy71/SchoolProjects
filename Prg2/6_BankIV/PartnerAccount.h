//
// Created by Cloudy on 30-Apr-18.
//

#ifndef BANK_PARTNERACCOUNT_H
#define BANK_PARTNERACCOUNT_H


#include "Account.h"

class PartnerAccount : public Account {
private:
    Client *_partner;
public:
    PartnerAccount(int n, Client *o, Client *p) : Account(n, o) {
        this->_partner = p;
    }

    PartnerAccount(int n, Client *o, Client *p, double ir) : Account(n, o, ir) {
        this->_partner = p;
    }

    ~PartnerAccount();

    Client *getPartner();

};


#endif //BANK_PARTNERACCOUNT_H
