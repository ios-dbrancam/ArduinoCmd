# ArduinoCmd
*ArduinoCmd is an iOS App that allows you to easily control an ESP32 throught WiFi using HTTP Requests*

![Icon _JPG](https://user-images.githubusercontent.com/53085860/61996380-09f1ca00-b094-11e9-99d6-222dbf378c7f.jpg)

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

    ![Schematic-_JPG](https://user-images.githubusercontent.com/53085860/61955957-6bdf0080-afbc-11e9-853c-4724fbf43e44.jpg)

- Open **ArduinoCmd**, you will find two *nodes* on the Main Screen. The first one displays the value read from the potentiometer (slide down to update the value). With the second one, you will be able to toggle the status of the LED by pressing the button.
