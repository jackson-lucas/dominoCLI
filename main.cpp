
// mostrar mesa
// mostrar placar
// aguardar movimento
#include "Mesa.h"
#include "Pedra.h"
#include "Partida.h"
#include "Jogador.h"

void iniciar() {
    cin >> (jogadores[0]).nome >> jogadores[1].nome >> jogadores[2].nome >> jogadores[3].nome;
    cout << endl << "Partida acaba de iniciar" << endl;
    cout << "As duplas são:" << endl;
    cout << jogadores[0].nome << " e " << jogadores[2].nome << endl;
    cout << jogadores[1].nome << " e " << jogadores[3].nome << endl;
    cout << "Quem tiver a maior carroça inicie o jogo" << endl;
}

void aguardarMovimento() {

}

main () {

}