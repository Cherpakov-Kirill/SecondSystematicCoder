#ifndef SECONDSYSTEMATICCODER_CHECKER_H
#define SECONDSYSTEMATICCODER_CHECKER_H

#include <string>
#include <utility>
#include <iostream>

using namespace std;

using namespace std;

class Checker {
private:
    int n;
    int r;
    string polyStr;
    string startDiv;
    string h;
    int **array;

    void computeH();

    void initCheckerMatrix();

    void printCheckerArray();

public:

    string getResultOfMul(string codeWord);

    Checker(int n, int r, string poly) {
        this->n = n;
        this->r = r;
        array = nullptr;
        polyStr = std::move(poly);
        startDiv = "1";
        for (int i = 0; i < n - 1; i++) startDiv += "0";
        startDiv += "1";
        computeH();

        cout << "h(x) = " << h << endl;
        initCheckerMatrix();
        printCheckerArray();
    }

};


#endif //SECONDSYSTEMATICCODER_CHECKER_H
