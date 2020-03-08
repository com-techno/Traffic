#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#define pinR 13
#define RED *new RGBColor(255, 0, 0)

#include "LiquidCrystal/LiquidCrystal.h"
#include "WiFi/WiFi.h"

class RGBColor{
public:
    int r;
    int g;
    int b;

    RGBColor(int r, int g, int b) : r(r), g(g), b(b) {}
};

void setColor(RGBColor color){
    analogWrite(pinR, color.r);
    analogWrite(12, color.g);
    analogWrite(11, color.b);

}

void setup() {
    pinMode(13,1);
    Serial.begin(9600);
}
void loop() {
    if (Serial.available() > 0) {
        int r = Serial.parseInt();
        int g = Serial.parseInt();
        int b = Serial.parseInt();
        Serial.print(r);
        Serial.print(" ");
        Serial.print(g);
        Serial.print(" ");
        Serial.println(b);
        if (!(r == 0 && g == 0 && b == 0))
        setColor(*new RGBColor(r, g, b));
    }
}