//============================================================================
// Name        : server.cpp
// Author      : Tim Doerzbacher <tim@tim-doerzbacher.com>
// Version     : nunyabidness
// Copyright   : See LICENSE
// Description : CATPOO Thrift Server
//============================================================================

#include <cstdlib>
#include <iostream>

#include <unistd.h>

#include "colors.h"
#include "vision.h"

using std::cout;
using std::endl;

void printUsage()
{
	cout << "Usage: catpoo_vision <channel>" << endl
		<< "Where channel is an integer from 0 to n. This maps directly to "<< endl
		<< colors::YELLOW << "/dev/video" << colors::MAGENTA << "X"
			<< colors::RESET << endl;
	return;
}


int main (int argc, char **argv)
{
	int frameDelay = 1000000 / CATPOO::FPS;

	if (argc < 2) {
		printUsage();
		exit(1);
	}

	int videoChannel = atoi(argv[1]);

	cout << endl << colors::YELLOW << "Starting up "
			<< colors::MAGENTA << "CATPOO"
			<< colors::YELLOW << " Thrift Server" << colors::RESET
			<< endl << endl;

	while (true) {
		CATPOO::captureFrame(videoChannel);

		cout << "Grabbed frame, sleeping " << (frameDelay/1000) << "ms..." << endl;
		usleep(frameDelay);
	}


	return 0;
}

