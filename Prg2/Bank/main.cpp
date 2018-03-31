#include <iostream>
#include "Bank.h"

using namespace std;

int main() {
    Bank   *bank   = new Bank();
    Client *client = bank->createClient(0, "Cloudy");
    Account *account = bank->createAccount(0, client);

    cout << "Client name: " << client->getName() << endl;
    cout << "Balance: " << account->getBalance() << endl;
    return 0;
}