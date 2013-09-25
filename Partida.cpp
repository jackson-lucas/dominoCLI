#include <list>
#include <vector>
#include <algorithm> // random_shuffle
#include <ctime>     // time
#include <cstdlib>   // rand, srand
#include "Partida.h"
#include "Pedra.h"

using namespace std;

int Partida::algoritmo_randomico (int i) { 
    srand (unsigned(time(0)));
    return rand() % i; 
}

void Partida::setJogador(int index, Jogador p1) {
    switch (index) {
        case 1:
            jogador1 = p1;
            break;
        case 2:
            jogador2 = p1;
            break;
        case 3:
            jogador3 = p1;
            break;
        case 4:
            jogador4 = p1;
    }
}

Jogador Partida::getJogador(int index) {
    switch (index) {
        case 1:
            return jogador1;
            break;
        case 2:
            return jogador2;
            break;
        case 3:
            return jogador3;
            break;
        case 4:
            return jogador4;
    }
}

void Partida::limparMesa() {
    list<Pedra> lista;
    mesa.setPonta(1, lista);
    mesa.setPonta(2, lista);
    mesa.setPonta(3, lista);
    mesa.setPonta(4, lista);
}

void Partida::iniciarPartida(Jogador p1, Jogador p2, Jogador p3, Jogador p4) {
    list<Pedra> lista;
    p1.setPontos(0);
    p2.setPontos(0);
    p3.setPontos(0);
    p4.setPontos(0);
    p1.setPedrasNaMao(lista);
    p2.setPedrasNaMao(lista);
    p3.setPedrasNaMao(lista);
    p4.setPedrasNaMao(lista);
    setJogador(1, p1);
    setJogador(2, p2);
    setJogador(3, p3);
    setJogador(4, p4);
}

// distribuir pedras
// contar_garagem
// encontrar6x6
// checarMaoDoJogador verificar se não está vazia
// proximoTurno
// colocarPedraNaMesa
list<Pedra> Partida::criarPedras() {
    list<Pedra> pedras;
    Pedra pedra;
    int contador=0;
    for(int i = 0; i < 7; i++, contador++) {
        for(int j=0+contador; j < 7; j++) {
            pedra.setNaipes(i,j);
            pedras.push_back(pedra);
        }
    }
    vector<Pedra> vetor(pedras.begin(), pedras.end());
    random_shuffle (vetor.begin(), vetor.end());
    pedras.clear();
    pedras = list<Pedra>(vetor.begin(), vetor.end());
    return pedras;
}

main() {
    
}