#include "qb_lexer.hpp"
#include <iostream>
#include <fstream>

QB_Lexer::QB_Lexer(const std::string file_name)
{
    m_token.type = TOKEN_EOF;
    m_token.name = "";
    m_token.file_name = file_name;
}

QB_Lexer::~QB_Lexer()
{
    std::cout << "[INFO]: Exit" << std::endl;
    std::exit(69);
}

void QB_Lexer::p_ParseFile()
{
    static std::ifstream fs;
    std::string line = "";

    fs.open(m_token.file_name);

    if(!fs.is_open()) {
        std::cout << "Could not open file" << std::endl;
        return;
    }

    while(std::getline(fs, line)){
        m_token.collect.emplace_back(line);
    }

    for (auto x : m_token.collect) {
        std::cout << x << std::endl;
    }

    fs.close();
}

Lexer::QB_Pos p_IsDigit()
{
    std::cout << "p_IsDigit()" << std::endl;
    std::exit(69);
}
