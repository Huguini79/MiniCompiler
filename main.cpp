#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "lexer/lexer.hpp"

int main() {
    std::ifstream CodigoFuente("program.mc");

    std::string s;

    std::cout << "COMPILACIÓN EN PROCESO" << std::endl << std::endl;

    while (std::getline(CodigoFuente, s)) {
        std::vector<Token> tokens = tokenize(s);

        for (auto a : tokens) {
            std::cout << "{Lexema: " << a.lexema << " -> Tipo de TOKEN: " << tipoDeTokenAString(a.tipo_de_token) << " | Linea: " << lexer.line << "}" << std::endl;
        }

        std::cout << std::endl;

    }

}