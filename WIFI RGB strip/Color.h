/*
기존 LED 코드 복사 TV ambilight 만들기
*/
#ifndef Color_h
#define Color_h

#include "Arduino.h"

class Color {
  public:
    Color(int redPIN, int greenPIN, int bluePIN);
    void red();
    void green();
    void blue();

    void orange(); //
    void lightgreen();
    void lightblue();
    void lightorange();
    void darkmagenta();
    void lightmagenta();
    void lightcyan();
    void yellow();
    void indigo();
    void cyan();
    void magenta();
    void white();
    void off();
    void pink();
    void rainbow();
  private:
    int _redPIN, _greenPIN, _bluePIN;

};

#endif
