#ifndef SECONDSYSTEMATICCODER_POLY_H
#define SECONDSYSTEMATICCODER_POLY_H

#include <string>
#include <iostream>

using namespace std;

class Poly {
private:
    long r;
    long poly;
    string polyStr;
public:

    long getPolyFromUser();

    void printPoly();

    int getPower() const;

    string getPolyStr();

    Poly() {
        getPolyFromUser();
        polyStr = to_string(poly);
        r = (long) polyStr.length() - 1;
        printPoly();
    }

    Poly(long poly) {
        this->poly = poly;
        polyStr = to_string(poly);
        r = (long) polyStr.length() - 1;
        printPoly();
    }
};


#endif //SECONDSYSTEMATICCODER_POLY_H
