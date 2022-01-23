#include <iostream>
#include "TemplateSet.h"

int main()
{
    TemplateSet<int> mySet;

    mySet.insert(1);
    mySet.insert(-15);
    mySet.insert(25);
    mySet.insert(10);
    mySet.insert(8);
    mySet.insert(2);
    mySet.insert(8); // Duplicated item is not inserted

    std::cout << mySet << std::endl;

    // Remove item that doesn't exist
    mySet.erase(150);

    std::cout << mySet << std::endl;

    mySet.erase(1);
    mySet.erase(10);
    mySet.erase(2);

    std::cout << mySet << std::endl;

    return 0;
}
