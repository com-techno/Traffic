#include <iostream>

using namespace std;

int main() {
    string str, result = "", stringBuffer;
    getline (cin, str);
    char charBuffer = '.';
    int counter = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == charBuffer){
            counter++;
        } else {
            stringBuffer = to_string(counter) + charBuffer + " ";
            result+= counter == 0?  "" : stringBuffer;
            charBuffer = str[i];
            counter = 1;
        }
    }
    result+= to_string(counter) + charBuffer;

   cout << result;
}
