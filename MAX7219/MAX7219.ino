#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

#define DATA_PIN 15
#define CS_PIN 13
#define CLK_PIN 12

const char *ssid     = "your-wifi-name";
const char *password = "your-wifi-password";
const long utcOffsetInSeconds = 3600;
int hours = 88;
int minutes = 88;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "it.pool.ntp.org", utcOffsetInSeconds);
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup() {
  P.begin();
  P.setIntensity(1);
  P.setTextAlignment(PA_CENTER);
  P.setCharSpacing(2);
  WiFi.begin(ssid, password);
  P.print(String(hours)+":"+String(minutes));
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  timeClient.begin();
}

void loop() {
  timeClient.update();
  hours = timeClient.getHours();
  minutes = timeClient.getMinutes();
  P.print(String(hours)+":"+ (minutes < 10 ? "0" + String(minutes) : String(minutes)));  
  delay(1000);
}
