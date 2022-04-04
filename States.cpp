#include "States.h"

void States::printRegistersPos() {
    cout << "registers: ";
    for (const auto &i: regNumbers) {
        cout << i << " ";
    }
    cout << endl;
}

void States::printXorsPos() {
    cout << "xors: ";
    for (const auto &i: xorNumbers) {
        cout << i << " ";
    }
    cout << endl;
}

void States::initArray(string uStr) {
    array = (int **) malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        array[i] = (int *) malloc(width * sizeof(int));
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == height - 1 && j == 0) array[i][j] = -1;
            else {
                if (j == 0) array[i][j] = uStr[i] - 48;
                else array[i][j] = 0;
            }
        }
    }
}

void States::printArray() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void States::compute() {
    for (int stage = 1; stage < height; stage++) {
        auto xorIt = xorNumbers.begin();
        while (xorIt != xorNumbers.end()) {
            if (xorIt == xorNumbers.begin()) {
                array[stage - 1][(*xorIt + 1)] =
                        (array[stage - 1][(*xorIt + 1) - 1] + array[stage - 1][(*xorIt + 1) + 1]) % 2;
            } else if (next(xorIt) == xorNumbers.end()) {
                array[stage - 1][(*xorIt + 1)] = array[stage - 1][*(xorNumbers.begin()) + 1];
            } else {
                array[stage - 1][(*xorIt + 1)] =
                        (array[stage - 1][*(xorNumbers.begin()) + 1] + array[stage - 1][(*xorIt + 1) + 1]) % 2;
            }
            xorIt++;
        }
        auto regIt = regNumbers.begin();
        while (regIt != regNumbers.end()) {
            array[stage][(*regIt + 1)] = array[stage - 1][(*regIt + 1) + 1];
            regIt++;
        }
    }
}

string States::getRegistersOnState(int state) {
    string s = "";
    if (state >= height) cout << "Number of registers state if more then n-r" << endl;
    for (const auto i: regNumbers) {
        s += to_string(array[state][i + 1]);
    }
    return s;
}
