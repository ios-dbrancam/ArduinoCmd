## How it works
- Download the app from the [App Store](https://apps.apple.com/es/developer/david-brana-campos/id1047286431)

- Copy the code from this [GitHub page](https://github.com/ios-dbrancam/ArduinoCmd/blob/master/Arduino%20%2B%20Ethernet%20Shield/Demo%20Code%20v.1.1) to a new Arduino Sketch

- You need to modify some things of the sketch
  - Change lines *22 .. 23* to your IP Address values. If you don't know this value, connect your iPhone to the same network as the Arduino and go to **Preferences > Wi-Fi > (i)** on the WiFi network and there you will find the values. *Router -> gateway; Subnet Mask -> subnet*
    - `byte gateway[] = {192, 168, 1, 1};`
    - `byte subnet[] = {255, 255, 255, 0};`
    
- Upload the sketch

- Follow the schematic to connect a LED and a Potentiometer to the Arduino + Ethernet Shield

![Sch_Arduino](https://user-images.githubusercontent.com/53085860/63844897-4f523180-c989-11e9-8dfa-7fba6e71babb.png)

- Open **ArduinoCmd**, you will find four *nodes* on the Main Screen. The first one displays the value read from the potentiometer (slide down to update the value). The other ones control the LED, you will be able to blink the LED by pressing the button or toggling the state with the switch. *If the Main Screen is empty it's possible to restart the tutorial from the Preferences View.*

![MainView](https://user-images.githubusercontent.com/53085860/63841557-4f4f3300-c983-11e9-9d08-94ab39a06335.png)
