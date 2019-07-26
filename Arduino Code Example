// Sketch ESP32 [static IP: 192.168.1.111]
// Read potentiometer value and display it as a Label Node
// Toggle the state of a LED with a Button Node
// Connection through WiFi

// Libraries
// To download WebServer.h >> github.com/espressif/arduino-esp32/tree/master/libraries/WebServer
#include <WiFi.h>
#include <WebServer.h>

// Your Network Name (SSID) & Password
// Change them to your network name and password
const char* ssid = "YOUR_NETWORK_NAME";
const char* password = "YOUR_NETWORK_PASSWORD";

// STATIC IP DETAILS
// local must be a unique IP on the local network
IPAddress local(192,168,1,111);
// to know how to configure the rest of the IPAddresses go in your iPhone to:
// (the iPhone must be connected to the same networks as the ESP32)
// Preferences > Wi-Fi > (i) on the WiFi network
// Router -> gateway
// Subnet Mask -> subnet
// DNS -> primaryDNS & secondaryDNS
IPAddress gateway(192,168,1,1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(80, 58, 62, 250);
IPAddress secondaryDNS(80, 58, 62, 254);

// WebServer instance
WebServer server(80);

// ESP32 Pins
const int ledPin = 22;
const int potPin = 34;

// Variables
bool isLedOn = false;
int potValue = 0;

void setup() {
  // Serial initialization
  Serial.begin(115200);
  delay(2000);

  // Configures WiFi connection
  if(!WiFi.config(local, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("Failed to config");
  }

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.print("Connected to the WiFi network // IP: ");
  Serial.println(WiFi.localIP());

  // Initialize server
  server.begin();
  // Add here the 'code' of the nodes
  // .on(nodeCode, arduinoFunction)
  server.on("/toggleLed", handleToggle);
  server.on("/potValue", handlePotValue);

  // LED & Pot pinModes
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  server.handleClient();
}

// When server calls it the LED state is toggled
void handleToggle() {
  if(isLedOn) {
    digitalWrite(ledPin, LOW);
    Serial.println("LED: OFF");
  } else {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED: ON");
  }
  isLedOn = !isLedOn;
  server.send(200, "text/html", "done");
}

// When server calls it, reads the value of the pot and sends it
void handlePotValue() {
  potValue = analogRead(potPin);
  Serial.println(potValue);
  server.send(200, "text/html", String(potValue));
}
