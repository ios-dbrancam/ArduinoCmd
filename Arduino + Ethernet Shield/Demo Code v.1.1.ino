// Sketch : Arduino [static IP: 192.168.1.111]
// Connection through Ethernet (ENET)
// Label Node > Displays the value readed from a potentiometer
// Button Node > Blinks a LED
// Switch Node > Toggles the state of a LED
// TextField Node > Set a PWM value to the LED

// Libraries
#include <SPI.h>
#include <Ethernet.h>

// STATIC IP DETAILS
// mac : unique MAC address
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// local : unique IP on the local network
byte local[] = {192, 168, 1, 111};
// to know how to configure the rest, in your iPhone go to:
// (the iPhone must be connected to the same network)
// Preferences > Wi-Fi > (i) on the WiFi network
// Router -> gateway
// Subnet Mask -> subnet
byte gateway[] = {192, 168, 1, 1};
byte subnet[] = {255, 255, 255, 0};

// Server instance
EthernetServer server(80);

// Server variables
String readString;

// Arduino pins
const int ledPin = 5;
const int potPin = 2;

// Sketch variables
bool isLedOn = false;

void setup() {
  // Serial initialization
  Serial.begin(9600);
  delay(2000);

  // Configures Ethernet connection
  Ethernet.begin(mac, local, gateway, subnet);
  server.begin();
  Serial.print("Server connected at: ");
  Serial.println(Ethernet.localIP());

  // LED & Pot pinModes
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  // Looks for client requests
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        readString += c;

        if (c == '\n') {
          // Request ended
          Serial.println(readString);

          // Server respond header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println("");

          // Create a IF statement for each node
          // Check Label Node Request
          if (readString.indexOf("/potValue") > 0) {
            int potValue = analogRead(potPin);
            client.println(potValue);
            Serial.println(potValue);

            // Check Switch Node Request
          } else if (readString.indexOf("/toggleLed") > 0) {
            if (readString.indexOf("?value") > 0) {
              isLedOn = (getValue(readString) == "1") ? true : false;
              digitalWrite(ledPin, isLedOn);
            }
            client.println(isLedOn ? "1" : "0");
            Serial.println(isLedOn);

            // Check Button Node Request
          } else if (readString.indexOf("/blinkLed") > 0) {
            digitalWrite(ledPin, !isLedOn);
            delay(200);
            digitalWrite(ledPin, isLedOn);
            Serial.println("Blink!");

            // Check Text Field Node Request
          } else if (readString.indexOf("/pwmValue") > 0) {
            analogWrite(ledPin, getValue(readString).toInt());
            Serial.print("PWM: ");
            Serial.println(getValue(readString));
          }

          delay(5);
          client.stop();

          readString = "";
        }
      }
    }
  }
}

// Process input data from HTTP Request
// input "GET http://192.168.1.111/toggleLed?value=1 HTTP/1.1"
// return "1"
String getValue(String input) {
  int startIndex = (input.indexOf("=") + 1);
  int endIndex = input.indexOf(" ", startIndex);
  return input.substring(startIndex, endIndex);
}
