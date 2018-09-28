#pragma once

#include <iostream>

using namespace std;

struct ListItem {
    int Value;
    ListItem *Prev;
    ListItem *Next;
};

struct List {
    ListItem *Head;
    ListItem *Tail;
};

void Init(List &L);

void Init(List &L, const int InitValue);

void Init(List &L, const int InitValues[], const int N);

void Init(List &L, const List &Other);

void Prepend(List &L, const int NewValue);

void Append(List &L, const int NewValue);

void InsertBefore(List &L, ListItem *CurrentItem, const int NewValue);

void InsertAfter(List &L, ListItem *CurrentItem, const int NewValue);

void RemoveFirst(List &L);

void RemoveLast(List &L);

void Remove(List &L, const int ValueToRemove);

void RemoveAll(List &L, const int ValueToRemove);

void Remove(List &L, const ListItem *ItemToRemove);

void Clear(List &L);

ListItem *Search(const List &L, const int Value);

ListItem *ReverseSearch(const List &L, const int Value);

bool Contains(const List &L, const int Value);

bool IsEmpty(const List &L);

int Count(const List &L);

void Report(const List &L);

void ReportStructure(const List &L);

void InternalCreateSingleElementList(List &L, const int NewValue);

void InternalRemove(List &L, const ListItem *ItemToDelete);
