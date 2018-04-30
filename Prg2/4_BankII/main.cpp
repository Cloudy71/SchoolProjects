#include <iostream>
#include "Bank.h"

using namespace std;

int main() {
    Bank    *bank    = new Bank();
    Client  *client  = bank->createClient(0, "Someone");
    Account *account = bank->createAccount(0, client);

    cout << "Client name: " << client->getName() << endl;
    cout << "Balance: " << account->getBalance() << ",-" << endl;
    cout << "Pocet klientu: " << Client::getObjectsCount() << endl;
    cout << "Pocet uctu: " << Account::getObjectsCount() << endl;
    return 0;
}