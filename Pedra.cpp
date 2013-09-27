#include "Pedra.h"

int Pedra::getNaipe(int index) {
    if(index == 1) {
        return n1;
    }
    return n2;
}

void Pedra::setNaipes(int x, int y) {
    n1 = x;
    n2 = y;
}

int Pedra::pontosNaPedra() {
    return n1 + n2;
}