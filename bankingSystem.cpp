#include <iostream>
using namespace std;

int main() {
    int choice;
    float balance = 0, amount;

    do {
        cout << "\n===== Bank Menu =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                balance += amount;
                break;

            case 2:
                cout << "Enter withdraw amount: ";
                cin >> amount;
                if(amount <= balance)
                    balance -= amount;
                else
                    cout << "Insufficient balance!\n";
                break;

            case 3:
                cout << "Balance: " << balance << endl;
                break;

            case 4:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 4);

    return 0;
}
