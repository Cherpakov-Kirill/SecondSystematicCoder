#include "Poly.h"

long Poly::getPolyFromUser() {
    printf("Please, type your generation polynomial: ");
    cin >> poly;
}


void Poly::printPoly() {
    printf("Your polynomial is %s or ", polyStr.c_str());
    for (int i = 0; i <= r; i++) {
        if (i == 0) printf("%c", polyStr[i]);
        else {
            if (i == 1) {
                printf("%cx", polyStr[i]);
            } else {
                printf("%cx^%d", polyStr[i], i);
            }
        }
        if (i != r) printf("+");
    }
    printf("\n");
}

int Poly::getPower() const {
    return r;
}

string Poly::getPolyStr() {
    return polyStr;
}
