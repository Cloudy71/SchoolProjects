//
// Created by mil0068 on 11-Mar-18.
//

#ifndef SCHOOLPROJECT_INVOICEITEM_H
#define SCHOOLPROJECT_INVOICEITEM_H

#include <string>

using namespace std;

class InvoiceItem {
private:
    string name;
    int    price;
public:
    InvoiceItem(string name, int price);

    string getName();

    int getPrice();
};


#endif //SCHOOLPROJECT_INVOICEITEM_H
