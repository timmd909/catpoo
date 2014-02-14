//============================================================================
// Name        : server.cpp
// Author      : Tim Doerzbacher <tim@tim-doerzbacher.com>
// Version     : nunyabidness
// Copyright   : See LICENSE
// Description : CATPOO Thrift Server
//============================================================================

#include <string>

#ifndef __COLOR_H_
#define __COLOR_H_

namespace colors {
	const static std::string BLACK   = "\033[1;30m";
	const static std::string RED     = "\033[31;1m";
	const static std::string GREEN   = "\033[32;1m";
	const static std::string YELLOW  = "\033[33;1m";
	const static std::string BLUE    = "\033[34;1m";
	const static std::string MAGENTA = "\033[35;1m";
	const static std::string CYAN    = "\033[36;1m";
	const static std::string WHITE   = "\033[37;1m";
	const static std::string RESET   = "\033[0m";
}

#endif
