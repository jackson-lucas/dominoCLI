#include "Pedra.h"

void Pedra::setNaipes(int x, int y) {
    n1 = x;
    n2 = y;
}

int Pedra::pontosNaPedra() {
    return n1 + n2;
}