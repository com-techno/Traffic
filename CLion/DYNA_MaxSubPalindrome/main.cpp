#define input_type 2
//1 - from file; 2 - from keyboard

#include <iostream>

#if input_type == 1
#include <fstream>
#endif

using namespace std;

void input(string &sInput, int &iSize) {

#if input_type == 1
    ifstream fin;
    fin.open("input.txt");
    getline(fin, sInput);
    fin.close();
#elif input_type == 2
    cout << "Input string by one line: ";
    cin >> sInput;
#endif

    iSize = sInput.size() + 2;
}

void fillBorder(int **iMatrix, int &iSize, string &sInput) {
    for (int iCur = 0; iCur < iSize; iCur++) {
        iMatrix[iCur][1] = 0;
        iMatrix[1][iCur] = 0;
        if (iCur >= 2) {
            iMatrix[iCur][0] = sInput.at(iCur - 2);
            iMatrix[0][iCur] = sInput.at(iSize - 1 - iCur);
        }
    }
}

void fillMatrix(int **iMatrix, int &iSize) {
    for (int iCurH = 2; iCurH <= iSize; iCurH++)
        for (int iCurL = 2; iCurL <= iSize; iCurL++)
            if (iMatrix[iCurH][0] == iMatrix[0][iCurL])
                iMatrix[iCurH][iCurL] = iMatrix[iCurH - 1][iCurL - 1] + 1;
            else
                iMatrix[iCurH][iCurL] = max(iMatrix[iCurH - 1][iCurL], iMatrix[iCurH][iCurL - 1]);
}

string findLCS(int **iMatrix, int &iSize, string &sInput) {
    string sLCS;

    int iCurH = iSize - 1;
    int iCurL = iSize - 1;

    while (iCurH >= 0 && iCurL >= 0)
        if (iMatrix[iCurH][0] == iMatrix[0][iCurL]) {
            sLCS+= sInput[iCurH - 2];
            iCurH--;
            iCurL--;
        } else if (iMatrix[iCurH - 1][iCurL] > iMatrix[iCurH][iCurL - 1]) {
            iCurH--;
        } else {
            iCurL--;
        }

    return sLCS;
}

int main() {
    system("title LSP - longest subpalindrome");

    string sInput;
    int iSize = 0;
    int **iMatrix = new int*[iSize];
    for (int iCurH = 0; iCurH < iSize; iCurH++)
        iMatrix[iCurH] = new int[iSize];

    input(sInput, iSize);
    fillBorder(iMatrix, iSize, sInput);
    fillMatrix(iMatrix, iSize);
    cout << findLCS(iMatrix, iSize, sInput) << endl;
}
