#include <iostream>

int getValue()
{
    return 3;
}

int main()
{
    int value = getValue();
    std::cout << "value: " << value << std::endl;
}