#include <iostream>
using namespace std;
#define R 11
#define G 12
#define B 13


class Color {
public:
    int r;
    int g;
    int b;
    Color(int r, int g, int b);
};

Color::Color(int r, int g, int b) {

}

int main() {

    Color RED = *new Color(255, 0, 0);
    Color GREEN = *new Color(0, 255, 0);
    Color BLUE = *new Color(0, 0, 255);
    Color WHITE = *new Color(255, 255 , 255);

}

void setColor(int r, int g, int b) {

}
void setColor(Color color, int i, int i1) {
    setColor(color.r, color.g, color.b);
}

