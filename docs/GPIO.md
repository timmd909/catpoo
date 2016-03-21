# Overview

| Device       | Pin  | I | O | A | D | Description                        |
|--------------|------|---|---|---|---|------------------------------------|
| Arduino      |  A0  | X |   | X |   | Proximity Sensor (front)
| Arduino      |  A1  | X |   | X |   | Proximity Sensor (left)
| Arduino      |  A2  | X |   | X |   | Proximity Sensor (right)
| Arduino      |  A3  | X |   | X |   | Proximity Sensor (back)
| Arduino      |  A4  | X |   | X |   | Audio input
| Arduino      |  A5  | X |   | X |   | Alcohol sensor
| Arduino      |  A6  | X |   | X |   | Smoke sensor
| Arduino      |   7  | X |   |   | X | Motion sensor
| Arduino      |   8  |   | X |   | X | Alcohol detected
| Arduino      |   9  |   | X |   | X | Smoke detected
| Arduino      |  10  |   | X |   | X | Motion sensor triggered
| Raspberry Pi |   5  |   | X |   | X | Ethernet connected
| Raspberry Pi |   6  |   | X |   | X | WiFi connected
| Raspberry Pi |  13  |   | X |   | X | WAP enabled
| Raspberry Pi |  19  |   | X |   | X | Servo command activity
| Raspberry Pi |  17  | X |   |   | X | Reset WAP
| Raspberry Pi |  27  | X |   |   | X | IR flood light toggle
| Raspberry Pi |  22  | X |   |   | X | Safe shutdown
| Raspberry Pi |  26  | X |   |   | X | Unassigned momentary switch #1
| Raspberry Pi |  20  | X |   |   | X | Unassigned momentary switch #2
| Raspberry Pi |  21  | X |   |   | X | Unassigned momentary switch #3



## Notes

* Both Raspberry Pi and Arduino's GPIOs run at 3.3v
* Arduino Micro has 20 total GPIOs
	* 7 can be used as PWM
	* 12 as analog
	* 6 are digital only
* Raspberry Pi has 26 I/O pins
	* 4 are for I2C (Assume I'll have some I2C devices)
	* 5 are for SPI (Assume I'll have some SPI devices)
	* 8 that don't have any alternate function
		* Use these first before using one that has another function
