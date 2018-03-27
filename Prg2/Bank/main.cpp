#include <iostream>
#include "Bank.h"

int main() {
    Bank   *bank   = new Bank();
    Client *client = bank->createClient(0, "Cloudy");

    std::cout << "Client name: " << client->getName() << std::endl;
    return 0;
}