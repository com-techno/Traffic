#include <Arduino.h>

int convertHex(int8_t ch){
  switch (ch) {
    case 'A': case 'a': return 10;
    case 'B': case 'b': return 11;
    case 'C': case 'c': return 12;
    case 'D': case 'd': return 13;
    case 'E': case 'e': return 14;
    case 'F': case 'f': return 15;
    default: return ch;
  }
}

class RGBColor{
private:
  uint8_t red;
  uint8_t green;
  uint8_t blue;

public:
  RGBColor(uint8_t r, uint8_t g, uint8_t b){
    this->red = r;
    this->green = g;
    this->blue = b;
  }

  static RGBColor parseColor(String hex){
    if (hex.startsWith("#")) {
      String red = hex.substring(1,2);
      String green = hex.substring(3,2);
      String blue = hex.substring(5,2);
      uint8_t r = convertHex(red[0]) * 16 + convertHex(red[1]);
      uint8_t g = convertHex(green[0]) * 16 + convertHex(green[1]);
      uint8_t b = convertHex(blue[0]) * 16 + convertHex(blue[1]);
      return *new RGBColor(r, g, b);
    }
  }

  String toString(){
    return ''.join("(" + red + ", " + green + ", " + blue + ")");
  }

};




void setup() {

}

void loop() {

}
