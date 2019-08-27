// Sketch : ESP32 [static IP: 192.168.1.111]
// Connection through WiFi
// Label Node > Displays the value readed from a potentiometer
// Button Node > Blinks a LED
// Switch Node > Toggles the state of a LED
// TextField Node > Set a PWM value to the LED*

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
IPAddress local(192, 168, 1, 111);
// to know how to configure the rest of the IPAddresses go in your iPhone to:
// (the iPhone must be connected to the same networks as the ESP32)
// Preferences > Wi-Fi > (i) on the WiFi network
// Router -> gateway
// Subnet Mask -> subnet
// DNS -> primaryDNS & secondaryDNS
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(80, 58, 62, 250);
IPAddress secondaryDNS(80, 58, 62, 254);

// WebServer instance
WebServer server(80);

// ESP32 Pins
const int ledPin = 15;
// const int ledChannel = 0;
const int potPin = 34;

// Sketch variables
bool isLedOn = false;

void setup() {
  // Serial initialization
  Serial.begin(115200);
  delay(2000);

  // Configures WiFi connection
  if (!WiFi.config(local, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("Failed to config");
  }
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.print("Connected to the WiFi network // IP: ");
  Serial.println(WiFi.localIP());

  // Initialize server
  server.begin();

  // Add here the 'code' of the nodes
  // .on(nodeCode, arduinoFunction)
  server.on("/potValue", handlePotValue);
  server.on("/toggleLed", handleToggle);
  server.on("/blinkLed", handleBlink);
  server.on("/pwmValue", handlePWM);

  // LED & Pot pinModes
  pinMode(ledPin, OUTPUT);
  // ledcSetup(ledChannel, 5000, 8);
  // ledcAttachPin(ledPin, ledChannel);
  pinMode(potPin, INPUT);
}

void loop() {
  server.handleClient();
}

// Reads the value of the potentiometer and sends it
void handlePotValue() {
  int potValue = analogRead(potPin);
  server.send(200, "text/html", String(potValue));
  Serial.println(potValue);
}

// Toggles the state of a LED
void handleToggle() {
  if (server.args()) {
    isLedOn = server.arg("value") == "1" ? true : false;
    digitalWrite(ledPin, isLedOn);
  }
  server.send(200, "text/html", isLedOn ? "1" : "0");
  Serial.println(isLedOn);
}

// Blinks the LED
void handleBlink() {
  digitalWrite(ledPin, !isLedOn);
  delay(200);
  digitalWrite(ledPin, isLedOn);
  server.send(200, "text/html", "OK");
  Serial.println("Blink!");
}

// Sets a PWM value on the LED
// digitalWrite & ledcWrite can't be
// used simultaneously, so it only prints it
void handlePWM() {
  int pwmValue = server.arg("value").toInt();
  // ledcWrite(ledChannel, pwmValue);
  server.send(200, "text/html", "OK");
  Serial.println(pwmValue);
}
