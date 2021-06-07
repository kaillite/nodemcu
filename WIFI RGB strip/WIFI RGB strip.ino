/*
LED 스트립바 만들기 기존 프로젝트 수정본
SMD 5050 기준으로 만들어져 있음
       Red : connected to D3 (GPIO0)
       Green: connected to D2 (GPIO2)
       Blue: connected to D4 (GPIO4)
*/

/* 라이브러리 호출*/
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "Color.h"
#include "mainpage.h"
 // OTA Includes
 #include <ArduinoOTA.h>


/* 네트워크 */
const char* ssid = "kaillite"; // 와이파이 이름
const char* password = "qwer3467"; // 와이파이 비번 
const char* device_name = "WiFi LED strip"; // you can access controller by http://led.local/
IPAddress ip(192,168,1,175);  // 고정 iP할당 
IPAddress gateway(192,168,1,1); //기본 게이트 웨이
IPAddress subnet(255,255,255,0); // 네트워크 넷마스크

const int redLED = 0;  // D3 GPIO0
const int greenLED = 2;  // D2 GPIO2
const int blueLED = 4;  // D4 GPIO4


/* Objects */
MDNSResponder mdns;
ESP8266WebServer server(80);




Color createColor(redLED, greenLED, blueLED);

void setup(void) {

  delay(1000);

  /* Begin some (un)important things */
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  WiFi.config(ip, gateway, subnet);
  Serial.println("");
  // OTA code
  ArduinoOTA.setHostname("LEDStrip");
  ArduinoOTA.setPassword((const char *)"qwer3467");
  ArduinoOTA.begin();
  /* Wait for WiFi connection */
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  /* Show some important information on Serial Monitor */
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

   /* Give name for the device */
  if (mdns.begin(device_name, WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }

  /* Show website (in browser), than send RGB code */
  server.on("/", []() {
    server.send(200, "text/html", webPage);
    Serial.println("Loaded main page");
    
    Serial.print("Pressed: ");
    Serial.println("on");
  });
  server.on("/lightup", []() {
    server.send(200, "text/html", webPage);
    createColor.rainbow();
    Serial.print("Pressed: ");
    Serial.println("lightup");
    delay(1000);
  });
  server.on("/lightdown", []() {
    server.send(200, "text/html", webPage);
    Serial.print("Pressed: ");
    Serial.println("lightdown");
    delay(1000);
  });
  server.on("/off", []() {
    server.send(200, "text/html", webPage);
    createColor.off();
    Serial.print("Pressed: ");
    Serial.println("off");
    delay(1000);
  });
  server.on("/on", []() {
    server.send(200, "text/html", webPage);
    createColor.white();
    Serial.print("Pressed: ");
    Serial.println("on");
    delay(1000);
  });

  server.on("/red", []() {
    server.send(200, "text/html", webPage);
    createColor.red();
    Serial.print("Pressed: ");
    Serial.println("red");
    delay(1000);
  });
  server.on("/green", []() {
    server.send(200, "text/html", webPage);
    createColor.green();
    Serial.print("Pressed: ");
    Serial.println("green");
    delay(1000);
  });
  server.on("/blue", []() {
    server.send(200, "text/html", webPage);
    createColor.blue();
    Serial.print("Pressed: ");
    Serial.println("blue");
    delay(1000);
  });
  server.on("/white", []() {
    server.send(200, "text/html", webPage);
    createColor.white();
    Serial.print("Pressed: ");
    Serial.println("white");
    delay(1000);
  });
  server.on("/red1", []() {
    server.send(200, "text/html", webPage);
    createColor.orange();
    Serial.print("Pressed: ");
    Serial.println("red1");
    delay(1000);
  });
  server.on("/green1", []() {
    server.send(200, "text/html", webPage);
    createColor.lightgreen();
    Serial.print("Pressed: ");
    Serial.println("green1");
    delay(1000);
  });
  server.on("/blue1", []() {
    server.send(200, "text/html", webPage);
    createColor.lightblue();
    Serial.print("Pressed: ");
    Serial.println("blue1");
    delay(1000);
  });
  server.on("/flash", []() {
    server.send(200, "text/html", webPage);
 
    Serial.print("Pressed: ");
    Serial.println("flash");
    delay(1000);
  });
  server.on("/red2", []() {
    server.send(200, "text/html", webPage);
    createColor.pink();
    Serial.print("Pressed: ");
    Serial.println("red2");
    delay(1000);
  });
  server.on("/green2", []() {
    server.send(200, "text/html", webPage);
    createColor.lightcyan();
    Serial.print("Pressed: ");
    Serial.println("green2");
    delay(1000);
  });
  server.on("/blue2", []() {
    server.send(200, "text/html", webPage);
    createColor.magenta();
    Serial.print("Pressed: ");
    Serial.println("blue2");
    delay(1000);
  });
  server.on("/strobe", []() {
    server.send(200, "text/html", webPage);

    Serial.print("Pressed: ");
    Serial.println("strobe");
    delay(1000);
  });

  server.on("/red3", []() {
    server.send(200, "text/html", webPage);
    createColor.lightorange();
    Serial.print("Pressed: ");
    Serial.println("red3");
    delay(1000);
  });
  server.on("/green3", []() {
    server.send(200, "text/html", webPage);
    createColor.cyan();
    Serial.print("Pressed: ");
    Serial.println("green3");
    delay(1000);
  });
  server.on("/blue3", []() {
    server.send(200, "text/html", webPage);
    createColor.lightmagenta();
    Serial.print("Pressed: ");
    Serial.println("blue3");
    delay(1000);
  });
  server.on("/fade", []() {
    server.send(200, "text/html", webPage);
    //irsend.sendNEC(IR_FADE, 32);
    Serial.print("Pressed: ");
    Serial.println("fade");
    delay(1000);
  });

  server.on("/red4", []() {
    server.send(200, "text/html", webPage);
    createColor.yellow();
    Serial.print("Pressed: ");
    Serial.println("red4");
    delay(1000);
  });
  server.on("/green4", []() {
    server.send(200, "text/html", webPage);
    createColor.indigo();
    Serial.print("Pressed: ");
    Serial.println("green4");
    delay(1000);
  });
  server.on("/blue4", []() {
    server.send(200, "text/html", webPage);
    createColor.darkmagenta();
    Serial.print("Pressed: ");
    Serial.println("blue4");
    delay(1000);
  });
  server.on("/smooth", []() {
    server.send(200, "text/html", webPage);
    //irsend.sendNEC(IR_SMOOTH, 32);
    Serial.print("Pressed: ");
    Serial.println("smooth");
    delay(1000);
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  ArduinoOTA.handle();
}
