/*
Joe Mulhern 2017
PWM colors for strips. Make with RGB LEDs
*/
#include "Color.h"

Color::Color(int redPIN, int greenPIN, int bluePIN){
    _redPIN = redPIN;
    _greenPIN = greenPIN;
    _bluePIN = bluePIN;
    pinMode(_redPIN, OUTPUT);
    pinMode(_greenPIN, OUTPUT);
    pinMode(_bluePIN, OUTPUT);
}
//빨강
void Color::red(){
  analogWrite(_redPIN, 255);
  analogWrite(_greenPIN, 0);
  analogWrite(_bluePIN, 0);
}
//초록
void Color::green(){
  analogWrite(_redPIN, 0);
  analogWrite(_greenPIN, 255);
  analogWrite(_bluePIN, 0);
}
//파랑
void Color::blue(){
  analogWrite(_redPIN, 0);
  analogWrite(_greenPIN, 0);
  analogWrite(_bluePIN, 255);
}
//초록
void Color::orange(){
  analogWrite(_redPIN, 237);
  analogWrite(_greenPIN, 109);
  analogWrite(_bluePIN, 0);
}
//밝은 초록
void Color::lightgreen(){
  analogWrite(_redPIN, 0);
  analogWrite(_greenPIN, 107);
  analogWrite(_bluePIN, 0);
}
//밝은 파랑
void Color::lightblue(){
  analogWrite(_redPIN, 50);
  analogWrite(_greenPIN, 0);
  analogWrite(_bluePIN, 107);
}
//밝은 노랑색
void Color::lightorange(){
  analogWrite(_redPIN, 150);
  analogWrite(_greenPIN, 109);
  analogWrite(_bluePIN, 0);
}
//청록색
void Color::lightcyan(){
  analogWrite(_redPIN, 0);
  analogWrite(_greenPIN, 155);
  analogWrite(_bluePIN, 255);
}
//밝은 자홍색
void Color::lightmagenta(){
  analogWrite(_redPIN, 255);
  analogWrite(_greenPIN, 0);
  analogWrite(_bluePIN, 150);
}
//노랑색
void Color::yellow(){
  analogWrite(_redPIN, 255);
  analogWrite(_greenPIN, 215);
  analogWrite(_bluePIN, 0);
}
//어두운 자홍색
void Color::darkmagenta(){
  analogWrite(_redPIN, 150);
  analogWrite(_greenPIN, 0);
  analogWrite(_bluePIN, 150);
}
//남색
void Color::indigo(){
  analogWrite(_redPIN, 0);
  analogWrite(_greenPIN, 46);
  analogWrite(_bluePIN, 90);
}
// 자홍색
void Color::magenta(){
  analogWrite(_redPIN, 255);
  analogWrite(_greenPIN, 0);
  analogWrite(_bluePIN, 255);
}
//핑크색
void Color::pink(){
  analogWrite(_redPIN, 158);
  analogWrite(_greenPIN, 4);
  analogWrite(_bluePIN, 79);
}
//청록색
void Color::cyan(){
  analogWrite(_redPIN, 0);
  analogWrite(_greenPIN, 255);
  analogWrite(_bluePIN, 255);
}
//하얀색
void Color::white(){
  analogWrite(_redPIN, 255);
  analogWrite(_greenPIN, 255);
  analogWrite(_bluePIN, 255);
}
//LED off
void Color::off(){
  analogWrite(_redPIN, 0);
  analogWrite(_greenPIN, 0);
  analogWrite(_bluePIN, 0);
}
//레인보우(RGB색상)
void Color::rainbow(){
  int FADESPEED = 10;

  for (int r = 0; r < 256; r++) {
   analogWrite(_redPIN, r);
   delay(FADESPEED);
 }
 // 보라색에서 빨강색
 for (int b = 255; b > 0; b--) {
   analogWrite(_bluePIN, b);
   delay(FADESPEED);
 }
 // 빨간색에서 노랑색
 for (int g = 0; g < 256; g++) {
   analogWrite(_greenPIN, g);
   delay(FADESPEED);
 }
 // 노란색에서 초록색
 for (int r = 255; r > 0; r--) {
   analogWrite(_redPIN, r);
   delay(FADESPEED);
 }
 // 초록색에서 청록색
 for (int b = 0; b < 256; b++) {
   analogWrite(_bluePIN, b);
   delay(FADESPEED);
 }
 // 청록색에서 파란색
 for (int g = 255; g > 0; g--) {
   analogWrite(_greenPIN, g);
   delay(FADESPEED);
 }

}
