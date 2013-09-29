#ifndef Partida_h
#define Partida_h
#include "Mesa.h"
#include "Jogador.h"
#include "Pedra.h"
#include <string>

using namespace std;

class Partida {
    Jogador jogador1;
    Jogador jogador2;
    Jogador jogador3;
    Jogador jogador4;
    bool inicioComSena;
    int turno;
    Mesa mesa;
    int algoritmoRandomico (int i);
    void setJogador(int index, Jogador p1);
    Jogador getJogador(int index);
    list<Pedra> criarPedras();
    void mostrarTurno();
    void limparMesa();
    void distribuirPedras();
    bool checarMaoDoJogadorEstaVazia(int index);
    bool temPalavrasReservadas(string nome);
    void mostrarPlacar();
    bool terminouJogo();
    int garagemParaJogador(int index);
    void maiorGaragem();
    void jogadaInvalida();
    bool validarJogada(string movimento, Pedra pedra);
    void finalizar();
    void encontrar6x6();
    void mostrarMao();
    bool vaiPassar(int index);
    public:
        void iniciar();
        void aguardarMovimento(string movimento);
};
#endif