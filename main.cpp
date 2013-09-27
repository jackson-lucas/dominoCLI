#include "Mesa.h"
#include "Pedra.h"
#include "Partida.h"
#include "Jogador.h"
#include <string>
#include <iostream>


main () {
    Partida p1;
    string movimento, auxiliar;
    p1.iniciar();
    while(1) {
        cin >> movimento;
        auxiliar = movimento;
        getline(cin, movimento);
        movimento = auxiliar + movimento;
        p1.aguardarMovimento(movimento);
    }
}