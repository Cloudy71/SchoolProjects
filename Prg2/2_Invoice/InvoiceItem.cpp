//
// Created by mil0068 on 11-Mar-18.
//

#include "InvoiceItem.h"

InvoiceItem::InvoiceItem(string name, int price) {
    this->name  = name;
    this->price = price;
}

string InvoiceItem::getName() {
    return this->name;
}

int InvoiceItem::getPrice() {
    return this->price;
}