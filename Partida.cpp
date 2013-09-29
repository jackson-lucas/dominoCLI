#include <list>
#include <iterator>
#include <vector>
#include <algorithm> // random_shuffle
#include <ctime>     // time
#include <cstdlib>   // rand, srand
#include "Partida.h"
#include "Pedra.h"
#include <string>
#include <iostream>
#include <array>

using namespace std;

int Partida::algoritmoRandomico (int i) { 
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

void Partida::mostrarTurno() {
    cout << "Turno: " << turno << ", É a vez do jogador: "<< getJogador(turno).getNome() << endl;
}

list<Pedra> Partida::criarPedras() {
    list<Pedra> pedras;
    Pedra pedra;
    int contador=0;

    algoritmoRandomico(6000);

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

    for(fim = pedras.begin(); fim != pedras.end(); fim++) {
        mao1.push_back(*fim);
        fim++;
        mao2.push_back(*fim);
        fim++;
        mao3.push_back(*fim);
        fim++;
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
    return false;
}

void Partida::encontrar6x6() {
    Pedra carroca6;
    carroca6.setNaipes(6,6);
    if(jogador1.existePedraNaMao(carroca6)) {
        turno = 1;
    }
    if(jogador2.existePedraNaMao(carroca6)) {
        turno = 2;
    }
    if(jogador3.existePedraNaMao(carroca6)) {
        turno = 3;
    }
    if(jogador4.existePedraNaMao(carroca6)) {
        turno = 4;
    }

}

bool Partida::temPalavrasReservadas(string nome) {
    array<string,6> palavrasReservadas = {"placar", "jogar", "mesa", "mao", "turno", "ajuda"};
    for(int i=0; i<6; i++) {
        if(nome.find(palavrasReservadas[i]) != -1) {
            return true;
        }
    }
    return false;
}

void Partida::iniciar() {
    string nome1, nome2, nome3, nome4;
    cout << "Insira o nome dos 4 jogadores que jogarão Dominó por Linha de Comando xD" << endl;
    cout << "Exemplo: Pimpão Adelícia Queiroga Timótio" << endl;
    cin >> nome1 >> nome2 >> nome3 >> nome4; 
    jogador1.setNome(nome1); 
    jogador2.setNome(nome2); 
    jogador3.setNome(nome3); 
    jogador4.setNome(nome4);
    
    if((!temPalavrasReservadas(nome1)) and (!temPalavrasReservadas(nome2)) and (!temPalavrasReservadas(nome3))
        and (!temPalavrasReservadas(nome4))) {
        cout << endl << "Partida acaba de iniciar" << endl;
        jogador1.setPontos(0);
        jogador2.setPontos(0);
        jogador3.setPontos(0);
        jogador4.setPontos(0);
        cout << "Os jogadores registrados são:" << endl;
        cout << jogador1.getNome() << ", " << jogador2.getNome() << ", " << jogador3.getNome() << " e " << jogador4.getNome() << endl;
        cout << "Quem tiver a maior carroça inicie o jogo" << endl;
        distribuirPedras();
        encontrar6x6();
        inicioComSena = true;
    } else {
        cout << "Nome de algum(ns) jogador(es) utiliza(m) alguma(s) palavra(s) reservada(s)" << endl;
        cout << "placar, jogar, mesa, mao, turno, ajuda são palavras reservadas!" << endl;
        cout << "Partida cancelada!" << endl;
        exit(1);
    }
    
}

void Partida::mostrarPlacar() {
    cout << "Placar: " << endl;
    cout << jogador1.getNome() << ": " << jogador1.getPontos() << endl;
    cout << jogador2.getNome() << ": " << jogador2.getPontos() << endl;
    cout << jogador3.getNome() << ": " << jogador3.getPontos() << endl;
    cout << jogador4.getNome() << ": " << jogador4.getPontos() << endl;
}

bool Partida::terminouJogo() {
    int quantosAtingiramPontuacao = 0;
    int pontos1, pontos2, pontos3, pontos4;
    pontos1 = jogador1.getPontos();
    pontos2 = jogador2.getPontos();
    pontos3 = jogador3.getPontos();
    pontos4 = jogador4.getPontos();
    if(pontos1 >= 100) {
        quantosAtingiramPontuacao++;
    }
    if(pontos2 >= 100) {
        quantosAtingiramPontuacao++;
    }
    if(pontos3 >= 100) {
        quantosAtingiramPontuacao++;
    }
    if(pontos4 >= 100) {
        quantosAtingiramPontuacao++;
    }
    // Se somente um conseguiu terminar jogo, caso contrário verificação se vai ter desempate
    if(quantosAtingiramPontuacao == 1) {
        return true;
    } else if(quantosAtingiramPontuacao > 1) {
        if(pontos1 > pontos2) {
        // Qual o maior entre os quatro
            if(pontos1 > pontos3) {
                if(pontos1 > pontos4) {
                    return true;
                } else if (pontos4 > pontos1) {
                    return true;
                }
            } else if (pontos3 > pontos1) {
                if(pontos3 > pontos4) {
                    return true;
                } else if (pontos4 > pontos3) {
                    return true;
                }
            } else if (pontos4 > pontos3) {
                return true;
            }
        } else if (pontos2 > pontos1) {
            if(pontos2 > pontos3) {
                if(pontos2 > pontos4) {
                    return true;
                } else if (pontos4 > pontos2) {
                    return true;
                }
            } else if(pontos3 > pontos2) {
                if(pontos3 > pontos4) {
                    return true;
                } else if (pontos4 > pontos3) {
                    return true;
                }
            } else if (pontos4 > pontos3) {
                return true;
            }
        } else if(pontos3 > pontos2) {
            if(pontos3 > pontos4) {
                return true;
            } else if (pontos4 > pontos3) {
                return true;
            }
        } else if (pontos4 > pontos2) {
            return true;
        }
    }
    return false;
}

int Partida::garagemParaJogador(int index) {
    int garagem = 0;
    if(index != 1) {
        garagem += jogador1.garagem();    
    }
    if(index != 2) {
        garagem += jogador2.garagem();    
    }
    if(index != 3) {
        garagem += jogador3.garagem();    
    }
    if(index != 4) {
        garagem += jogador4.garagem();    
    }
    for(; garagem%5!=0; garagem--);
    return garagem;
}

// Situação para quando o jogo fechar: O jogador que tiver a menor garagem será o jogador que terá a maior Garagem
// Com esse princípio, a função procura quem vai ter maior Garagem e coloca esse pontos para o jogador.
void Partida::maiorGaragem() {
    int maiorGaragem, garagem, index = 1;
    Jogador jogador;
    maiorGaragem = garagemParaJogador(index);
    for(int i = 2; i < 5; i++) {
        garagem = garagemParaJogador(i);
        if (garagem > maiorGaragem) {
            maiorGaragem = garagem;
            index = i;
        }
    }
    jogador = getJogador(index);
    jogador.setPontos(jogador.getPontos() + maiorGaragem);
    setJogador(index, jogador);
}

void Partida::jogadaInvalida() {
    cout << "Jogada Inválida!" << endl;
}

void Partida::finalizar() {
    cout << "O jogo acabou!" << endl;
    mostrarPlacar();
    exit(1);
}

void Partida::mostrarMao() {
    list<Pedra> mao;
    list<Pedra>::iterator pedra;
    switch (turno) {
        case 1:
            mao = jogador1.getPedrasNaMao();
            cout << jogador1.getNome() << ": [";
            for(pedra = mao.begin(); pedra!=mao.end(); pedra++) {
                cout << "(" << (*pedra).getNaipe(1) << ", " << (*pedra).getNaipe(2) << ")";
            }
            cout << "]" << endl;
            break;
        case 2:
            mao = jogador2.getPedrasNaMao();
            cout << jogador2.getNome() << ": [";
            for(pedra = mao.begin(); pedra!=mao.end(); pedra++) {
                cout << "(" << (*pedra).getNaipe(1) << ", " << (*pedra).getNaipe(2) << ")";
            }
            cout << "]" << endl;
            break;
        case 3:
            mao = jogador3.getPedrasNaMao();
            cout << jogador3.getNome() << ": [";
            for(pedra = mao.begin(); pedra!=mao.end(); pedra++) {
                cout << "(" << (*pedra).getNaipe(1) << ", " << (*pedra).getNaipe(2) << ")";
            }
            cout << "]" << endl;
            break;
        case 4:
            mao = jogador4.getPedrasNaMao();
            cout << jogador4.getNome() << ": [";
            for(pedra = mao.begin(); pedra!=mao.end(); pedra++) {
                cout << "(" << (*pedra).getNaipe(1) << ", " << (*pedra).getNaipe(2) << ")";
            }
            cout << "]" << endl;
    }
}

bool Partida::validarJogada(string movimento, Pedra pedra) {
    Jogador jogadorDaVez = getJogador(turno); // Somente o jogador do turno poderá jogar
    int pontos;
    if (pedra.getNaipe(1) >= 0 and pedra.getNaipe(1) <= 6 and pedra.getNaipe(2) >= 0 and pedra.getNaipe(2) <= 6) {
        if (movimento.find(jogadorDaVez.getNome()) != -1) {
            if(jogadorDaVez.existePedraNaMao(pedra)) {
                if(inicioComSena) {
                    if ((pedra.getNaipe(1) == 6) and (pedra.getNaipe(2) == 6)) {
                        if(mesa.colocarPedraNaMesa(pedra)) {
                            jogadorDaVez.removerPedraNaMao(pedra);
                            pontos = mesa.pontosNaMesa();
                            if(pontos % 5 == 0) {
                                jogadorDaVez.setPontos(pontos + jogadorDaVez.getPontos());
                            }
                            setJogador(turno, jogadorDaVez);
                            return true;
                        }
                    }
                } else if(mesa.colocarPedraNaMesa(pedra)) {
                    jogadorDaVez.removerPedraNaMao(pedra);
                    pontos = mesa.pontosNaMesa();
                    if(pontos % 5 == 0) {
                        jogadorDaVez.setPontos(pontos + jogadorDaVez.getPontos());
                    }
                    setJogador(turno, jogadorDaVez);
                    return true;
                }
            }
        }
    }
    jogadaInvalida();
    return false;
}

// Verificar se jogador tem pedra para jogar ou se passou
bool Partida::vaiPassar(int index) {
    Jogador jogadorDaVez = getJogador(turno);
    list<Pedra> mao = jogadorDaVez.getPedrasNaMao();
    Pedra pedraNaMesa;
    list<Pedra>::iterator iterador;
    for(int i = 1 ; i<5; i++) {
        pedraNaMesa = mesa.pedraDaPonta(i);
        for(iterador = mao.begin(); iterador!=mao.end(); iterador++) {
            if(pedraNaMesa.getNaipe(1) == (*iterador).getNaipe(1) or pedraNaMesa.getNaipe(1) == (*iterador).getNaipe(2)) {
                return false;
            }
        }
    }
    cout << jogadorDaVez.getNome() << " não tem pedra para jogar, o passe é contado automaticamente" << endl;
    return true;
}

void Partida::aguardarMovimento(string movimento) {
    int index, pontos = 0, i, garagem, turnoAnterior;
    bool acabouPartida, passar;
    Pedra pedra;
    Jogador jogadorDaVez = getJogador(turno);

    if(movimento.find("placar") != -1) {
        mostrarPlacar();
        return;
    } else if(movimento.find("turno") != -1) {
        mostrarTurno();
    } else if(movimento.find("mesa") != -1) {
        mesa.mostrarMesa();
        return;
    } else if (movimento.find("mao") != -1) {
        mostrarMao();
        return;
    } else if(movimento.find("ajuda") != -1) {
        cout << "Para mostrar o placar do jogo, digite: placar" << endl;
        cout << "Para mostrar a mesa, digite: mesa" << endl;
        cout << "Para saber de quem é a vez, digite: turno" << endl;
        cout << "Para ver a mao do jogador que está na vez, digite: mao" << endl;
        cout << "Para jogar, digite: jogar <nome do jogador> <pedra>. Exemplo: jogar " << jogadorDaVez.getNome() << " (3,3)" << endl;
        cout << "Se a jogada for válida a mesa e a pontuação atualizadas serão mostradas, caso contrário será alertado que se trata de uma jogada inválida!"<< endl;
        cout << "Caso a sua jogada tenha mais de uma ponta em que a pedra possa ser colocada, " << endl << "será perguntado em qual ponta você quer colocar, apenas digite o número correspondente a ponta."<< endl;
    } else if (movimento.find("jogar") != -1) {
        // Caso se deseje jogar, vai verificar se foi jogado alguma pedra e se a mesma é válida
        index = movimento.find("(");
        if (index != -1) {
            pedra.setNaipes((int)(movimento[index+1] - '0'),(int)(movimento[index+3] - '0'));
            if (validarJogada(movimento, pedra)) {
                mesa.mostrarMesa();
                // Se o jogador ainda tiver pedras na mao próximo turno para outro jogar caso contrário, fechar turno
                if(!(checarMaoDoJogadorEstaVazia(turno))) {
                    
                    turnoAnterior = turno;
                    // Verificação se o jogador vai passar
                    do {
                        if(inicioComSena) {
                            inicioComSena = false;
                        }
                        if (turno < 4) {
                            turno++;
                        } else {
                            turno = 1;
                        }
                        passar = vaiPassar(turno);
                        if(passar) {
                            // Bug Corrigido: Quando tinha um passe o jogador tinha sua mao sobrescrita, com isso não perdendo 
                            // a pedra jogada, para solucionar jogadorDaVez recebe novamente o jogador do turno, para atualizar a mao
                            if(((turno - turnoAnterior) == 1) or (turnoAnterior == 4 and turno == 1)) {
                                // continua sendo o jogador que acabou de jogar
                                jogadorDaVez = getJogador(turnoAnterior);
                                jogadorDaVez.setPontos(20 + jogadorDaVez.getPontos());
                                setJogador(turnoAnterior, jogadorDaVez);
                            } else if((turnoAnterior - turno == 1) or (turnoAnterior == 1 and turno == 4)) {
                                // Caracteriza 50 pontos
                                jogadorDaVez = getJogador(turnoAnterior);
                                jogadorDaVez.setPontos(30 + jogadorDaVez.getPontos());
                                setJogador(turnoAnterior, jogadorDaVez);
                            } else if(turnoAnterior == turno) {
                                // Jogo 'fechado'
                                // Nesse momento a garagem ficará com quem fechou, nova rodada começará caso a pontuação não tenha sido alcançada
                                // Nova rodada começará com quem tiver a carroça de 6
                                jogadorDaVez = getJogador(turnoAnterior);
                                jogadorDaVez.setPontos(jogadorDaVez.getPontos() - 50);
                                setJogador(turnoAnterior, jogadorDaVez);
                                cout << "Jogo Fechado não é possível ninguem jogar" << endl;
                                cout << "Quem tem a menor pontuação em mãos receberá a garagem dos outros jogadores" << endl;
                                maiorGaragem();
                                if(terminouJogo()) {
                                    finalizar();
                                }
                                distribuirPedras();
                                encontrar6x6();
                                limparMesa();
                                inicioComSena = true;
                                cout << "Nova rodada!" << endl;
                                break;
                            }
                        }
                    } while(passar);

                } else {

                    // fechar turno -> contar garagem
                    garagem = garagemParaJogador(turno);
                    cout << jogadorDaVez.getNome() << " ganhou como garagem: " << garagem << " pontos." << endl;
                    jogadorDaVez.setPontos(garagem + jogadorDaVez.getPontos());
                    setJogador(turno, jogadorDaVez);

                    // verificar pontuação geral se alguem alcançou a pontuação terminar jogo e declarar vencedores
                    if(terminouJogo()) {
                        finalizar();
                    } else {

                    // caso contrário começar novo turno
                        distribuirPedras();
                        limparMesa();
                        jogadorDaVez = getJogador(turno);
                        cout << "Nova rodada!" << endl;
                        // Verifica se o jogador tem carroça para começar uma rodada
                        while(!jogadorDaVez.temCarrocaNaMao()) {
                            cout << jogadorDaVez.getNome() << " passou por não ter carroça. Placar continua o mesmo." << endl;
                            turno++;
                            jogadorDaVez = getJogador(turno);
                        }
                    }

                }
                mostrarPlacar();
                return;
            }
        }
    }
}