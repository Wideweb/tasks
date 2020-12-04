#include "saber.hpp"

#include <iostream>

int main() {
    Saber::to_binary(-9, Saber::Endian::big, std::cout);
    std::cout << std::endl;
}
