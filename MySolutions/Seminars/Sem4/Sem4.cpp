#include <iostream>
#include <print>
//class Cache {
//    mutable int accessCount = 0;
//    int value = 42;
//
//public:
//    int get() const {
//        accessCount++;
//        return value;
//    }
//
//    void report() const {
//        std::cout << "Accessed " << accessCount << " times" << std::endl;
//    }
//};
//
//int main() {
//    const Cache c;
//    c.get();
//    c.get();
//    c.report();
//}

class Human {
public:
	Human() { std::print("Human() "); }
	~Human() { std::print("~Human() "); }

};

int main() {
	Human* arr[5];
}