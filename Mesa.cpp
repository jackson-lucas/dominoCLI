#include <list>
#include <iostream>
#include "Mesa.h"
#include "Pedra.h"

using namespace std;

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
            return ponta1.back();
            break;
        case 2:
            return ponta2.back();
            break;
        case 3:
            return ponta3.back();
            break;
        case 4:
            return ponta4.back();
    }
}

void Mesa::colocarPedraNaPonta(int index, Pedra p) {
    switch(index) {
        case 1:
            ponta1.push_back(p);
            break;
        case 2:
            ponta2.push_back(p);
            break;
        case 3:
            ponta3.push_back(p);
            break;
        case 4:
            ponta4.push_back(p);
    }
}
// checarPontosNaMesa
// colocarPedraNaMesa
/*Teste: Testa a criação de uma pedra e da ponta de uma mesa main () {Pedra pedra1;
main () {
    Mesa mesa1;
    list<Pedra> lista;
    Pedra pedra1;
    pedra1.setNaipes(1,4);
    Pedra pedra2, pedra3;
    cout << pedra1.pontosNaPedra() << " 1" << endl; // 1,4
    pedra2 = pedra1;
    cout << pedra2.pontosNaPedra() << " 2" << endl; // 1,4
    pedra1.setNaipes(1,2);
    cout << pedra1.pontosNaPedra() << " 1" << endl; // 1,2
    cout << pedra2.pontosNaPedra() << " 2" << endl; // 1,4
    pedra3 = pedra1;
    cout << pedra3.pontosNaPedra() << " 3" << endl; // 
    pedra1.setNaipes(5,5);
    cout << pedra1.pontosNaPedra() << " 1" << endl;
    lista.push_back(pedra1);
    lista.push_back(pedra1);
    lista.push_back(pedra1);
    mesa1.setPonta(1,lista);
    cout << mesa1.pedraDaPonta(1).pontosNaPedra() << endl;
}
*/