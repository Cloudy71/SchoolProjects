#include <iostream>
#include "KeyValue.h"

using namespace std;


int main() {
    KeyValue* kv = new KeyValue(0, 1.23);
    KeyValue* n = kv;
    int max = 1000;
    for (int i = 0; i < max; i++) {
        n->createNext(i, 2.2 + (double)i);
        n = n->getNext();
    }

    KeyValue* actual = kv;
    do {
        cout << actual->getKey() << ": " << actual->getValue() << endl;
    } while ((actual = actual->getNext()) != nullptr);

    delete kv;

    return 0;
}
