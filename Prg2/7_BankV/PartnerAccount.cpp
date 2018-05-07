//
// Created by Cloudy on 30-Apr-18.
//

#include "PartnerAccount.h"

PartnerAccount::~PartnerAccount() {
    delete this->_partner;
}

Client *PartnerAccount::getPartner() {
    return this->_partner;
}