#include "Arduino.h"
#define red_pin 2
#define green_pin 4
#define yellow_pin 3
#define buzzer_pin 13
#define btn_pin 10

class Led{
public:
  Led(uint8_t pin){
    this->pin = pin;
  }
  bool status;
  unsigned long last_change;
  uint8_t pin;
  uint8_t sw;

  void blink(){
    if (millis() - last_change > 500) {
      status = !status;
      last_change = millis();
    }
  }

  void fastBlink(){
    if (millis() - last_change > 200) {
      status = !status;
      last_change = millis();
    }
  }

  void apply(){
    switch (sw) {
      case 0:
        status = 0;
        break;
      case 1:
        status = 1;
        break;
      case 2:
        blink();
        break;
      case 3:
        fastBlink();
        break;
    }
  }

  void show(){
    apply();
    if(status) digitalWrite(pin, HIGH);
    else digitalWrite(pin, LOW);
  }
};

Led red = *new Led(red_pin);
Led yellow = *new Led(yellow_pin);
Led green = *new Led(green_pin);
Led buzzer = *new Led(buzzer_pin);

void setup() {
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(yellow_pin, OUTPUT);
  pinMode(btn_pin, INPUT);
  pinMode(buzzer_pin, INPUT);
  Serial.begin(9600);
}

uint8_t status = 0;
unsigned long last_press = 0;

void changeStatus(){
  if (status == 4) status = 0;
  else status++;
}

void applyStatus(uint8_t status){
  switch (status) {
    case 0:
      red.sw = 0;
      yellow.sw = 0;
      green.sw = 1;
      buzzer.sw = 2;
      break;
    case 1:
      red.sw = 0;
      yellow.sw = 0;
      green.sw = 2;
      buzzer.sw = 3;
      break;
    case 2:
      red.sw = 0;
      yellow.sw = 1;
      green.sw = 0;
      buzzer.sw = 0;
    case 3:
      red.sw = 1;
      yellow.sw = 0;
      green.sw = 0;
      buzzer.sw = 0;
      break;
    case 4:
      red.sw = 1;
      yellow.sw = 1;
      green.sw = 0;
      buzzer.sw = 0;
      break;
  }
}

void request(){
  if(millis() - last_press > 2000){
    digitalWrite(13, HIGH);
    if (digitalRead(btn_pin) == HIGH) {
      last_press = millis();
      changeStatus();
      applyStatus(status);
      digitalWrite(13, LOW);
    }
  }
}

void loop(){
  request();
  red.show();
  yellow.show();
  green.show();
  buzzer.show();
  Serial.println(digitalRead(btn_pin));
}
