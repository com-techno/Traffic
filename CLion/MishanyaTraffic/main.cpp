#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <string>
#include <math.h>
#include <ctime>
#include <map>

using namespace std;

int kol_vo_dney_i;
float kol_vo_dney_f;

map<string, int> getMap(){
    map<string, int> mapping;
    mapping["Jan"] = 1;
    mapping["Feb"] = 2;
    mapping["Mar"] = 3;
    mapping["Apr"] = 4;
    mapping["May"] = 5;
    mapping["Jun"] = 6;
    mapping["Jul"] = 7;
    mapping["Aug"] = 8;
    mapping["Sep"] = 9;
    mapping["Oct"] = 10;
    mapping["Nov"] = 11;
    mapping["Dec"] = 12;
    return mapping;
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

void printCurrentStutus(float fCurrent) {
    fCurrent = fCurrent < 0 ? fCurrent - 0.5 : fCurrent + 0.5;
    if (fCurrent > 0)
        cout << "опаздывание на " << abs(fCurrent);
    else if (fCurrent < 0)
        cout << "опережение на " << abs(fCurrent);
    else
        cout << "расход согласно графику";
}

float inputCurrentBalance(int iMaxBalance) {
    string sInput;
    float fCurrentBalance;
    cin >> sInput;
    fCurrentBalance = parseFloat(sInput);
    while (fCurrentBalance < 0 || fCurrentBalance > iMaxBalance) {
        cout << "Недопустимое значение\n";
        cout << "Текущий остаток: ";
        cin >> sInput;
        fCurrentBalance = parseFloat(sInput);
    }
    return fCurrentBalance;
}

int razmer_mes(string s) {
    string mes = s.substr(4, 3);
    map<string, int> mapping = getMap();
    switch (mapping[mes]) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            kol_vo_dney_f = 31.0;
            kol_vo_dney_i = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            kol_vo_dney_f = 30.0;
            kol_vo_dney_i = 30;
            break;
        case 2:
            int m = atoi((s.substr(20, 4)).c_str());
            if (m % 4 == 0) {
                kol_vo_dney_f = 29.0;
                kol_vo_dney_i = 29;
            } else {
                kol_vo_dney_f = 28.0;
                kol_vo_dney_i = 28;
            }
            break;
    }
    cout << "Количество дней в месяце: " << kol_vo_dney_i << endl;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    system("title Прогноз остатка трафика");
    int chislo, vsego = 15; //лимит трафика на месяц
    float tek_ost, plan_ost, v_den;
    time_t sec;
    sec = time(NULL);
    string s = asctime(localtime(&sec));
    string date = s.substr(8, 2);
    chislo = atoi(date.c_str());
    cout << "Сегодняшнее число: " << chislo << endl;
    razmer_mes(s);
    cout << "Текущий остаток: ";
    tek_ost = inputCurrentBalance(vsego);
    string chas = s.substr(11, 2);
    int pint = 0;
    if (atoi(chas.c_str()) >= 20) {
        pint = 1;
        cout << "Не включая сегодняшний день" << endl;
    } else {
        cout << "Включая сегодняшний день" << endl;
    }
    v_den = vsego / kol_vo_dney_f;
    plan_ost = v_den * (kol_vo_dney_i - chislo + 1 - pint);
    cout.setf(ios::fixed);
    cout << "Планируемый остаток на сегодняшний день: " << setprecision(2) << plan_ost;
    cout << " (при расходе " << setprecision(3) << v_den << " в день)" << endl;
    cout << "Отличие текущего остатка от планируемого: " << setprecision(2) << tek_ost - plan_ost;
    cout << " (";
    float dney;
    //dney=ceil((fabs(tek_ost-plan_ost)/v_den)-0.5); //округление до целого по модулю
    //dney=ceil((tek_ost-plan_ost)/v_den-0.5); //округление до целого с учётом знака
    dney = (tek_ost - plan_ost) / v_den;
    cout << printCurrentStutus(dney) << declinationDays(dney);
    //cout << setprecision(0) << (tek_ost-plan_ost)/vsego*100 << "%";
    cout << ")" << endl;
    float rec = tek_ost / (kol_vo_dney_i - chislo + 1);
    cout << "Рекомендуемый ежедневный расход до конца месяца: " << setprecision(2) << rec << endl;

    cout << "\nДля выхода нажмите любую клавишу...";
    getch();
    return 0;
}
