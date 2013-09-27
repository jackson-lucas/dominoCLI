#include <list>
#include <iostream>
#include "Mesa.h"
#include "Pedra.h"

using namespace std;

list<Pedra> Mesa::getPonta(int index){
    switch(index) {
        case 1:
            return ponta1;
            break;
        case 2:
            return ponta2;
            break;
        case 3:
            return ponta3;
            break;
        case 4:
            return ponta4;
    }
}

void Mesa::setPonta(int index, list<Pedra> lista){
    switch(index) {
        case 1:
            ponta1 = lista;
            break;
        case 2:
            ponta2 = lista;
            break;
        case 3:
            ponta3 = lista;
            break;
        case 4:
            ponta4 = lista;
    }
}

Pedra Mesa::pedraDaPonta(int index) {
    switch(index) {
        case 1:
            return ponta1.front();
            break;
        case 2:
            return ponta2.front();
            break;
        case 3:
            return ponta3.front();
            break;
        case 4:
            return ponta4.front();
    }
}

void Mesa::colocarPedraNaPonta(int index, Pedra p) {
    switch(index) {
        case 1:
            ponta1.push_front(p);
            break;
        case 2:
            ponta2.push_front(p);
            break;
        case 3:
            ponta3.push_front(p);
            break;
        case 4:
            ponta4.push_front(p);
    }
}

bool Mesa::colocarPedraNaMesa(Pedra p) {
    Pedra pedraNaPonta;
    int n1, n2, pontaEscolhida;
    list<int> pontasDisponiveis;
    list<int>::iterator ponta;
    list<Pedra> lista;
    if(ponta1.empty() and ponta2.empty() and ponta3.empty() and ponta4.empty() and p.getNaipe(1) == p.getNaipe(2)) {
        lista.push_back(p);
        setPonta(1, lista);
        setPonta(2, lista);
        setPonta(3, lista);
        setPonta(4, lista);
        return true;
    } else { 
        for(int i=1; i<5; i++) {
            pedraNaPonta = pedraDaPonta(i);
            if(pedraNaPonta.getNaipe(1)== p.getNaipe(2)) {
                pontasDisponiveis.push_back(i);
            } else if (pedraNaPonta.getNaipe(1) == p.getNaipe(1)) {
                pontasDisponiveis.push_back(i);
            }
        }
        // Caso haja mais de uma opção o jogador pode optar em que ponta vai jogar
        if(pontasDisponiveis.size() > 1) {
            cout << "Escolha uma das pontas a seguir para jogar:" << endl;
            for(ponta = pontasDisponiveis.begin(); ponta!=pontasDisponiveis.end(); ponta++) {
                cout <<  " " << *ponta;
            }
            cout << endl;
            cin >> pontaEscolhida;
            pedraNaPonta = pedraDaPonta(pontaEscolhida);
            if(pedraNaPonta.getNaipe(1)== p.getNaipe(2)) {
                colocarPedraNaPonta(pontaEscolhida, p);
                return true;
            } else if (pedraNaPonta.getNaipe(1) == p.getNaipe(1)) {
                n1 = p.getNaipe(1);
                n2 = p.getNaipe(2);
                p.setNaipes(n2, n1);
                colocarPedraNaPonta(pontaEscolhida, p);
                return true;
            }
        } else if (pontasDisponiveis.size() == 1) {
            pedraNaPonta = pedraDaPonta(pontasDisponiveis.front());
            if(pedraNaPonta.getNaipe(1)== p.getNaipe(2)) {
                colocarPedraNaPonta(pontaEscolhida, p);
                return true;
            } else if (pedraNaPonta.getNaipe(1) == p.getNaipe(1)) {
                n1 = p.getNaipe(1);
                n2 = p.getNaipe(2);
                p.setNaipes(n2, n1);
                colocarPedraNaPonta(pontaEscolhida, p);
                return true;
            }
        }
    }
    return false;
}

// Para corrigir a contagem de pontos após a primeira pedra ser colocada
bool Mesa::pedraEstaNaLista(Pedra p, list<Pedra> memoria) {
    list<Pedra>::iterator pedra;
    for(pedra = memoria.begin(); pedra!=memoria.end(); pedra++) {
        if(p.getNaipe(1) == (*pedra).getNaipe(1) and p.getNaipe(2) == (*pedra).getNaipe(2)) {
            return true;
        } else if(p.getNaipe(1) == (*pedra).getNaipe(2) and p.getNaipe(2) == (*pedra).getNaipe(1)) {
            return true;
        }
    }
    return false;
}

int Mesa::pedraEstaEmQuantasPontas(Pedra p) {
    int quantidade = 0;
    
    if(pedraEstaNaLista(p, ponta1)) {
        quantidade++;
    }
    if(pedraEstaNaLista(p, ponta2)) {
        quantidade++;
    }
    if(pedraEstaNaLista(p, ponta3)) {
        quantidade++;
    }
    if(pedraEstaNaLista(p, ponta4)) {
        quantidade++;
    }
    return quantidade;
}

int Mesa::pontosNaMesa() {
    Pedra p;
    int pontasAbertasRestantes = 0;
    list<Pedra> inicial;
    list<Pedra>::iterator elemento;
    int quantasPontas;
    int pontos = 0;
    
    for(int i =1; i<5; i++) {
        p = pedraDaPonta(i);
        if(p.getNaipe(1) == p.getNaipe(2)) {
            quantasPontas = pedraEstaEmQuantasPontas(p);
            if(quantasPontas == 4) {
                pontasAbertasRestantes++;
                inicial.push_back(p);
            } else {
                pontos += p.pontosNaPedra();
            }
        } else {
            quantasPontas = pedraEstaEmQuantasPontas(p);
            if(quantasPontas == 4) {
                pontasAbertasRestantes++;
                inicial.push_back(p);
            } else {
                pontos += p.getNaipe(1);
            }
        }
    }
    // Solução para o caso em que a primeira pedra ainda está disponível na mesa
    if(pontasAbertasRestantes > 2) {
        // Solucionado somente para os casos em que é uma carroça(Domino Amazonense)
        elemento = inicial.begin();
        if (elemento!=inicial.end()) {
            pontos += (*elemento).pontosNaPedra();  
        } 
    }
    return pontos;
}

void Mesa::mostrarMesa() {
    list<Pedra>::iterator pedra;
    cout << "Mesa:" << endl;
    cout << "Ponta 1 " << ": [";
    for(pedra=ponta1.begin(); pedra!=ponta1.end(); pedra++) {
        cout << "(" << (*pedra).getNaipe(1) << ", " << (*pedra).getNaipe(2) << ")";
    }
    cout << "]" << endl;
    cout << "Ponta 2 " << ": [";
    for(pedra=ponta2.begin(); pedra!=ponta2.end(); pedra++) {
        cout << "(" << (*pedra).getNaipe(1) << ", " << (*pedra).getNaipe(2) << ")";
    }
    cout << "]" << endl;
    cout << "Ponta 3 " << ": [";
    for(pedra=ponta3.begin(); pedra!=ponta3.end(); pedra++) {
        cout << "(" << (*pedra).getNaipe(1) << ", " << (*pedra).getNaipe(2) << ")";
    }
    cout << "]" << endl;
    cout << "Ponta 4 " << ": [";
    for(pedra=ponta4.begin(); pedra!=ponta4.end(); pedra++) {
        cout << "(" << (*pedra).getNaipe(1) << ", " << (*pedra).getNaipe(2) << ")";
    }
    cout << "]" << endl;
}