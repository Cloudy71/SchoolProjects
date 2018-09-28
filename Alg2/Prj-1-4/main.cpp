#include <iostream>
#include <sstream>
#include "List.h"
#include "ProjectListAdds.h"

bool inDebug    = true;
int  windowSize = 120;

void makeLine();

void makeText();

void menu();

void addItem();

void removeItem();

void foreachItems();

void searchOne();

void searchAll();

int chooseItem();

// Input methods
char getChar();

int getInt();

List l;

int main() {
    Init(l);

    menu();

    return 0;
}

void makeLine() {
    for (int i = 0; i < windowSize; i++) {
        cout << "=";
    }
    if (inDebug) cout << endl;
}

void makeText(string text) {
    cout << "| " << text;
    for (int i = 0; i < windowSize - (text.length() + 2) - 1; i++) {
        cout << " ";
    }
    cout << "|";
    if (inDebug) cout << endl;
}

void menu() {
    makeLine();
    makeText("1. Pridat polozku");
    makeText("2. Odebrat polozku");
    makeText("3. Vycistit (smazat vsechny polozky)");
    makeText("4. Vyhledat (jeden)");
    makeText("5. Vyhledat (vsechny)");
    makeText("6. Vypsat seznam");
    makeText("7. Vypsat seznam (zakl. impl.)");
    char sel = getChar();
    makeLine();
    cout << endl << endl;
    system("cls");
    switch (sel) {
        case '1':
            addItem();
            break;
        case '2':
            removeItem();
            break;
        case '3':
            Clear(l);
            break;
        case '4':
            searchOne();
            break;
        case '5':
            searchAll();
            break;
        case '6':
            makeLine();
            foreachItems();
            1
            makeLine();
            break;
        case '7':
            ReportStructure(l);
            break;
        default:
            return;
    }
    cout << endl << endl;
    menu();
}

void addItem() {
    makeLine();
    makeText("Zadejte hodnotu");
    int value = getInt();
    makeText("Vlozit na (K)onec, (Z)acatek, (B)pred polozku, (A)za polozku?");
    char pos = getChar();
    if (pos == 'K' || pos == 'k') {
        Append(l, value);
    } else if (pos == 'Z' || pos == 'z') {
        Prepend(l, value);
    } else if (pos == 'B' || pos == 'b') {
        int index = chooseItem();
        if (index == -1) {
            makeText("Spatna polozka");
            makeLine();
            return;
        }
        ListItem *listItem = getItem(l, index);
        InsertBefore(l, listItem, value);
    } else if (pos == 'A' || pos == 'a') {
        int index = chooseItem();
        if (index == -1) {
            makeText("Spatna polozka");
            makeLine();
            return;
        }
        ListItem *listItem = getItem(l, index);
        InsertAfter(l, listItem, value);
    } else {
        makeLine();
        return;
    }
    makeLine();
}

void removeItem() {
    makeLine();
    foreachItems();
    makeLine();
    makeText("Vyberte polozku");
    int index = getInt();
    if (index < 1 || index > Count(l)) {
        makeText("Spatna polozka.");
        makeLine();
        return;
    }
    ListItem *listItem = getItem(l, index - 1);
    Remove(l, listItem);
    makeLine();
}

void foreachItems() {
    iteratorReset();
    int i = 1;
    while (!iteratorIsOnTail(l)) {
        ListItem     *item = iteratorNext(l);
        stringstream ss;
        ss << i++ << ". " << item << " = " << getValue(item) << " => " << item->Next;
        makeText(ss.str());
    }

    if (i == 1) {
        makeText("Zadne polozky...");
    }
}

void searchOne() {
    makeLine();
    makeText("Zadejte hodnotu");
    int value = getInt();
    makeLine();
    ListItem *listItem = Search(l, value);
    if (listItem != nullptr) {
        stringstream ss;
        ss << listItem << " = " << getValue(listItem) << " => " << listItem->Next;
        makeText(ss.str());
    } else {
        makeText("Zadne polozky...");
    }
    makeLine();
}

void searchAll() {
    makeLine();
    makeText("Zadejte hodnotu");
    int value = getInt();
    makeLine();
    iteratorReset();
    int i = 1;
    while (!iteratorIsOnTail(l)) {
        ListItem *item = iteratorNext(l);
        if (getValue(item) == value) {
            stringstream ss;
            ss << i++ << ". " << item << " = " << getValue(item) << " => " << item->Next;
            makeText(ss.str());
        }
    }
    if (i == 1) {
        makeText("Zadne polozky...");
    }
    makeLine();
}

int chooseItem() {
    foreachItems();
    makeText("Index polozky");
    int index = getInt();
    if (index < 1 || index > Count(l)) {
        return -1;
    }
    return index - 1;
}

// Input
char getChar() {
    cout << "| > ";
    char v;
    do {
        cin >> v;
    } while (cin.fail());

    return v;
}

int getInt() {
    cout << "| > ";
    int v;
    do {
        cin >> v;
    } while (cin.fail());

    return v;
}