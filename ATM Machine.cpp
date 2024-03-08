#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {

private:
    string id;
    string password;
    double balance;

public:
    BankAccount(string id, string password) : id(id), password(password), balance(0) {}

    bool login(string id, string password) {
        return this->id == id && this->password == password;
    }

    void deposit(double amount) {
        balance = balance + amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance = balance - amount;
            return true;
        }
        return false;
    }

    double getBalance() {
        return balance;
    }

};

void printIntroMenu() {
    cout << "Please select an option from the menu below:\n"
         << "l -> Login\n"
         << "c -> Create New Account\n"
         << "q -> Quit\n"
         << "> ";
}

void printMainMenu() {
    cout << "d -> Deposit Money\n"
         << "w -> Withdraw Money\n"
         << "r -> Request Balance\n"
         << "q -> Quit\n"
         << "> ";
}

void start() {
    vector<BankAccount> accounts;
    char menuInput;

    while (true) {
        printIntroMenu();
        cin >> menuInput;

        switch (menuInput) {
        case 'l': {
            string id, password;
            cout << "Enter your id: ";
            cin >> id;
            cout << "Enter your password: ";
            cin >> password;

            bool loggedIn = false;
            BankAccount* currentAccount = nullptr;
            for (BankAccount &account : accounts) {
                if (account.login(id, password)) {
                    loggedIn = true;
                    currentAccount = &account;
                    break;
                }
            }

            if (loggedIn) {
                cout<<"Access Granted !"<<endl;
                while (true) {
                    printMainMenu();
                    cin >> menuInput;

                    switch (menuInput) {
                    case 'd': {
                        double amount;
                        cout << "Enter the amount to deposit: $ ";
                        cin >> amount;
                        currentAccount->deposit(amount);
                        break;
                    }
                    case 'w': {
                        double amount;
                        cout << "Enter the amount to withdraw: $ ";
                        cin >> amount;
                        if (currentAccount->withdraw(amount)) {
                            cout << "Withdrawal successful.\n";
                        } else {
                            cout << "Insufficient balance.\n";
                        }
                        break;
                    }
                    case 'r': {
                        cout << "Your balance is : $ " << currentAccount->getBalance() << endl;
                        break;
                    }
                    case 'q': {
                        cout<<"Thanks for stopping by!";
                        menuInput ='q';
                        break;
                    }
                    default: {
                        cout << "Invalid option.\n";
                        break;
                    }
                    }
        if (menuInput == 'q') break;
                }
            } else {
                cout << "*******LOGIN FAILED !*******\n";
            }
            break;
        }
        case 'c': {
            string id, password;
            cout << "Enter your id: ";
            cin >> id;
            cout << "Enter your password: ";
            cin >> password;

            accounts.push_back(BankAccount(id, password));
            cout << "Thank you! your account has been Created !\n";
            break;
        }
        case 'q': {
            exit(0);
        }
        default: {
            cout << "Invalid option.\n";
        }
        }
    }
}

int main() {
    cout<<"Hi! Welcome to Mr.Zamar's ATM Machine!"<<endl;
    start();
    return 0;
}
