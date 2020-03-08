#include <iostream>
#include <string>

using namespace std;

int main(){
    int iLength; ///Столбцов
    int iHeight; ///Строк
    int iMaxSubstrLength = 0;
    int iMaxHeight = 0;
    string sInput1; ///Первая строка
    string sInput2; ///Вторая строка
    string sOutput; ///Наибольшая общая подстрока

    ///Ввод
    cout << "Input first string by one line: ";
    getline(cin, sInput1);
    cout << "Input second string by one line: ";
    getline(cin, sInput2);

    ///Расширить матрицу на две клетке по высоте и ширине под каемку
    iLength = sInput1.length() + 2;
    iHeight = sInput2.length() + 2;

    ///Создание динамической матрицы
    int **iInput = new int *[iLength];
    for(int iCur = 0; iCur < iLength; iCur++)
        iInput[iCur] = new int [iHeight];

    ///Заполнение каёмки
    /*
    for (int iCurH = 0; iCurH < 2; iCurH++)///Четыре первые клетки
        for (int iCurL = 0; iCurL < 2; iCurL++)
            iInput[iCurH][iCurL] = 0;
    */
    iInput[0][0] = 0;
    for(int iCur = 2; iCur < iHeight; iCur++) ///Символы первой строки
        iInput[iCur][0] = sInput2.at(iCur - 2);
    for(int iCur = 2; iCur < iLength; iCur++) ///Символы второй строки
        iInput[0][iCur] = sInput1.at(iCur - 2);
    for(int iCur = 0; iCur < iHeight; iCur++) ///Каёмка вертикальная
        iInput[iCur][1] = 0;
    for(int iCur = 0; iCur < iLength; iCur++) ///Каёмка горизонтальная
        iInput[1][iCur] = 0;

    ///Заполнение матрицы длины совпадающих символов
    for(int iCurH = 2; iCurH < iHeight; iCurH++)
        for(int iCurL = 2; iCurL < iLength; iCurL++)
            if(iInput[iCurH][0] == iInput[0][iCurL]) {
                iInput[iCurH][iCurL] = iInput[iCurH - 1][iCurL - 1] + 1;
                if (iInput[iCurH][iCurL] > iMaxSubstrLength) {
                    iMaxHeight = iCurH - 1;
                    iMaxSubstrLength = iInput[iCurH][iCurL];
                }
            } else
                iInput[iCurH][iCurL] = 0;

    ///Вывод матрицы длины совпадающих символов
    /*cout << "\n\n\n";
    for(int iCurH = 1; iCurH < iHeight; iCurH++){
        for(int iCurL = 1; iCurL < iLength; iCurL++)
            if((iCurH == 0 && iCurL >= 2) || (iCurL == 0 && iCurH >= 2))
                cout << (char)iInput[iCurH][iCurL] << "\t";
            else
                cout << iInput[iCurH][iCurL] << "\t";
        cout << endl;
    }*/

    sOutput = sInput2.substr(iMaxHeight - iMaxSubstrLength, iMaxSubstrLength);
    cout << "\nМаксимальная общая подстрока: " << sOutput << "\n\n\n";
    system("pause");
}