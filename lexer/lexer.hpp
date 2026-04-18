#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <string>
#include <vector>

enum TokenType {
    Identifier,
    Number,
    String,
    Keyword,
    Puntuaction,
    Operator,
    OpenParen,
    CloseParen,
    OpenKey,
    CloseKey,
};

struct Token {
    std::string lexema;
    TokenType tipo_de_token;
    int line;
    int pos;
};

struct Lexer {
    int line;
    int pos;
};

struct Lexer lexer;

bool esNumero(std::string &Cadena) {
    for (auto a : Cadena) {
        if (!isdigit(a)) return false;
    }

    return !Cadena.empty();

}

std::string tipoDeTokenAString(TokenType tipo) {
    switch(tipo) {
        case 0: return "TOKEN_IDENTIFIER";
        case 1: return "TOKEN_NUMBER";
        case 2: return "TOKEN_STRING";
        case 3: return "TOKEN_KEYWORD";
        case 4: return "TOKEN_PUNTUACTION";
        case 5: return "TOKEN_OPERATOR";
        case 6: return "TOKEN_OPEN_PAREN";
        case 7: return "TOKEN_CLOSE_PAREN";
        case 8: return "TOKEN_OPEN_KEY";
        case 9: return "TOKEN_CLOSE_KEY";
        default: return "TOKEN_UNKNOWN";
    }
}

std::vector<Token> tokenize(std::string &CodigoFuente) {
    std::vector<Token> tokens = {};
    std::string buf = "";

    lexer.line++;

    for (int i = 0; i < CodigoFuente.size(); ++i) {
        lexer.pos++;     
        
        if (std::isalpha(CodigoFuente[i])) {
            buf += CodigoFuente[i];
        } else if (std::isdigit(CodigoFuente[i])) {
            buf += CodigoFuente[i];
        }

        else if (CodigoFuente[i] == '=' || CodigoFuente[i] == '"' || CodigoFuente[i] == '>' || CodigoFuente[i] == '-' || CodigoFuente[i] == '+' || CodigoFuente[i] == '-' || CodigoFuente[i] == '*' || CodigoFuente[i] == '/') {
            buf += CodigoFuente[i];
        }

        else if (std::isspace(CodigoFuente[i]) || CodigoFuente[i] == ';' || CodigoFuente[i] == ':' || CodigoFuente[i] == '{' || CodigoFuente[i] == '}' || CodigoFuente[i] == '(' || CodigoFuente[i] == ')') {
            

            if (buf == "int") {
                tokens.push_back({buf, TokenType::Keyword, lexer.line, lexer.pos});
                buf = "";
            }

            if (buf == "->") {
                tokens.push_back({buf, TokenType::Operator, lexer.line, lexer.pos});
                buf = "";
            }

            else if (buf == "string") {
                tokens.push_back({buf, TokenType::Keyword, lexer.line, lexer.pos});
                buf = "";
            }

            else if (buf == "float") {
                tokens.push_back({buf, TokenType::Keyword, lexer.line, lexer.pos});
                buf = "";
            }

            else if (esNumero(buf)) {
                tokens.push_back({buf, TokenType::Number, lexer.line, lexer.pos});
                buf = "";
            }

            else if (buf == "if") {
                tokens.push_back({buf, TokenType::Keyword, lexer.line, lexer.pos});
                buf = "";
            }

            else if (buf == "else") {
                tokens.push_back({buf, TokenType::Keyword, lexer.line, lexer.pos});
                buf = "";
            }

            else if (buf == "function") {
                tokens.push_back({buf, TokenType::Keyword, lexer.line, lexer.pos});
                buf = "";
            }
        
            else if (buf == "return") {
                tokens.push_back({buf, TokenType::Keyword, lexer.line, lexer.pos});
                buf = "";
            }

            else if (buf == "==") {
                tokens.push_back({"==", TokenType::Operator, lexer.line, lexer.pos});
                buf = "";
            }

            else if (buf == "++") {
                tokens.push_back({"++", TokenType::Operator, lexer.line, lexer.pos});
                buf = "";
            }

            else if (buf == "//") {
                // Los compiladores ignoran los comentarios, en este caso, se supone que toda la línea está comentada, así que hacemos un break para después saltar a la siguiente línea
                break;
            }

            else if (buf == "L") {
                tokens.push_back({buf, TokenType::String, lexer.line, lexer.pos});
                buf = "";

            }

            else if (buf == "") {

            }
            
            else {
                tokens.push_back({buf, TokenType::Identifier, lexer.line, lexer.pos});
                buf = "";
            }
           
            if (CodigoFuente[i] == ';') {
                tokens.push_back({";", TokenType::Puntuaction, lexer.line, lexer.pos});
                buf = "";
            }

            if (CodigoFuente[i] == ':') {
                tokens.push_back({":", TokenType::Puntuaction, lexer.line, lexer.pos});
                buf = "";
            }

            if (CodigoFuente[i] == '.') {
                tokens.push_back({".", TokenType::Puntuaction, lexer.line, lexer.pos});
                buf = "";
            }

            if (CodigoFuente[i] == ',') {
                tokens.push_back({",", TokenType::Puntuaction, lexer.line, lexer.pos});
                buf = "";
            }

            if (CodigoFuente[i] == '+') {
                tokens.push_back({"+", TokenType::Operator, lexer.line, lexer.pos});
                buf = "";
            }

            if (CodigoFuente[i] == '-') {
                tokens.push_back({"-", TokenType::Operator, lexer.line, lexer.pos});
                buf = "";
            }

            if (CodigoFuente[i] == '*') {
                tokens.push_back({"*", TokenType::Operator, lexer.line, lexer.pos});
                buf = "";
            }

            if (CodigoFuente[i] == '"') {
                tokens.push_back({buf, TokenType::String, lexer.line, lexer.pos});
                buf = "";
            }

            if (CodigoFuente[i] == '/') {
                tokens.push_back({"/", TokenType::Operator, lexer.line, lexer.pos});
                buf = "";
            }

            /*
            if (CodigoFuente[i] == '=') {
                tokens.push_back({"=", TokenType::Operator, lexer.line, lexer.pos});
                buf = "";
            }
            */

            if (CodigoFuente[i] == '(') {
                tokens.push_back({"(", TokenType::OpenParen, lexer.line, lexer.pos});
                buf = "";
            }

            if (CodigoFuente[i] == ')') {
                tokens.push_back({")", TokenType::CloseParen, lexer.line, lexer.pos});
                buf = "";
            }

            if (CodigoFuente[i] == '{') {
                tokens.push_back({"{", TokenType::OpenKey, lexer.line, lexer.pos});
                buf = "";
            }

            if (CodigoFuente[i] == '}') {
                tokens.push_back({"}", TokenType::CloseKey, lexer.line, lexer.pos});
                buf = "";
            }

            

        } else {
            std::cerr << "CARÁCTER DESCONOCIDO: LINEA: " << lexer.line << std::endl;
            exit(1);
        }

    }

    lexer.pos = 0;

    return tokens;
}

#endif