# Cat Antagonizing Tactical Platform of Oppression (CATPOO)

This project utilizes a Rasperberry Pi for everything except sensor inputs.
For all inputs and blinken lights, an Arduino Nano is used.

# Required Parts

* Chassis
	* Currently, I'm using the schematics from `docs/circle chassis/`.
	* The actual chassis and stuff isn't really that important to this code,
		so it won't be documented well until I'm settled on a final design.
* Parts (not all of these should be purchased, make sure to prune out later)
	* [Arduino Nano](https://www.arduino.cc/en/Main/arduinoBoardNano)
	* [Raspberry Pi 2](https://www.raspberrypi.org/products/raspberry-pi-2-model-b/)
		* Not technically necessary, but having a Pi 2 is nicer. Any Pi will do
			if you got a different one laying around.
	* [Pi NoIR camera](https://www.adafruit.com/products/1567)
		* Cuz what's the point of a robot that can't see in the dark? How else
			can one scare away one's girlfriend effectively?
	* [IR Leds](https://www.adafruit.com/products/388)
		* The more, the merrier
	* Breadboards (just got a bunch)
	* Movement Related
		* Servo Route
			* [Maestro server controller](https://www.pololu.com/product/1350)
			* [2x Servos](https://www.pololu.com/product/1248)
			* [Track links](https://www.pololu.com/product/415)
			* [Sprockets](https://www.pololu.com/product/224)
		* Stepper Motors Route
			* [Stepper Motor ICs (L293D)](http://www.amazon.com/PIXNOR-16-pin-Stepper-Drivers-Controllers/dp/B00ODQM8KC/ref=pd_cp_147_1?ie=UTF8&refRID=163T73NC2XDBT193E2NF)
			* [Arduino usage instructions](http://www.instructables.com/id/Control-your-motors-with-L293D-and-Arduino/?ALLSTEPS)
			* [TB6612 breakout board](https://learn.adafruit.com/adafruit-tb6612-h-bridge-dc-stepper-motor-driver-breakout)
				* [How to use it](https://learn.adafruit.com/adafruit-tb6612-h-bridge-dc-stepper-motor-driver-breakout/using-stepper-motors)
		* Plain Motor
			* [298:1 Micro Metal Gearmotor MP](https://www.pololu.com/product/2371) (less than 1/2" wide and tall)
				* [Mounting bracket](https://www.pololu.com/product/989)
				* [Pololu Micro Metal Gearmotor Bracket Extended Pair](https://www.pololu.com/product/1089)
	* Wheels
		* [VEX IQ 63mm Omni Wheels (2pk)](http://www.ebay.com/itm/VEX-IQ-63mm-Omni-Wheels-2pk-/121804737450?hash=item1c5c20cbaa:g:JtQAAOSw42JWDSlt) $10
* Things I wanna put in for no reason
	* [Vibration Motor 11.6×4.6×4.8mm](https://www.pololu.com/product/2265)
	* [Shaftless Vibration Motor 10x3.4mm](https://www.pololu.com/product/1636)

There are other miscellaneous things you'll need like extra wires, extra LEDs
for whatever, and so on. This will be documented More Better™ later on.

Or maybe not.

# Installing

Read `bootstrap/INSTRUCTIONS.md`.
