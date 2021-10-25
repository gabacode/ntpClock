#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <TM1637Display.h>

#define CLK 4
#define DIO 0

const char *ssid     = "your-wifi-name";
const char *password = "your-wifi-password";

const long utcOffsetInSeconds = 7200;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);
TM1637Display display(CLK, DIO);

void setup(){
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  Serial.begin(115200);
  display.setBrightness(0x8);
  display.setSegments(data);
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();
  display.showNumberDec(timeClient.getHours(),false,2,0);
  display.showNumberDec(timeClient.getMinutes(),false,2,2);
  delay(1000);
}
