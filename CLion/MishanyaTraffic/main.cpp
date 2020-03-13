#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <string>
#include <math.h>
#include <ctime>
#include <map>
#include <list>

using namespace std;

int iMonthLength;
float fMonthLength;

map<string, int> getMap(){
    map<string, int> months;
    months["Jan"] = 1;
    months["Feb"] = 2;
    months["Mar"] = 3;
    months["Apr"] = 4;
    months["May"] = 5;
    months["Jun"] = 6;
    months["Jul"] = 7;
    months["Aug"] = 8;
    months["Sep"] = 9;
    months["Oct"] = 10;
    months["Nov"] = 11;
    months["Dec"] = 12;
    return months;
}

float parseFloat(string sTarget) {
    if (sTarget.find(',', 0) < string::npos)
        sTarget.replace(sTarget.find(','), 1, ".");
    return atof(sTarget.c_str());
}

string declinationDays(float fTarget) {
    int iDays = abs(fTarget < 0 ? fTarget - 0.5 : fTarget + 0.5);
    int iLastDigit = iDays % 10;
    if (iLastDigit == 1)
        return " день";
    if (iLastDigit >= 2 && iLastDigit <= 4)
        return " дня";
    if ((iLastDigit >= 5 && iLastDigit <= 9) || iLastDigit == 0 || (iDays >= 11 && iDays <= 19))
        return " дней";
    return "";
}

void printCurrentStatus(float fCurrent, float fPerDay, float fPlanCurrentBalance, float fCurrentBalance) {
    cout << "Планируемый остаток на сегодняшний день: " << setprecision(2) << fPlanCurrentBalance
         << " (при расходе " << setprecision(3) << fPerDay << " в день)\n"
         << "Отличие текущего остатка от планируемого: " << setprecision(2) << fCurrentBalance - fPlanCurrentBalance
         << " (";
    fCurrent = fCurrent < 0 ? fCurrent - 0.5 : fCurrent + 0.5;
    if (fCurrent > 0)
        cout << "опаздывание на " << abs(fCurrent) << declinationDays(fCurrent);
    else if (fCurrent < 0)
        cout << "опережение на " << abs(fCurrent) << declinationDays(fCurrent);
    else
        cout << "расход согласно графику" << declinationDays(fCurrent);
    cout << ")\n";
}

float inputCurrentBalance(int iMaxBalance) {
    string sInput;
    float fCurrentBalance;
    cin >> sInput;
    fCurrentBalance = parseFloat(sInput);
    while (fCurrentBalance < 0 || fCurrentBalance > iMaxBalance) {
        cout << "Недопустимое значение\nТекущий остаток: ";
        cin >> sInput;
        fCurrentBalance = parseFloat(sInput);
    }
    return fCurrentBalance;
}

int getMonthLength(string s) {
    string mes = s.substr(4, 3);
    map<string, int> months = getMap();

    switch (months[mes]) {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            fMonthLength = 31.0;
            iMonthLength = 31;
            break;
        case 4:case 6:case 9:case 11:
            fMonthLength = 30.0;
            iMonthLength = 30;
            break;
        case 2:
            if (atoi((s.substr(20, 4)).c_str()) % 4 == 0) {
                fMonthLength = 29.0;
                iMonthLength = 29;
            } else {
                fMonthLength = 28.0;
                iMonthLength = 28;
            }
            break;
    }
    cout << "Количество дней в месяце: " << iMonthLength << endl;
}

void consoleConfig(){
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    system("title Прогноз остатка трафика");
}

int main() {
    consoleConfig();
    int iDate;
    int iMaxBalance = 15; //лимит трафика на месяц
    float fPerDay;
    float fPlanCurrentBalance;
    float fCurrentBalance;
    time_t systemTime;
    systemTime = time(NULL);
    string sSystemDate = asctime(localtime(&systemTime));
    iDate = atoi(sSystemDate.substr(8, 2).c_str());
    cout << "Сегодняшнее число: " << iDate << endl;
    getMonthLength(sSystemDate);
    cout << "Текущий остаток: ";
    fCurrentBalance = inputCurrentBalance(iMaxBalance);
    int pint = 0;
    if (atoi(sSystemDate.substr(11, 2).c_str()) >= 20) {
        pint = 1;
        cout << "Не включая сегодняшний день\n";
    } else {
        cout << "Включая сегодняшний день\n";
    }
    fPerDay = iMaxBalance / fMonthLength;
    fPlanCurrentBalance = fPerDay * (iMonthLength - iDate + 1 - pint);
    cout.setf(ios::fixed);
    printCurrentStatus((fCurrentBalance - fPlanCurrentBalance) / fPerDay, fPerDay, fPlanCurrentBalance, fCurrentBalance);
    cout << "Рекомендуемый ежедневный расход до конца месяца: "
        << setprecision(2) << fCurrentBalance / (iMonthLength - iDate + 1)
        << "\n\nДля выхода нажмите любую клавишу...";
    getch();
    return 0;
}