//============================================================================
// Name        : motion.h
// Author      : Tim Doerzbacher <tim@tim-doerzbacher.com>
// Version     : nunyabidness
// Copyright   : See LICENSE
// Description : CATPOO Motion
//============================================================================

#include <exception>
#include <vector>
#include <string>

#ifndef __CATPOO_SERVER_H_
#define __CATPOO_SERVER_H_

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed char    s8;
typedef signed short   s16;

#include "Maestro/protocol.h"

namespace CATPOO {

	namespace motion {

		const std::string DEVICE = "/dev/ttyACM0";
		// const int BAUD_RATE = 19200;
		const int BAUD_RATE = 14400;
		// const int BAUD_RATE = 9600;
		// const int BAUD_RATE = 2400;

		// this should be loaded from an external file in the future...
		// but for now, I don't really change the servos out that often
		// so I guess this'll do... :-/
		const unsigned int FRONT_RIGHT = 0x2;
		const unsigned int FRONT_LEFT  = 0x3;
		const unsigned int BACK_LEFT   = 0x0;
		const unsigned int BACK_RIGHT  = 0x1;

		void move(int direction);
		void turn(int direction);
		void stop();
	}
}

#endif
