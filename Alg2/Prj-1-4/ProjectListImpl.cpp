//
// Created by MIL0068 on 26.03.2018.
// File is made for overriding purposes...
//

#include "List.h"
#include <iostream>

//@Override
void Prepend(List &L, const int NewValue) {
    if (IsEmpty(L)) {
        InternalCreateSingleElementList(L, NewValue);
    } else {
        ListItem *NewItem = new ListItem;
        NewItem->Value      = NewValue;
        NewItem->Prev       = L.Tail;
        NewItem->Next       = L.Head;
        NewItem->Prev->Next = NewItem;
        NewItem->Next->Prev = NewItem;
        L.Head              = NewItem;
    }
}

//@Override
void Append(List &L, const int NewValue) {
    if (IsEmpty(L)) {
        InternalCreateSingleElementList(L, NewValue);
    } else {
        ListItem *NewItem = new ListItem;
        NewItem->Value      = NewValue;
        NewItem->Next       = L.Head;
        NewItem->Prev       = L.Tail;
        NewItem->Prev->Next = NewItem;
        NewItem->Next->Prev = NewItem;
        L.Tail              = NewItem;
    }
}

//@Override
void InternalCreateSingleElementList(List &L, const int NewValue) {
    L.Head        = L.Tail        = new ListItem;
    L.Head->Value = L.Tail->Value = NewValue;
    L.Head->Prev  = L.Head->Next  = L.Tail;
    L.Tail->Prev  = L.Tail->Next  = L.Head;
    // Element0 <- Element0 -> Element0
}

//@Override
void InternalRemove(List &L, const ListItem *ItemToDelete) {
    if (ItemToDelete == L.Head && ItemToDelete == L.Tail) {
        L.Head = nullptr;
        L.Tail = nullptr;
    } else {
        if (ItemToDelete == L.Head) {
            L.Head       = L.Head->Next;
            L.Head->Prev = L.Tail;
            L.Tail->Next = L.Head;
        } else {
            if (ItemToDelete == L.Tail) {
                L.Tail       = L.Tail->Prev;
                L.Tail->Next = L.Head;
                L.Head->Prev = L.Tail;
            } else {
                ListItem *P = ItemToDelete->Prev;
                ListItem *N = ItemToDelete->Next;
                P->Next = N;
                N->Prev = P;
            }
        }
    }
    delete ItemToDelete;
}

//@Override
int Count(const List &L) {
    int counter = 0;

    for (ListItem *p = L.Head; p != L.Tail; p = p->Next) {
        counter++;
    }
    if (L.Tail != nullptr) counter++;
    return counter;
}

//@Override
ListItem *Search(const List &L, const int Value) {
    if (L.Head == nullptr) {
        return nullptr;
    }

    if (L.Head->Value == Value) {
        return L.Head;
    }
    for (ListItem *p = L.Head->Next; p != L.Head; p = p->Next) {
        if (p->Value == Value) {
            return p;
        }
    }
    return nullptr;
}

//@Override
ListItem *ReverseSearch(const List &L, const int Value) {
    if (L.Tail == nullptr) {
        return nullptr;
    }

    if (L.Tail->Value == Value) {
        return L.Tail;
    }
    for (ListItem *p = L.Tail->Prev; p != L.Tail; p = p->Prev) {
        if (p->Value == Value) {
            return p;
        }
    }
    return nullptr;
}