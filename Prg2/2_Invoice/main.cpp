#include <iostream>
#include "Invoice.h"

using namespace std;

int main() {
    Invoice *invoice = new Invoice(0, new Person("Daniel", "aabb"));
    invoice->addItem(new InvoiceItem("Lednicka", 1000));
    invoice->addItem(new InvoiceItem("Klavir", 4000));
    cout << "Name : " << invoice->getPerson()->getName() << endl;
    cout << "Price: " << invoice->getPrice() << endl;
    delete invoice->dispose();
    return 0;
}