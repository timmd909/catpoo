#!/bin/bash

# header
echo "Content-type: text/plain"
echo ""

# Important variables
GPIOs="5 13 19 22"
ORIGINAL_VALUE="`cat /sys/class/gpio/gpio13/value`"

# Looping time!
for GPIO in $GPIOs; do

	VALUE_FILE="/sys/class/gpio/gpio$GPIO/value"

	if [ $ORIGINAL_VALUE -gt 0 ]; then
		echo "Turning IR lights off"
		NEW_VAL=0
	else
		echo "Turning IR lights on"
		NEW_VAL=1
	fi

	echo $NEW_VAL > $VALUE_FILE

done
