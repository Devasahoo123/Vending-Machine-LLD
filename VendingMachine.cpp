#pragma once
#include <iostream>
#include "Inventory.cpp"
#include "Cart.cpp"
#include "Payment.cpp"
using namespace std;

class VendingMachine {
private:
    Inventory inventory;
    Cart cart;

    double calculateTotal() {
        double total = 0;
        for (auto &e : cart.getEntries()) {
            total += inventory.getPrice(e.first) * e.second;
        }
        return total;
    }

public:
    // Used for first-time loading and for admin
    void addNewItem(int id, string name, double price, int qty) {
        inventory.addItem(id, name, price, qty);
    }

    void showItems() { inventory.showAvailableItems(); }

    void addToCart(int id, int qty) {
        if (qty <= 0) {
            cout << "Invalid quantity!\n";
            return;
        }
        // total in cart already + new qty must be within stock
        int alreadyInCart = 0;
        auto &entries = cart.getEntries();
        if (entries.count(id)) alreadyInCart = entries[id];

        if (!inventory.isAvailable(id, alreadyInCart + qty)) {
            cout << "Item not available in this quantity!\n";
            return;
        }
        cart.add(id, qty);
        cout << qty << " x " << inventory.getName(id) << " added to cart.\n";
    }

    void checkout(Payment *payment) {
        if (cart.isEmpty()) {
            cout << "Cart is empty!\n";
            return;
        }

        double total = calculateTotal();
        bool success = payment->pay(total);

        if (!success) {
            cout << "Payment failed. Cart is kept, try again.\n";
            return;
        }

        // Payment ok -> decrease stock
        for (auto &e : cart.getEntries()) {
            inventory.reduceStock(e.first, e.second);
        }
        cart.clear();
        cout << "Please collect your items. Thank you!\n";
    }

    // Admin refill
    void refill(int id, int qty) { inventory.refill(id, qty); }
};