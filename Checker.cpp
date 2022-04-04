#include "Checker.h"

void Checker::computeH() {
    string div = startDiv;
    int polySize = (int) polyStr.size();
    int currSize = (int) div.size();
    int diffSizes = currSize - polySize;
    h = "";
    for (int i = 0; i <= diffSizes; i++)h += "0";

    while (diffSizes != 0) {
        currSize = (int) div.size();
        diffSizes = currSize - polySize;
        h[diffSizes] = '1';
        for (int i = currSize - 1; i >= currSize - polySize; i--) {
            if ((polyStr[i - diffSizes] + div[i]) % 2 == 0) {
                div[i] = '0';
            } else div[i] = '1';
        }
        int pos = currSize - 1;
        while (pos >= 0 && div[pos] == '0') {
            div.erase(pos, 1);
            pos--;
        }
    }
}

void Checker::initCheckerMatrix() {
    array = (int **) malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++) {
        array[i] = (int *) malloc(n * sizeof(int));
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = 0;
        }
    }
    int counter = 0;
    for (int j = n - 1; j >= n - h.size(); j--) {
        array[0][j] = h[counter] - 48;
        counter++;
    }
    for (int i = 1; i < r; i++) {
        array[i][n - 1] = 0;
        for (int j = n - 2; j >= 0; j--) {
            array[i][j] = array[i - 1][j + 1];
        }
    }
}

void Checker::printCheckerArray() {
    cout<<"Checker matrix :\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < n; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

string Checker::getResultOfMul(string codeWord) {
    string res;
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += array[i][j] * (codeWord[j] - 48);
        }
        if (sum % 2 == 0) res += "0";
        else res += "1";
    }
    return res;
}
