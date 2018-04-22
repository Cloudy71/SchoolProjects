//
// Created by mil0068 on 11-Mar-18.
//

#include "Invoice.h"
#include <iostream>

using namespace std;

Invoice::Invoice(int number, Person *person) {
    this->number = number;
    this->person = person;
    this->items  = vector<InvoiceItem *>();
}

Invoice::~Invoice() {
    for (InvoiceItem *item : this->items) {
        cout << "deleting i .. " << item << endl;
        delete item;
    }
    this->items.clear();
}

Invoice *Invoice::dispose() {
    cout << "deleting .. " << this->person << endl;
    delete this->person;
    return this;
}

int Invoice::getNumber() {
    return this->number;
}

Person *Invoice::getPerson() {
    return this->person;
}

set<InvoiceItem *> Invoice::getItems() {
    return set<InvoiceItem *>(this->items.begin(), this->items.end());
}

int Invoice::getPrice() {
    int price = 0;
    for (InvoiceItem *item : this->getItems()) {
        price += item->getPrice();
    }

    return price;
}

void Invoice::addItem(InvoiceItem *item) {
    cout << "added .. " << item << endl;
    this->items.push_back(item);
}