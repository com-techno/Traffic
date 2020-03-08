#include <iostream>
#include <cmath>
#include <cstdlib>
#include <conio.h>

using namespace std;

double changeToDecimal(string str, int base, int sign) {
    double sum = 0;
    int buffer;
    int n = sign == -1 ? 1 : 0;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[str.length() - i - 1];
        switch (ch) {
            case 'A':
                buffer = 10;
                break;
            case 'B':
                buffer = 11;
                break;
            case 'C':
                buffer = 12;
                break;
            case 'D':
                buffer = 13;
                break;
            case 'E':
                buffer = 14;
                break;
            case 'F':
                buffer = 15;
                break;
            default:
                buffer = atoi(&ch);
        }
        if (sign == -1) {
            sum += (buffer / pow(base, i + 1));
        } else {
            sum += buffer * pow(base, i);
        }
    }
    return sum;
}


int main() {
    string number;
    int base;
    cin >> number >> base;
    if (!(number.find(".") >= 0 && number.find(".") < number.length())) {
        cout << changeToDecimal(number, base, 1);
    } else {
        string z, d;
        z = number.substr(0, number.find("."));
        d = number.substr(number.find(".") + 1, number.length() - number.find("."));
        string revd = "";
        for (int i = 0; i < d.length(); i++) {
            revd += d[d.length() - i - 1];
        }
        double sum = changeToDecimal(z, base, 1) + changeToDecimal(revd, base, -1);
        cout << changeToDecimal(z, base, 1) + changeToDecimal(revd, base, -1) << endl;
    }

}
