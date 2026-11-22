#pragma once
#include <iostream>
#include <string>
using namespace std;

// Common interface (Strategy pattern)
class Payment {
public:
    virtual bool pay(double amount) = 0;
    virtual ~Payment() {}
};

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        double inserted;
        cout << "Total Rs " << amount << ". Insert cash: ";
        cin >> inserted;
        if (inserted < amount) {
            cout << "Not enough cash. Returning Rs " << inserted << endl;
            return false;
        }
        if (inserted > amount)
            cout << "Collect change: Rs " << inserted - amount << endl;
        cout << "Cash payment successful!\n";
        return true;
    }
};

class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        string pin;
        cout << "Total Rs " << amount << ". Enter card PIN (demo PIN = 1234): ";
        cin >> pin;
        if (pin != "1234") {
            cout << "Wrong PIN. Card payment failed.\n";
            return false;
        }
        cout << "Card payment successful!\n";
        return true;
    }
};

class QRPayment : public Payment {
public:
    bool pay(double amount) override {
        int done;
        cout << "Scan the QR and pay Rs " << amount << endl;
        cout << "Payment done? (1 = yes, 0 = no): ";
        cin >> done;
        if (done != 1) {
            cout << "QR payment failed.\n";
            return false;
        }
        cout << "QR payment successful!\n";
        return true;
    }
};