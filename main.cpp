#include <iostream>
#include "VendingMachine.cpp"
using namespace std;

int main() {
    VendingMachine vm;

    // initial stock
    vm.addNewItem(1, "Coke", 40, 5);
    vm.addNewItem(2, "Chips", 20, 3);
    vm.addNewItem(3, "Biscuit", 10, 0);   // empty -> will not be shown
    vm.addNewItem(4, "Water", 15, 10);

    int choice;
    do {
        cout << "\n===== VENDING MACHINE =====\n";
        cout << "1. Show items\n2. Add item to cart\n3. Checkout\n";
        cout << "4. Admin refill\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            vm.showItems();
        }
        else if (choice == 2) {
            int id, qty;
            cout << "Enter item id and quantity: ";
            cin >> id >> qty;
            vm.addToCart(id, qty);
        }
        else if (choice == 3) {
            int type;
            cout << "Pay by: 1.QR  2.Card  3.Cash : ";
            cin >> type;

            Payment *payment = nullptr;
            if (type == 1) payment = new QRPayment();
            else if (type == 2) payment = new CardPayment();
            else if (type == 3) payment = new CashPayment();
            else {
                cout << "Invalid payment type!\n";
                continue;
            }

            vm.checkout(payment);
            delete payment;
        }
        else if (choice == 4) {
            int id, qty;
            cout << "Enter item id and refill quantity: ";
            cin >> id >> qty;
            vm.refill(id, qty);
        }
    } while (choice != 0);

    cout << "Bye!\n";
    return 0;
}