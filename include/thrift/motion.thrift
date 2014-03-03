namespace cpp CATPOO.Motion

// -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- 

include "common.thrift" 

// -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- 

service CatPooMotion {

	/**
	 * Sets a particular servo's speed.  
	 * 
	 * @param index servo (0 indexed)
	 * @param speed 127 = stop, 128+ forward, 127- backward
	 *
	 * The further the speed is from 127, the faster the wheels will spin. 	 
	 */
	void setServoSpeed(1:i32 index, 2:i32 speed) throws (1:common.CatPooServerException e);

	/**
	 * Returns true or false depending on if motion is detected. 
	 */
	bool getMotionDetected() throws (1:common.CatPooServerException e);
}
