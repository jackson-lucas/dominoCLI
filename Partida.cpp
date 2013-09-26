#include <list>
#include <iterator>
#include <vector>
#include <algorithm> // random_shuffle
#include <ctime>     // time
#include <cstdlib>   // rand, srand
#include "Partida.h"
#include "Pedra.h"

#include <iostream>

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
    p1.setPontos(0);
    p2.setPontos(0);
    p3.setPontos(0);
    p4.setPontos(0);
    setJogador(1, p1);
    setJogador(2, p2);
    setJogador(3, p3);
    setJogador(4, p4);
}

// contar_garagem
// encontrarPedra
// proximoTurno

// Verificar se não há repetição das pedras do embaralhamento
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

void Partida::distribuirPedras() {
    list<Pedra> pedras;
    list<Pedra>::iterator fim;    
    list<Pedra> mao1;
    list<Pedra> mao2;
    list<Pedra> mao3;
    list<Pedra> mao4;

    pedras = criarPedras();

    for(fim = pedras.end(); fim != pedras.begin(); fim--) {
        mao1.push_back(*fim);
        fim--;
        mao2.push_back(*fim);
        fim--;
        mao3.push_back(*fim);
        fim--;
        mao4.push_back(*fim);
    }

    jogador1.setPedrasNaMao(mao1);
    jogador2.setPedrasNaMao(mao2);
    jogador3.setPedrasNaMao(mao3);
    jogador4.setPedrasNaMao(mao4);
}    

bool Partida::checarMaoDoJogadorEstaVazia(int index) {
    switch (index) {
        case 1:
            return jogador1.getPedrasNaMao().empty();
            break;
        case 2:
            return jogador2.getPedrasNaMao().empty();
            break;
        case 3:
            return jogador3.getPedrasNaMao().empty();
            break;
        case 4:
            return jogador4.getPedrasNaMao().empty();
    }   
}

main() {
    Partida p1;
    p1.distribuirPedras();
}