#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unistd.h>

using namespace std;

vector<char> tokens = {};

vector<char> token_int = {'i', 'n', 't'};
vector<char> token_char = {'c', 'h', 'a', 'r'};
vector<char> token_import = {'#', 'i', 'm', 'p', 'o', 'r', 't'};
vector<char> token_void = {'v', 'o', 'i', 'd'};

bool token_int_detectado = false;
bool token_char_detectado = false;
bool token_import_detectado = false;
bool token_void_detectado = false;

int token_int_offset = 0;
int token_char_offset = 0;
int token_import_offset = 0;
int token_void_offset = 0;

int offset = 0;

void tokenize(string codigo) {
    for (auto a : codigo) {
        if (a != ' ') {
            tokens.push_back(a);

        } else if (a == ' ') {
            tokens.push_back(' ');
        }
    }


    ofstream Compilado("result.mc");
    for (auto a : tokens) {
        offset++;
        // Compilado << a;
        cout << "Token " << offset << ": " << a << endl;

        /* Verificación de tokens */

        /* Verificación del token de int */
       for (auto b : token_int) {
            if (a == b) {
                token_int_offset++;
                // cout << token_int_offset;
            }
       }

       /* Verificación del token de char */
       for (auto b : token_char) {
            if(a == b) {
                token_char_offset++;
            }
       }

    }

    /*
    cout << endl << endl;
    cout << "Tokens: " << offset << " en total" << endl;
    */

    if (token_int_offset == 3) {cout << "El token int ha sido DETECTADO" << endl;}
    if (token_char_offset == 4) {cout << "El token char ha sido DETECTADO" << endl;}

}

int main() {
    cout << "COMPILACIÓN EN PROCESO..." << endl << endl;
    sleep(1);
    string codigo;
    ifstream Archivo("program.mc");

    while(getline(Archivo, codigo)) {
        tokenize(codigo);
    }

}