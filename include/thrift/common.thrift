namespace cpp CATPOO

// -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=-

// SHM key for CATPOO
const i32 CATPOO_FRAME_KEY = 234634692

const i32 CATPOO_SERVO_LEFT  = 1
const i32 CATPOO_SERVO_RIGHT = 0

const string CATPOO_SERVO_DEV = "/dev/ttyACM0"

// -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=-

exception CatPooServerException {
	1:optional string details;
}
