// Este programa está hecho para que MiniCompiler lo compile
// Básicamente, en este programa en una variable guardamos el estado de salida que deseamos que se retorne, y hacemos un return de esa variable

start:
    int exitStatus -> 255; // Rango 0-255 bits
    exitStatus = 0; // Ponemos como nuevo valor a la variable exitStatus 0
    return exitStatus; // Retornamos el valor de la variable exitStatus