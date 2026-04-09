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
        if (tokens[a] == token_char[0]) {
            if (tokens[a+1] == token_char[1]) {
                if (tokens[a+2] == token_char[2]) {
                    token_char_offset = 4;
                }
            }
        }

        /*
        for (int i = 0; i < len_total_de_tokens; ++i) {
            if ()
        }
        */

        /* Verificación del token int */
       // for (auto b : token_int) {
            // if (a == b) {
                // token_int_offset++;
                // cout << token_int_offset;
            // }
       // }

       /* Verificación del token char */
      //  for (auto b : token_char) {
           //  if(a == b) {
               //  token_char_offset++;
           //  }
      //  }

       /* Verificación del token #import */
       // for (auto b : token_import) {
            // if (a == b) {
                // token_import_offset++;
            // }
       // }

       /* Verificación del token void */
       // for (auto b : token_void) {
            // if (a == b) {
                // token_void_offset++;
            // }
       // }

    }

    /*
    cout << endl << endl;
    cout << "Tokens: " << offset << " en total" << endl;
    */

    if (token_int_offset == 3) {cout << "El token int ha sido DETECTADO" << endl; token_int_detectado = true;}
    if (token_char_offset == 4) {cout << "El token char ha sido DETECTADO" << endl; token_char_detectado = true;}
    if (token_import_offset == 7) {cout << "El token #import ha sido DETECTADO" << endl; token_import_detectado = true;}
    if (token_void_offset == 4) {cout << "El token void ha sido DETECTADO" << endl; token_void_detectado = true;}

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