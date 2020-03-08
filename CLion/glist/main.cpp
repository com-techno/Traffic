/**
 * ©Techno, 2020
 **
 * Эта программа выводит гистограмму,
 * содержащую статистику использования символов.
 * Просто введите строку!
 **
 * This program displays a histogram containing
 * statistics on character usage.
 * Just enter a line!
 */

#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int symbol_number = 1;
    int *numbers = new int [symbol_number];
    char *symbols = new char [symbol_number];
    symbols[0] = str[0];
    numbers[0] = 1;
    bool flag;
    for (int i = 1; i < str.length(); i++) {
        flag = false;
        for (int j = 0; j < symbol_number; j++) {
            if (str[i] == symbols[j]){
                numbers[j]++;
                flag = true;
            }
        }
        if (!flag){
            symbol_number++;
            int cur = symbol_number - 1;
            symbols[cur] = str[i];
            numbers[cur] = 1;
        }
    }
    for (int k = 0; k < symbol_number; k++) {
        cout << symbols[k] << "\t";
        for (int i = 0; i < numbers[k]; i++) {
            cout << ":";
        }
        cout << endl;
    }
    system("pause");
}
