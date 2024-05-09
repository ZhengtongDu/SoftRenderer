#include <iostream>
#include "Application.h"

int main() {
    // Application app = Application();
    // app.run();

    // test for loop grammar in c++11
    double m[15];
    for (auto &x : m)
        x = 100;
    for (auto x : m)
        std::cout << x << std::endl;

    return 0;
}
