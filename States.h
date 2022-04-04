#ifndef SECONDSYSTEMATICCODER_STATES_H
#define SECONDSYSTEMATICCODER_STATES_H

#include <set>
#include <string>
#include <iostream>
#include <utility>

using namespace std;

class States {
private:
    set<int> xorNumbers;
    set<int> regNumbers;
    unsigned int regNumber;
    unsigned int width;
    unsigned int height;
    int **array;

    void printRegistersPos();

    void printXorsPos();

    void initArray(string uStr);

    void printArray();

public:
    void compute();

    string getRegistersOnState(int state);

    States(int n, int r, string polyStr, string u) {
        int counter = 0;
        array = nullptr;
        for (int i = 0; i <= r; i++) {
            if (i != 0) {
                regNumbers.insert(counter);
                counter++;
            }
            if (polyStr[i] == '1') {
                xorNumbers.insert(counter);
                counter++;
            }
        }
        printRegistersPos();
        printXorsPos();
        regNumber = regNumbers.size();
        width = regNumber + 1 + xorNumbers.size();
        height = n - regNumber + 1;
        initArray(std::move(u));
    }
};


#endif //SECONDSYSTEMATICCODER_STATES_H
