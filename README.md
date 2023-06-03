# wireless_motion_sensor_esp32
Small Saturday project utilizing two ESP32 (NodeMCU), two HC12 433 mHz radio modules, one HC-SR505 mini pir sensor, and one HW-508 (or KY-006) passive piezo buzzer. The power supply can be realized either via USB or by attaching a battery to the GPIO pins of the ESP.

One ESP (+PIR +HC12) acts as the motion detector and sends a signal to the other ESP (+HC12 +Buzzer), which then gives out an acoustic notification.

The range, depending on the set transmission power, can be >1km (outdoors). The price of the parts was around 92k sats (+soldering iron and 3D printed cases).

The .ino source files can be compiled and flashed to the ESP with the Arduino IDE.

Also, make sure your HC12 module works correctly; many Chinese clones need a simple fix to function correctly:
https://ytb.trom.tf/watch?v=ZfBuEAH-Q8Y


![IMG_20230603_231545_354](https://github.com/f321x/wireless_motion_sensor_esp32/assets/51097237/45946a81-4768-449f-95f2-d5ed001bbcdb)
