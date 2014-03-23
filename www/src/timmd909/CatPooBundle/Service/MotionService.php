<?php

namespace timmd909\CatPooBundle\Service;

class MotionService extends ServiceBase
{
	const SET_TARGET = 0x84;
	const MINI_SET_TARGET = 0xFF;
	
	protected $frontRightChannel;
	protected $frontLeftChannel;
	protected $backLeftChannel;
	protected $backRightChannel;
	
	protected $commandPort;
	
	public function setCommandPort($filename)
	{
		$this->logger->info("Command port file: $filename");
	
		$this->commandPort = \dio_open($filename, O_NONBLOCK|O_RDWR);
		dio_fcntl($this->commandPort, F_SETFL, O_SYNC);
		
		\dio_tcsetattr($this->commandPort,
			array(
				'baud' => 9600,
				'bits' => 8,
				'stop' => 1,
				'parity' => 0
			)
		);
	}
	
	public function setChannels($frontRight, $frontLeft, $backLeft, $backRight)
	{
		$this->frontRightChannel = intval($frontRight);
		$this->frontLeftChannel  = intval($frontLeft);
		$this->backLeftChannel   = intval($backLeft);
		$this->backRightChannel  = intval($backRight);
	}	
	
	public function stop()
	{
		$this->sendCommand(array(
			self::SET_TARGET, $this->frontRightChannel, 0, 0,
			self::SET_TARGET, $this->frontLeftChannel , 0, 0,
			self::SET_TARGET, $this->backLeftChannel  , 0, 0,
			self::SET_TARGET, $this->backRightChannel , 0, 0
		));	
	}
	
	public function turn($direction)
	{
		$this->logger->info("Turning $direction");
		
		if ($direction == 0) {
			$frTarget = 127;
			$flTarget = 127;
		} elseif ($direction < 0) {
			$flTarget = 127 + $direction;
			$frTarget = 127 + $direction;
		} else {
			$flTarget = 128 - $direction;
			$frTarget = 128 - $direction;
		}
		$brTarget = $frTarget;
		$blTarget = $flTarget;
		
		$this->sendCommand(array(
			self::MINI_SET_TARGET, $this->frontRightChannel, $frTarget,
			self::MINI_SET_TARGET, $this->frontLeftChannel,  $flTarget,
			self::MINI_SET_TARGET, $this->backLeftChannel,   $blTarget,
			self::MINI_SET_TARGET, $this->backRightChannel,  $brTarget
		));
	}
	
	public function move($direction)
	{
		$this->logger->info("Moving $direction");
		if ($direction == 0) {
			$frTarget = 127;
			$flTarget = 127;
		} elseif ($direction < 0) {
			$flTarget = 128 - $direction;
			$frTarget = 127 + $direction;
		} else {
			$flTarget = 127 + $direction;
			$frTarget = 128 - $direction;
		}
		$brTarget = $frTarget;
		$blTarget = $flTarget;
		
		$this->sendCommand(array(
			self::MINI_SET_TARGET, $this->frontRightChannel, $frTarget,
			self::MINI_SET_TARGET, $this->frontLeftChannel,  $flTarget,
			self::MINI_SET_TARGET, $this->backLeftChannel,   $blTarget,
			self::MINI_SET_TARGET, $this->backRightChannel,  $brTarget
		));
	}
	
	protected function sendCommand(array $bytes)
	{
		$rawCommand = $this->pack($bytes);
		$this->printRaw($rawCommand);
		$bytesWritten = \dio_write($this->commandPort, $rawCommand);
	}
	
	protected function printRaw($raw)
	{
		$hexstring = bin2hex($raw);
		ob_start();
		for ($i=0; $i < strlen($hexstring)/2; $i++) {
			echo substr($hexstring, $i*2, 2), " ";
		}
		$this->logger->info("CMD: ".ob_get_clean());
	}
	
	public function pack(array $bytes)
	{
		$result = NULL;
		foreach ($bytes as $curr) $result .= \pack("C", $curr);
		return $result;	
	}
	
	function __destruct()
	{
		if ($this->commandPort) \dio_close($this->commandPort);
	}
	
} // class
