#include <iostream>
#include "Poly.h"
#include "States.h"
#include "Checker.h"
#include <set>

using namespace std;

int main() {
    struct timespec start{}, end{};
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    int n;
    string uStr;

    cout << "Please, enter n-parameter: ";
    cin >> n;
    auto *poly = new Poly();
    int r = poly->getPower();
    string polyStr = poly->getPolyStr();

    cout << "Please, enter input-word: ";
    cin >> uStr;

    auto *states = new States(n, r, polyStr, uStr);
    states->compute();
    cout << "Registers:\n";
    string regs;
    for (int i = 1; i <= n - r; i++) {
        regs = states->getRegistersOnState(i);
        cout << i << ". " << regs << endl;
    }
    string codeWord = regs + uStr;
    cout << "Code word = " << codeWord << endl;
    cout << endl;

    auto *checker = new Checker(n, r, polyStr);
    string checkRes = checker->getResultOfMul(codeWord);
    cout << "H*codeWord^T = " << checkRes << endl;

    int countOfZero = 0;
    for (char checkRe: checkRes) {
        if (checkRe == '0') countOfZero++;
    }
    if (countOfZero == checkRes.size()) cout << "SUCCESS!" << endl;
    else cout << "!!!!!!!!FAILED!!!!!!!!" << endl;
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    printf("Time taken: %lf sec.\n",
           (double) (end.tv_sec - start.tv_sec)
           + 0.000000001 * (double) (end.tv_nsec - start.tv_nsec));
    delete (poly);
    delete (checker);
    delete (states);
    return 0;
}
