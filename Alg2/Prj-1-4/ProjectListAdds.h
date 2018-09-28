//
// Created by MIL0068 on 10.04.2018.
// File is made for additive purposes...
//

#include "List.h"

ListItem *_iterator = nullptr;

ListItem *iteratorNext(List &L) {
    if (_iterator == nullptr) {
        _iterator = L.Head;
        return _iterator;
    }
    _iterator = _iterator->Next;
    return _iterator;
}

ListItem *iteratorPrevious(List &L) {
    if (_iterator == nullptr) {
        _iterator = L.Tail;
        return _iterator;
    }
    _iterator = _iterator->Prev;
    return _iterator;
}

bool iteratorIsOnHead(List &L) {
    return _iterator == L.Head;
}

bool iteratorIsOnTail(List &L) {
    return _iterator == L.Tail;
}

void iteratorReset() {
    _iterator = nullptr;
}

int getValue(ListItem *listItem) {
    return listItem->Value;
}

ListItem *getItem(List &list, int index) {
    iteratorReset();
    int i = 0;
    while (!iteratorIsOnTail(list)) {
        ListItem *listItem = iteratorNext(list);
        if (i++ == index) {
            return listItem;
        }
    }
    return nullptr;
}