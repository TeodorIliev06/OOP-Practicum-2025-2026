#include <iostream>
#include "Container.h"

int main()
{
    Container c;

    std::cin >> c;

    Entry e1("BookA", "id1", 10.0, 1.0);
    Entry e2("BookB", "id2", 20.0, 2.0);
    Entry e3("BookC", "id3", 5.0, 0.5);

    c += e1;
    c += e2;
    c += e3;

    if (c) {
        std::cout << "Yes\n";
    }
    else {
        std::cout << "No\n";
    }

    return 0;
}
