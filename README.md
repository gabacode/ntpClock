# Arduino clock synchronized with NTP server
![nodemcu-esp8266](https://github.com/gabacode/ntpClock/blob/master/images/matrix.jpg?raw=true)

Some time ago I bought a cheap alarm clock from the most famous international chinese online shop. It was quite good but every time the power went off, the clock resetted and I had to set it again with its not-so user friendly buttons.

So, I've decided to built a clock that would keep in sync with the an Network Time Protocol server, so that I didn't need to set it anymore. I had some spare NodeMCU-esp8266 left from a different project, got some LED display and made the first version. With a Matrix display it's even better, and had no problems ever since :)  

There are 2 versions of the clock in this repository, the [TM1637](https://github.com/gabacode/ntpClock/tree/master/TM1637) powered, featuring a tiny 7-segments display, and a bigger size matrix one, featuring the [MAX7219](https://github.com/gabacode/ntpClock/tree/master/MAX7219) display. Pick your favourite and feel free to use it and modify it as much as you want. 

## 7-segments display requirements (TM1637)

- [ESP8266WiFi](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi)  
- [NTPClient](https://github.com/arduino-libraries/NTPClient)  
- [TM1637](https://github.com/avishorp/TM1637)

## Matrix Display requirements (MAX7219)

- [ESP8266WiFi](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi)  
- [NTPClient](https://github.com/arduino-libraries/NTPClient)
- [MD_Parola](https://www.arduino.cc/reference/en/libraries/md_parola/)
