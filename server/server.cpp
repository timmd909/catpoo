//============================================================================
// Name        : server.cpp
// Author      : Tim Doerzbacher <tim@tim-doerzbacher.com>
// Version     : nunyabidness
// Copyright   : See LICENSE
// Description : CATPOO Thrift Server
//============================================================================

//#include <cstdio>
#include <cstdlib>
#include <iostream>

using std::cout;

#include "color.h"

int main (void) {

	cout << std::endl << colors::YELLOW << "Starting up "
			<< colors::MAGENTA << "CATPOO"
			<< colors::YELLOW << " Thrift Server" << colors::RESET
			<< std::endl << std::endl;



	return EXIT_SUCCESS;
}
