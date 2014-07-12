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

		const unsigned int FRONT_RIGHT = 0x0;
		const unsigned int FRONT_LEFT  = 0x1;
		const unsigned int BACK_LEFT   = 0x2;
		const unsigned int BACK_RIGHT  = 0x3;

		void move(int direction);
		void turn(int direction);
		void stop();
	}
}

#endif
