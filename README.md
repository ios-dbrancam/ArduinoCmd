# ArduinoCmd
*ArduinoCmd is an iOS App that allows you to easily control an ESP32 throught WiFi using HTTP Requests*

![Icon-_JPG](https://user-images.githubusercontent.com/53085860/61950423-0f74e480-afae-11e9-9aba-a4c44ea940bc.jpg)

## How it works
- Download the app from the [App Store](https://apps.apple.com/es/developer/david-brana-campos/id1047286431)

- Download the library from [WebServer Library](https://github.com/espressif/arduino-esp32/tree/master/libraries/WebServer)

- Copy the code from this [GitHub](https://github.com/ios-dbrancam/ArduinoCmd/blob/master/Arduino%20Code%20Example) repo to an Arduino Sketch

- You need to modify some things of the sketch
  - Change this lines to your current WiFi network name and password
    - `const char* ssid = "YOUR_NETWORK_NAME";`
    - `const char* password = "YOUR_NETWORK_PASSWORD"`
  
    - `IPAddress gateway(192,168,1,1);`
    - `IPAddress subnet(255, 255, 255, 0);`
    - `IPAddress primaryDNS(80, 58, 62, 250);`
    - `IPAddress secondaryDNS(80, 58, 62, 254);`
    

