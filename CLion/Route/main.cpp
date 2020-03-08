#include <iostream>
#include <string>

using namespace std;

int main(){
    int iLength;///Столбцов
    int iHeight;///Строк
    cin >> iHeight >> iLength;

    string sRoute = "";
    iLength++;
    iHeight++;
    int **iInput = new int *[iLength];
    int **iRoutes = new int *[iLength];
    for(int iCur = 0; iCur < iLength; iCur++) {
        iInput[iCur] = new int [iHeight];
        iRoutes[iCur] = new int [iHeight];
    }

    ///Заполнение вводимой матрицы
    for(int iCurH = 1; iCurH < iHeight; iCurH++)
        for(int iCurL = 1; iCurL < iLength; iCurL++)
            cin >> iInput[iCurH][iCurL];

    ///Заполнение каёмки
    for(int iCur = 0; iCur < iHeight; iCur++) {
        iRoutes[iCur][0] = 2147483647;
        iInput[iCur][0] = 2147483647;
    }
    for(int iCur = 0; iCur < iLength; iCur++) {
        iRoutes[0][iCur] = 2147483647;
        iInput[0][iCur] = 2147483647;
    }

    ///Заполнение матрицы маршрута
    for(int iCurH = 1; iCurH < iHeight; iCurH++)
        for(int iCurL = 1; iCurL < iLength; iCurL++) {
            if(iCurH == 1 && iCurL == 1) iRoutes[iCurH][iCurL] = iInput[iCurH][iCurL];
            else {
                int l = iRoutes[iCurH][iCurL - 1];///Левая клетка
                int u = iRoutes[iCurH - 1][iCurL];///Верхняя клетка
                int lu = iRoutes[iCurH - 1][iCurL - 1];///Левая верхняя клетка
                if (lu <= min(u, l))
                    iRoutes[iCurH][iCurL] = lu + iInput[iCurH][iCurL];
                else
                    iRoutes[iCurH][iCurL] = min(u, l) + iInput[iCurH][iCurL];
            }
        }

    ///Вывод матрицы маршрута
    cout << "\n\n\n";
    for(int iCurH = 1; iCurH < iHeight; iCurH++){
        for(int iCurL = 1; iCurL < iLength; iCurL++)
            cout << iRoutes[iCurH][iCurL] << "\t";
        cout << endl;
    }

    ///Определение кратчайшего маршрута
    int iCurL = iLength - 1;
    int iCurH = iHeight - 1;
    while(iCurH >= 1 && iCurL >= 1){
        int l = iRoutes[iCurH][iCurL - 1];
        int u = iRoutes[iCurH - 1][iCurL];
        int lu = iRoutes[iCurH - 1][iCurL - 1];
        if (lu <= min(l, u)) {
            sRoute = "\\" + sRoute;
            iCurL--;
            iCurH--;
        } else if (l < u) {
            sRoute = "-" + sRoute;
            iCurL--;
        } else {
            sRoute = "|" + sRoute;
            iCurH--;
        }
    }
    sRoute = sRoute.substr(1, sRoute.length() - 1);
    cout << "\n\n\n" << sRoute << "\n\n\n";
    system("pause");
}