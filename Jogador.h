#ifndef Jogador_h
#define Jogador_h
#include <string>
#include <list>
#include "Pedra.h"

using namespace std;

class Jogador {
    list<Pedra> pedrasNaMao;
    string nome;
    int pontos;
    public:
        void setPedrasNaMao(list<Pedra> pedras);
        void setPontos(int pontos_);
        void setNome(string nome_);
        int getPontos();
        string getNome();
        list<Pedra> getPedrasNaMao();
        int garagem();
        bool existePedraNaMao(Pedra pedraEscolhida);
        bool removerPedraNaMao(Pedra pedraParaRemover);
};

#endif
