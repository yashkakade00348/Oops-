#include <iostream>
using namespace std;

class Account {
private:
    int id = 1234;

protected:
    int balance = 0;

public:
    void deposit(int amount) {
        balance += amount;
    }

    void show() {
        cout << "ID: " << id << " | Balance: Rs " << balance << endl;
    }
};

class Savings : public Account {
public:
    void addBonus() {
        balance += 50;
    }
};

int main() {
    Savings MyAcc;
    MyAcc.deposit(100);
    MyAcc.addBonus();
    MyAcc.show();

    return 0;
}
