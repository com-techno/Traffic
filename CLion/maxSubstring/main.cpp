#include <iostream>

using namespace std;

int main() {
    string str1;
    string str2;
    string strAns;

    getline(cin, str1);
    getline(cin, str2);

    if(str2.size() < str1.size()) {
        string buf = str1;
        str1 = str2;
        str2 = buf;
    }

    bool flag, hasAns = false;

    for (int i = 1; i <= str1.size(); i++) {
        flag = false;
        for (int j = 0; j <= str1.size() - i && !flag; j++) {
            for (int k = 0; k <= str2.size() - i && !flag; k++) {
                if (str1.substr(j, i) == str2.substr(k, i)) {
                    flag = true;
                    hasAns = true;
                    strAns = str1.substr(j, i);
                }
            }
        }
    }
    if (hasAns)
        cout << strAns << "\n\n";
    else
        cout << "No substring" << "\n\n";

    system("pause");
}