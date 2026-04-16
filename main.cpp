#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "lexer/lexer.hpp"

int main() {
    std::string codigo_fuente = "int 1234;char^"; // El carácter ^ indica el fin del programa
    std::vector<Token> tokens = tokenize(codigo_fuente);

    for (auto a : tokens) {
        std::cout << a.value << " => Tipo: " << tokenAString(a.type) << " | Linea: " << a.line << " | Pos: " << a.pos << std::endl;
    }

}