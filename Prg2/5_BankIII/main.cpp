#include <iostream>
#include "Bank.h"

using namespace std;

int main() {
    Bank *bank = new Bank();

    Client *o = bank->createClient(0, "One");
    Client *p = bank->createClient(1, "Two");

    Account        *a  = bank->createAccount(0, o);
    PartnerAccount *pa = bank->createAccount(1, o, p);

    cout << "Owner name: " << a->getOwner()->getName() << endl;
    cout << "Partner name: " << pa->getPartner()->getName() << endl;

    cout << bank->getClient(1)->getName() << endl;
    return 0;
}