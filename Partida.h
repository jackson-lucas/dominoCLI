#ifndef Partida_h
#define Partida_h
#include "Mesa.h"
#include "Jogador.h"
#include "Pedra.h"

using namespace std;

class Partida {
    Jogador jogador1;
    Jogador jogador2;
    Jogador jogador3;
    Jogador jogador4;
    int turno;
    Mesa mesa;
    int algoritmo_randomico (int i);
    list<Pedra> criarPedras();
    public:
        void setJogador(int index, Jogador p1);
        Jogador getJogador(int index);
        void limparMesa();
        void iniciarPartida(Jogador p1, Jogador p2, Jogador p3, Jogador p4);
};
#endif