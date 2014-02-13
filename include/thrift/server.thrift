

exception CatPooServerException {
	1:optional string details; 
}

service CatPooServer {
	void setServoSpeed(1:i32 index, 2:i32 speed) throws (1:CatPooServerException e);

	/**
	 * Direction < 0 - "Reverse"
	 * Direction = 0 - "Stop"
	 * Direction > 0 - "Forward"
	 */
	void activateServo(1:i32 index, 2:i32 direction) throws (1:CatPooServerException e);
	
	/** 
	 * Takes a picture using the specified UVC device and saves it to disk.
	 * `index` is the last part of the device filename (example: /dev/video0 -> 0)
	 * `filename` absolute or relative filename to save the image to
	 */ 
	void takePicture(1:i32 index, 2:string filename) throws (1:CatPooServerException e);	
}

