#pragma once

#include <string>
#include <vector>

enum QB_TokenType {
    TOKEN_EOF = 1,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
};

namespace Lexer {
    struct QB_Pos {
        std::string start;
        std::string end;
    };
}

struct QB_Token {
    QB_TokenType type;
    Lexer::QB_Pos pos;
    Lexer::QB_Pos p_IsAlpha();
    std::string name;
    std::string file_name;
    std::vector<std::string> collect;
};

class QB_Lexer {
    public:
        QB_Lexer(const std::string file_name);
        Lexer::QB_Pos p_IsDigit();
        void p_ParseFile();
        ~QB_Lexer();
    private:
        QB_Token m_token;
};
