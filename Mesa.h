#ifndef Mesa_h
#define Mesa_h
#include <list>
#include "Pedra.h"

using namespace std;

class Mesa {
    list<Pedra> ponta1, ponta2;
    list<Pedra> ponta3, ponta4;
    public:
        list<Pedra> getPonta(int index);
        void setPonta(int index, list<Pedra> lista);
        Pedra pedraDaPonta(int index);
        void colocarPedraNaPonta(int index, Pedra p);
        bool colocarPedraNaMesa(Pedra p);
        bool pedraEstaNaLista(Pedra p, list<Pedra> memoria);
        int pedraEstaEmQuantasPontas(Pedra p);
        int pontosNaMesa();
        void mostrarMesa();
};
#endif

