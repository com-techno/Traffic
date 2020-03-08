#include <iostream>
#include <vector>

using namespace std;

int symbol_number = 1;

class CodeSymbol{
public:

    char symbol;

    CodeSymbol(char symbol){
        this->symbol = symbol;
    }

    string toString(){
        string return_ = " ";
        return return_ + symbol + "\t" + code;
    };

    void setCode(string newCode){
        this->code = newCode;
    }

private:
    string code;
};

void identification(string INPUT_STRING, char *symbols, int *numbers){
    bool flag;
    symbols[0] = INPUT_STRING[0];
    numbers[0] = 1;
    for (int i = 1; i < INPUT_STRING.length(); i++) {
        flag = false;
        for (int j = 0; j < symbol_number; j++) {
            if (INPUT_STRING[i] == symbols[j]){
                numbers[j]++;
                flag = true;
            }
        }
        if (!flag){
            symbol_number++;
            int cur = symbol_number - 1;
            symbols[cur] = INPUT_STRING[i];
            numbers[cur] = 1;
        }
    }
}

int current = 0;

void tree(vector<CodeSymbol> &codes, int symbol_number_cur, string code){
    if (symbol_number_cur == 1) {
        codes.at(current).setCode(code);
        current++;
        return;
    }
    int cur = symbol_number_cur / 2;
    tree(codes, cur, code + "0");
    cout << " ";
    tree(codes, symbol_number_cur - cur, code + "1");
}

int main() {
    char *symbols = new char[symbol_number];
    int *numbers = new int[symbol_number];
    string input;
    cin >> input;
    identification(input, symbols, numbers);
    bool flag = true;
    if (symbol_number < 2) flag = false;
    if(flag) {
        /*
        for (int i = 0; i < symbol_number - 1; i++) {
            for (int j = 0; j < symbol_number - 1; j++) {
                if (numbers[j] < numbers[j + 1]) {
                    // меняем элементы местами
                    char temp = symbols[j];
                    symbols[j] = symbols[j + 1];
                    symbols[j + 1] = temp;
                }
            }
        }
        */
        vector<CodeSymbol> codes;
        for (int k = 0; k < symbol_number; k++) {
            codes.push_back(*new CodeSymbol(symbols[k]));
        }
        tree(codes, symbol_number, "");

        for (CodeSymbol codeSymbol: codes) cout << codeSymbol.toString() << endl;

    } else cout << "Nothing to code /// $Error" << endl;
    system("pause");
}
