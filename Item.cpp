#pragma once
#include <string>
using namespace std;

class Item {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    Item(int id, string name, double price, int quantity) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

    int getId() { return id; }
    string getName() { return name; }
    double getPrice() { return price; }
    int getQuantity() { return quantity; }

    void reduceQuantity(int qty) { quantity -= qty; }
    void addQuantity(int qty) { quantity += qty; }
};