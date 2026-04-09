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

int len_total_de_tokens = 18;

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
    for (int a = 0; a < tokens.size(); ++a) {
        offset++;
        // Compilado << a;
        cout << "Token " << offset << ": " << tokens[a] << endl;

        /* Verificación de tokens */

        /* Verificación del token char */
        if (tokens[a] == token_char[0]) { // c
            if (tokens[a+1] == token_char[1]) { // h
                if (tokens[a+2] == token_char[2]) { // a
                    if (tokens[a+3] == token_char[3]) { // r
                        token_char_offset = 4;
                        token_char_detectado = true;
                        cout << "TOKEN CHAR DETECTADO" << endl;
                    }
                }
            }
        }

        /* Verificación del token int */
        if (tokens[a] == token_int[0]) { // i
            if (tokens[a+1] == token_int[1]) { // n
                if (tokens[a+2] == token_int[2]) { // t
                    token_int_offset = 3;
                    token_int_detectado = true;
                    cout << "TOKEN INT DETECTADO" << endl;
                }
            }
        }

        /* Verificación del token #import */
        if (tokens[a] == token_import[0]) { // #
            if (tokens[a+1] == token_import[1]) { // i
                if (tokens[a+2] == token_import[2]) { // m
                    if (tokens[a+3] == token_import[3]) { // p
                        if (tokens[a+4] == token_import[4]) { // o
                            if (tokens[a+5] == token_import[5]) { // r
                                if (tokens[a+6] == token_import[6]) { // t
                                    token_import_offset = 7;
                                    token_import_detectado = true;
                                    cout << "TOKEN #IMPORT DETECTADO" << endl;
                                }
                            }
                        }
                    }
                }
            }
        }

        /* Verificación del token void */
        if (tokens[a] == token_void[0]) { // v
            if (tokens[a+1] == token_void[1]) { // o
                if (tokens[a+2] == token_void[2]) { // i
                    if (tokens[a+3] == token_void[3]) { // d
                        token_void_offset = 4;
                        token_void_detectado = true;
                        cout << "TOKEN VOID DETECTADO" << endl;
                    }
                }
            }
        }

    }

    cout << endl << endl;
    cout << "Tokens: " << offset << " tokens en total" << endl;

    /*
    if (token_int_offset == 3) {cout << "El token int ha sido DETECTADO" << endl; token_int_detectado = true;}
    if (token_char_offset == 4) {cout << "El token char ha sido DETECTADO" << endl; token_char_detectado = true;}
    if (token_import_offset == 7) {cout << "El token #import ha sido DETECTADO" << endl; token_import_detectado = true;}
    if (token_void_offset == 4) {cout << "El token void ha sido DETECTADO" << endl; token_void_detectado = true;}
    */

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