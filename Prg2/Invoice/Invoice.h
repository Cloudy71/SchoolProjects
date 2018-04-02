#ifndef SCHOOLPROJECT_INVOICE_H
#define SCHOOLPROJECT_INVOICE_H

#include "Person.h"
#include "InvoiceItem.h"
#include <vector>
#include <set>

class Invoice {
private:
    int                   number;
    Person                *person;
    vector<InvoiceItem *> items;
public:
    Invoice(int number, Person *person);

    ~Invoice();

    Invoice *dispose();

    int getNumber();

    Person *getPerson();

    set<InvoiceItem *> getItems();

    int getPrice();

    void addItem(InvoiceItem *item);
};


#endif //SCHOOLPROJECT_INVOICE_H
