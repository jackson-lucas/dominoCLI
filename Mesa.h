#ifndef Mesa_h
#define Mesa_h
#include <list>
#include "Pedra.h"

using namespace std;

class Mesa {
    list<Pedra> ponta1, ponta2;
    list<Pedra> ponta3, ponta4;
    int pedraEstaEmQuantasPontas(Pedra p);
    bool pedraEstaNaLista(Pedra p, list<Pedra> memoria);
    void colocarPedraNaPonta(int index, Pedra p);
    list<Pedra> getPonta(int index);
    public:
        void setPonta(int index, list<Pedra> lista);
        Pedra pedraDaPonta(int index);
        bool colocarPedraNaMesa(Pedra p);
        int pontosNaMesa();
        void mostrarMesa();
};
#endif

