#pragma once
#include <map>
using namespace std;

class Cart {
private:
    map<int, int> entries;   // itemId -> quantity

public:
    void add(int id, int qty) { entries[id] += qty; }
    void clear() { entries.clear(); }
    bool isEmpty() { return entries.empty(); }
    map<int, int> &getEntries() { return entries; }
};