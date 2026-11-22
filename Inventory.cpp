#pragma once
#include <iostream>
#include <map>
#include "Item.cpp"
using namespace std;

class Inventory {
private:
    map<int, Item> items;   // id -> Item

public:
    void addItem(int id, string name, double price, int qty) {
        items.emplace(id, Item(id, name, price, qty));
    }

    // Only items with quantity > 0 are shown
    void showAvailableItems() {
        bool found = false;
        cout << "\n----- Available Items -----\n";
        for (auto &p : items) {
            Item &it = p.second;
            if (it.getQuantity() > 0) {
                cout << it.getId() << ". " << it.getName()
                     << " | Rs " << it.getPrice()
                     << " | Qty: " << it.getQuantity() << endl;
                found = true;
            }
        }
        if (!found) cout << "Machine is empty!\n";
    }

    bool isAvailable(int id, int qty) {
        auto it = items.find(id);
        if (it == items.end()) return false;
        return it->second.getQuantity() >= qty;
    }

    double getPrice(int id) { return items.at(id).getPrice(); }
    string getName(int id) { return items.at(id).getName(); }

    void reduceStock(int id, int qty) { items.at(id).reduceQuantity(qty); }

    // Refill (admin)
    void refill(int id, int qty) {
        auto it = items.find(id);
        if (it == items.end()) {
            cout << "Item not found!\n";
            return;
        }
        it->second.addQuantity(qty);
        cout << "Refilled " << it->second.getName() << " by " << qty << endl;
    }
};