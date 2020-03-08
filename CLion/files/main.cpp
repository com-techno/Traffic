#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

/**Working with file*/

const string path = R"(C:\Users\Sinyavsk\CLionProjects\files\array.txt)";

void printArray(int _array[], int numberElements){
    for (int i = 0; i < numberElements; i++) {
        cout << _array[i] << " ";
    }
    cout << endl;
}

bool callFile (int *_array, int &_numberElements) {
    ifstream ifs;
    delete [] _array;
    _array = new int [_numberElements];
    _numberElements = 0;
    ifs.open(path);
    if (ifs.is_open()) {
        string buffer;
        while (!ifs.eof()) {
            buffer = "";
            _numberElements++;
            ifs >> buffer;
            _array[_numberElements - 1] = atoi(buffer.c_str());
        }
        ifs.close();

        cout << "File has sucsessfully read.\nNew array: ";
        printArray(_array, _numberElements);
    } else {
        cout << "$File can't be opened\n";
    }
    return !(_numberElements == 1 && _array[0] == 0);
}

void changeFile () {
    ofstream ofs;
    ofs.open(path, ios::out);
    string str;
    cout << "Enter elements by one line: ";
    getline(cin, str);
    ofs << str;
    cout << "File has sucsessfully changed\n";
    ofs.close();
}

/** End of working with file*/

/** Working with array*/

void deleteElementByNumber (int *_array, int &_numberElements){
    int numDeleteElem;
    cout << "Enter number of element you want delete(from 0 to " << _numberElements - 1 << "): ";
    cin >> numDeleteElem;
    for (int i = 0; i < _numberElements; i++) {
        if (i > numDeleteElem) _array[i - 1] = _array[i];
    }
    _numberElements--;
    cout << "Element sucsessfully deleted.\nCurrent array: ";
    printArray(_array, _numberElements);
}

void addElementToEnd(int *_array, int &_numberElements){
    int element;
    cout << "Enter value: ";
    cin >> element;

    _numberElements++;
    _array[_numberElements-1] = element;
    cout << "Element successfully added.\nCurrent array: ";
    printArray(_array, _numberElements);
}

void sortArrayFromLowToHigh(int *_array, int &_numberElements){
    int tmp;
    for (int i = 0; i < _numberElements - 1; i++) {
        for (int j = 0; j < _numberElements - i - 1; j++) {
            if (_array[j] > _array[j + 1]) {
                tmp = _array[j];
                _array[j] = _array[j + 1];
                _array[j + 1] = tmp;
            }
        }
    }
    cout << "Array has sucsessfully sorted.\nCurrent array: ";
    printArray(_array, _numberElements);
}

void findMaxElement(int *_array, int &_numberElements){
    int max = _array[0];
    for (int i = 1; i < _numberElements; i++) {
        if (_array[i] > max) max = _array[i];
    }
    cout << "Max element in array is: " << max << "\n";
}

/** End of working with array*/

void menu() {
    cout << "\n"
            "1 - delete element by number\n"
            "2 - add element to end\n"
            "3 - sort array from low to high\n"
            "4 - find max element\n"
            "5 - print array\n"
            "6 - write to file\n"
            "7 - read from file\n"
            "0 - exit program\n\n";
}

void hello(){
    cout << "Programmers company \"Techno\" represents...\nProgram! Good luck! Please don't type \"samalamadumalama\", okay?\nTo start, press any key.";
    getch();
    system("cls");
}

int main() {

    int numberElements = 0;
    int *array = new int [numberElements];

    hello();

    bool b = callFile(array, numberElements);
    bool fl = false;
    if(!b){
        cout << "File don't contains anything. Do you want to enter array now?[Y/N](N - exit program)\n";
        if (getch() == 'y'){
            changeFile();
            callFile(array, numberElements);
        } else return 0;
    }
    bool fl1 = false;
    do{
        if(fl1) {
            cout << "\n\nPress any key to continue...\n\n";
            getch();
        }
        fl1 = true;
        menu();
        switch (getch()){
            case '1':
                deleteElementByNumber(array, numberElements);
                break;
            case '2':
                addElementToEnd(array, numberElements);
                break;
            case '3':
                sortArrayFromLowToHigh(array, numberElements);
                break;
            case '4':
                findMaxElement(array, numberElements);
                break;
            case '5':
                printArray(array, numberElements);
                break;
            case '6':
                changeFile();
                break;
            case '7':
                callFile(array, numberElements);
                break;
            case '0':
                fl = true;
                break;
            default:
                cout << "Chi sho, durachek?\n";
                break;
        }
    } while(!fl);
    system("pause");
}
