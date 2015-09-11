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
#include "thrift/common_constants.h"

namespace CATPOO {

	namespace motion {

		void move(int direction);
		void turn(int direction);
		void stop();
	}

}

#endif
