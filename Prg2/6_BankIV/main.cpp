#include <iostream>
#include "Bank.h"
#include "CreditAccount.h"

using namespace std;

int main() {
    Bank *bank = new Bank();

    Client        *c  = new Client(0, "Dan");
    CreditAccount *ca = new CreditAccount(1, c, 1000);

    cout << ca->canWithdraw(1000) << endl;
    cout << ((Account *) ca)->canWithdraw(1000) << endl;
    cout << ca->withdraw(1000) << endl;
    cout << "Number in char: " << ca->getNumberInChar() << endl;

    return 0;
}