## How it works
- Download the app from the [App Store](https://apps.apple.com/es/developer/david-brana-campos/id1047286431)

- Download and install the [WebServer Library](https://github.com/espressif/arduino-esp32/tree/master/libraries/WebServer)

- Copy the code from this [GitHub](https://github.com/ios-dbrancam/ArduinoCmd/blob/master/Arduino%20Code%20Example) repo to an Arduino Sketch

- You need to modify some things of the sketch
  - Change lines *13 .. 14* to your current WiFi network name and password
    - `const char* ssid = "YOUR_NETWORK_NAME";`
    - `const char* password = "YOUR_NETWORK_PASSWORD"`
  - Change lines *25 .. 28* to your IP Address values. If you don't know this value, connect your iPhone to the same network as the ESP32 and go to **Preferences > Wi-Fi > (i)** on the WiFi network and there you will find the values. *Router -> gateway; Subnet Mask -> subnet; DNS -> primaryDNS and secondaryDNS.*
    - `IPAddress gateway(192,168,1,1);`
    - `IPAddress subnet(255, 255, 255, 0);`
    - `IPAddress primaryDNS(80, 58, 62, 250);`
    - `IPAddress secondaryDNS(80, 58, 62, 254);`
    
- Upload the sketch

- Follow the schematic to connect a LED and a Potentiometer to the ESP32

![Sch_ESP32](https://user-images.githubusercontent.com/53085860/63838104-0300f480-c97d-11e9-9689-151bde8b2621.png)

- Open **ArduinoCmd**, you will find two *nodes* on the Main Screen. The first one displays the value read from the potentiometer (slide down to update the value). With the second one, you will be able to toggle the status of the LED by pressing the button.


## Quick Reference

![Diagram](https://user-images.githubusercontent.com/53085860/62040503-0d9f6100-b1fa-11e9-8252-637cf517f245.jpg)