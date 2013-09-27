#include <string>
#include "Jogador.h"
#include <list>
#include "Pedra.h"
#include <iostream>

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

int Jogador::garagem() {
	list<Pedra>::iterator pedra;
	int pontos = 0;
	for(pedra = pedrasNaMao.begin(); pedra!=pedrasNaMao.end(); pedra++) {
		pontos += (*pedra).pontosNaPedra();
	}
	return pontos;
}

bool Jogador::existePedraNaMao(Pedra pedraEscolhida) {
    list<Pedra>::iterator pedra;
    for(pedra = pedrasNaMao.begin(); pedra!=pedrasNaMao.end(); pedra++) {
        if (((*pedra).getNaipe(1) == pedraEscolhida.getNaipe(1)) and ((*pedra).getNaipe(2) == pedraEscolhida.getNaipe(2))) {
            return true;
        } else if(((*pedra).getNaipe(2) == pedraEscolhida.getNaipe(1)) and ((*pedra).getNaipe(1) == pedraEscolhida.getNaipe(2))) {
            return true;
        }
    }
    return false;
}

bool Jogador::removerPedraNaMao(Pedra pedraParaRemover) {
    list<Pedra>::iterator pedra;
    for(pedra = pedrasNaMao.begin(); pedra!=pedrasNaMao.end(); pedra++) {
        if (((*pedra).getNaipe(1) == pedraParaRemover.getNaipe(1)) and ((*pedra).getNaipe(2) == pedraParaRemover.getNaipe(2))) {
            cout << "removendo (" << (*pedra).getNaipe(1) << "," << (*pedra).getNaipe(2) << ")" << endl;
        	pedra = pedrasNaMao.erase(pedra);
            return true;
        } else if (((*pedra).getNaipe(1) == pedraParaRemover.getNaipe(2)) and ((*pedra).getNaipe(2) == pedraParaRemover.getNaipe(1))) {
            cout << "removendo (" << (*pedra).getNaipe(1) << "," << (*pedra).getNaipe(2) << ")" << endl;
            pedra = pedrasNaMao.erase(pedra);
            return true;
        }
    }
    cout << "nenhuma pedra removida" << endl;
    return false;
}