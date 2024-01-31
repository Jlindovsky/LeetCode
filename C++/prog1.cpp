#include <iostream>

int main()
{
    // int age1{2.0}; error narrowing
    int age1(2.0); // make it 2
    int age2 = -23;

    int age3{age1 + age2};
    std::string fullName;
    std::string Name;

    std::cout << "write your full name" << std::endl;
    std::getline(std::cin, fullName); // to work with spaces

    std::cout << "write your name" << std::endl;
    std::cin >> Name; // take string only to space

    std::cout << fullName << std::endl;
    std::cout << Name << " this is your age: " << age1 << std::endl;

    std::cerr << "error message" << std::endl;
    std::clog << "log message" << std::endl;

    std::cout << "write your name and age" << std::endl;
    std::cin >> Name; // take string only to space
    std::cin >> age2; // take string only to space, so can write on one line with space

    std::cout << Name << " this is your age: " << age2 << std::endl;

    return 0;
}