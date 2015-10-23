# Overview

| Device       | Port | I | O | A | D | Description                        |
|--------------|------|---|---|---|---|------------------------------------|
| Arduino      |      | X |   | X |   | Proximity Sensor (front)
| Arduino      |      | X |   | X |   | Proximity Sensor (left)
| Arduino      |      | X |   | X |   | Proximity Sensor (right)
| Arduino      |      | X |   | X |   | Proximity Sensor (back)
| Arduino      |      | X |   | X |   | Audio input
| Arduino      |      | X |   | X |   | Alcohol sensor
| Arduino      |      | X |   | X |   | Smoke sensor
| Arduino      |      | X |   |   | X | Motion sensor
| Arduino      |      |   | X |   | X | Alcohol detected
| Arduino      |      |   | X |   | X | Smoke detected
| Arduino      |      |   | X |   | X | Motion sensor triggered
| Raspberry Pi |      |   | X |   | X | Ethernet connected
| Raspberry Pi |      |   | X |   | X | WiFi connected
| Raspberry Pi |      |   | X |   | X | WAP enabled
| Raspberry Pi |      |   | X |   | X | Servo command activity
| Raspberry Pi |      | X |   |   | X | Reset WAP
| Raspberry Pi |      | X |   |   | X | IR flood light toggle
| Raspberry Pi |      | X |   |   | X | Safe shutdown
| Raspberry Pi |      | X |   |   | X | Unassigned momentary switch #1
| Raspberry Pi |      | X |   |   | X | Unassigned momentary switch #2
| Raspberry Pi |      | X |   |   | X | Unassigned momentary switch #3



## Notes

* Both Raspberry Pi and Arduino's GPIOs run at 3.3v
* Arduino Nano has total GPIOs
	* 8 are analog or digital
	* 6 are digital only
* Raspberry Pi has 26 I/O pins
	* 4 are for I2C (Assume I'll have some I2C devices)
	* 5 are for SPI (Assume I'll have some SPI devices)
	* 8 that don't have any alternate function
		* Use these first before using one that has another function
