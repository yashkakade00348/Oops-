#include <iostream>
#include <utility>
using namespace std;

class A {
    int* x;
public:
    A() {
        x = new int(0);
    }
    A(int a) {
        x = new int(a);
    }
    ~A() {
        delete x;
    }
    A(const A &obj) {
        x = new int(*obj.x);
    }
    A& operator=(const A &obj) {
        if (this != &obj) {
            delete x;
            x = new int(*obj.x);
        }
        return *this;
    }
    A(A &&obj) noexcept {
        x = obj.x;
        obj.x = nullptr;
    }
    A& operator=(A &&obj) noexcept {
        if (this != &obj) {
            delete x;
            x = obj.x;
            obj.x = nullptr;
        }
        return *this;
    }
    void print() {
        if (x != nullptr)
            cout << *x << endl;
    }
};

int main() {
    A obj1;
    obj1.print();
    A obj2(5);
    obj2.print();
    A obj3(obj2);
    obj3.print();
    A obj4(std::move(obj2));
    obj4.print();
    return 0;
}
