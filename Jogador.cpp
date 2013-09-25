#include <string>
#include "Jogador.h"
#include <list>
#include "Pedra.h"

using namespace std;

void Jogador::setPedrasNaMao(list<Pedra> pedras) {
    pedrasNaMao = pedras;
}

void Jogador::setPontos(int pontos_) {
    pontos = pontos_;
}

void Jogador::setNome(string nome_) {
    nome = nome_;
}

int Jogador::getPontos() {
    return pontos;
}

string Jogador::getNome(){
    return nome;
}

list<Pedra> Jogador::getPedrasNaMao(){
    return pedrasNaMao;
}
