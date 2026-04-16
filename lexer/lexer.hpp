//
// Created by Hugo González Ruiz on 12/04/2026.
//

#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <cctype>
#include <vector>
#include <string>

// Frontend (Lexer)

// Tipos de tokens
enum TokenType {
    Identifier, // hola()  cout  declaración de una variable (x = ....)
    Keyword,    // if  else  do  while
    Operator, // <= << >> == = + * - /
    Literal, // 1234567890  Hola
    Punctuation, // ;  .  ,
};

// Estructura de un token
struct Token {
    int line;
    int pos;
    std::string value; // lexema
    TokenType type; // Tipo de token
};

struct Lexer {
    int line;
    int pos;
    int word_offset;
    std::string buf;
};

std::string last_token = "";

struct Lexer lexer;

std::string tokenAString(enum TokenType type) {
    switch (type) {
        case 0: return "IDENTIFIER";
        case 1: return "KEYWORD";
        case 2: return "OPERATOR";
        case 3: return "LITERAL";
        case 4: return "PUNCTUATION";
        default: return "UNKNOWN";
    }
}

bool isNumber(std::string &buffer) {
    for (auto a : buffer) {
        if (!isdigit(a)) return false;
    }
    return !buffer.empty();
}

// Tokenización
std::vector<Token> tokenize(const std::string &codigo) {
    std::vector<Token> tokens;

    lexer.line++;

    for (int a = 0; a < codigo.size(); ++a) {
        lexer.pos++;

        if (std::isalpha(codigo[a])) {
            lexer.word_offset++;

            lexer.buf += codigo[a];

        } else if (std::isdigit(codigo[a])) {
            lexer.word_offset++;

            lexer.buf += codigo[a];

        } else if (std::isspace(codigo[a]) || codigo[a] == ';' || codigo[a] == '^') {
            if (lexer.buf == "int") {
                tokens.push_back({lexer.line, lexer.pos, "int", TokenType::Keyword});
                lexer.buf = "";
                last_token = "int";
            }

            if (lexer.buf == "char") {
                tokens.push_back({lexer.line, lexer.pos, "char", TokenType::Keyword});
                lexer.buf = "";
                last_token = "char";
            }

            if (isNumber(lexer.buf)) {
                tokens.push_back({lexer.line, lexer.pos, lexer.buf, TokenType::Literal});
                lexer.buf = "";
                last_token = lexer.buf;
            }

        }

        /*else {
            std::cerr << "Carácter no definido: " << "Valor: " << codigo[a] << " | Linea: " << lexer.line << " | Pos: " << lexer.pos << std::endl;
            break;

        }*/
    }

    lexer.pos = 0;

    return tokens;
}

#endif