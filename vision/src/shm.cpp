//============================================================================
// Name        : server.cpp
// Author      : Tim Doerzbacher <tim@tim-doerzbacher.com>
// Version     : nunyabidness
// Copyright   : See LICENSE
// Description : CATPOO Thrift Server
//============================================================================

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "common_constants.h"

namespace CATPOO {

	/**
	 * Reserves the SHM area for the current frame
	 */
	void reserveFrameMem()
	{
		CATPOO::g_common_constants.CATPOO_FRAME_KEY;
	}

}
