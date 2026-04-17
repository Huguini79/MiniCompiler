#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "../lexer/lexer.hpp"

void process(std::vector<Token> &tokens, std::ofstream &Compilado) {
    for (int i = 0; i < tokens.size(); ++i) {
        if (tokens[0].lexema == "return" 
            && tokens[0].tipo_de_token == TokenType::Keyword) {
            if (tokens[1].tipo_de_token == TokenType::Number || tokens[1].tipo_de_token == TokenType::Identifier) {
                Compilado << "    return " << tokens[1].lexema << ";" << std::endl;;
                break;
            }
        }

        // Declaración de una variable int 
        else if (tokens[0].lexema == "int"
                && tokens[0].tipo_de_token == TokenType::Keyword
                && tokens[1].tipo_de_token == TokenType::Identifier
                && tokens[2].lexema == ";"
                && tokens[2].tipo_de_token == TokenType::Puntuaction) {
                Compilado << "    int " << tokens[1].lexema << ";" << std::endl;
                break;
        }

        // Declaración del punto de entrada del programa
        else if (tokens[0].lexema == "start"
            && tokens[0].tipo_de_token == TokenType::Identifier
            && tokens[1].tipo_de_token == TokenType::Puntuaction) {
                Compilado << "int main() {" << std::endl;
                break;
            }

        // Declaración de una variable int con un valor definido;
        else if (tokens[0].lexema == "int" 
            && tokens[0].tipo_de_token == TokenType::Keyword 
            && tokens[1].tipo_de_token == TokenType::Identifier 
            && tokens[2].lexema == "=" && tokens[2].tipo_de_token == TokenType::Identifier || tokens[2].lexema == "->" && tokens[2].tipo_de_token == TokenType::Identifier
            && tokens[3].tipo_de_token == TokenType::Number 
            && tokens[4].lexema == ";" 
            && tokens[4].tipo_de_token == TokenType::Puntuaction) {
                Compilado << "    int " << tokens[1].lexema << " = " << tokens[3].lexema << ";" << std::endl;
                break;
        }

        // Declaración de una función sin parámetros
        else if (tokens[0].lexema == "function"
            && tokens[0].tipo_de_token == TokenType::Keyword
            && tokens[1].tipo_de_token == TokenType::Identifier
            && tokens[2].tipo_de_token == TokenType::OpenParen
            && tokens[3].tipo_de_token == TokenType::CloseParen
            && tokens[4].tipo_de_token == TokenType::OpenKey
            && tokens[5].tipo_de_token == TokenType::CloseKey) {
                Compilado << "void " << tokens[1].lexema << " () {}" << std::endl;
                break;
            }

    }


}

#endif