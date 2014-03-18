<?php

define(COMMAND_PORT, '/dev/ttyACM0');
define(SERIAL_PORT,  "/dev/ttyACM1");
//define(SERIAL_PORT,  "/dev/ttyAMA0");

function package(array $bytes)
{
	$result = NULL;
	foreach ($bytes as $curr) $result .= pack("C", $curr);
	return $result;	
}

function send_command($bytes)
{
	$command = package($bytes);

	echo "Sending command => ";
	$hexstring = bin2hex($command);
	for ($i=0; $i < strlen($hexstring)/2; $i++) {
		echo substr($hexstring, $i*2, 2), " ";
	}
	echo PHP_EOL;

	$fh = fopen(COMMAND_PORT, "w+b");
	
	stream_set_blocking($fh, 0);
	
	$bytesWritten = fwrite($fh, $command);
	
	fflush($fh);
	fclose($fh);
}

// -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- 

function reset_motors()
{
	send_command(array(
		0x84, 0, 0, 0,
		0x84, 1, 0, 0,
		0x84, 2, 0, 0,
		0x84, 3, 0, 0
	));
}

function set_motor_speed($channel, $speed)
{
	if ($speed > 1.0) $speed = 1.0;
	else if ($speed < -1.0) $speed = -1.0;

	$target = intval(127 + ($speed * 126));
			
	//echo "set_motor_speed($channel, $speed) -> target=$target\n";
	
	send_command(array(
		0xff, $channel, $target
	));
}

function turn_left($howLong=1)
{
	$target = 67;
	$target += 20;
	send_command(array(
		0xff, 0, $target,
		0xff, 1, $target,
		0xff, 2, $target,
		0xff, 3, $target
	));	
	usleep($howLong*1000000);
	reset_motors();
}

function turn_right($howLong=1)
{
	$target = 187;
	$target -= 20;
	send_command(array(
		0xff, 0, $target,
		0xff, 1, $target,
		0xff, 2, $target,
		0xff, 3, $target
	));
	usleep($howLong*1000000);
	reset_motors();
}

function go_forward($howLong=1)
{
	send_command(array(
		0xff, 0, 67+20,
		0xff, 1, 187-20,
		0xff, 2, 187-20,
		0xff, 3, 67+20
	));
	usleep($howLong*1000000);
	reset_motors();
}

function go_backward($howLong=1)
{
	send_command(array(
		0xff, 0, 187-20,
		0xff, 1, 67+20,
		0xff, 2, 67+20,
		0xff, 3, 187-20
	));
	usleep($howLong*1000000);
	reset_motors();
}

function motion_detected()
{
	//$result = send_command(array(0x90, 5));
	$bytes = array();
	$bytes[] = 0xaa;
	$bytes[] = 0x0; 
	$bytes[] = 0x10;
	$bytes[] = 0x05; 
	
	// $fh = fopen(COMMAND_PORT, "w+");
	// $result = send_command($bytes);
		
	
	// make sure dio is installed by doing this:
	//
	//    sudo pecl install channel://pecl.php.net/dio-0.0.7
	//
	$fh = dio_open(COMMAND_PORT, O_NONBLOCK|O_RDWR);
	dio_fcntl($fh, F_SETFL, O_SYNC);
	dio_tcsetattr($fh,
		array(
			'baud' => 9600,
			'bits' => 8,
			'stop' => 1,
			'parity' => 0
		)
	);
	
	
	$command = package($bytes);
	
	dio_write($fh, $command);
	
	$result = dio_read($fh);
	
	$unpacked = unpack("C*", $result);
	echo "Unpacked: " . print_r($unpacked, TRUE) . PHP_EOL;
		
	echo "Result of motion check: ".bin2hex($result).PHP_EOL;
	
	echo '$result & 0x7f = ' . ($result & 0x7f). PHP_EOL;
	
	return ($unpacked[2]) ? TRUE : FALSE;
}

//turn_left(2);
//go_forward(2);

if (!motion_detected()) {
	turn_right(rand(1,1000)/1000.0); 
} else {
	; // do nothing... things are moving
}
