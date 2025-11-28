#include <iostream>
#include "qb_lexer.hpp"

int main(int argc, char **argv)
{
    if(argc < 2) {
        std::cout << "[ERROR] Need more arguments" << std::endl;
        std::exit(69);
    }

    const std::string file(argv[1]);
    std::cout << file << std::endl;
    QB_Lexer qb(file);
}
