//============================================================================
// Name        : server.cpp
// Author      : Tim Doerzbacher <tim@tim-doerzbacher.com>
// Version     : nunyabidness
// Copyright   : See LICENSE
// Description : CATPOO Thrift Server
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <cstdlib>

#include "motion.h"

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::exception;

using cgicc::Cgicc;
using cgicc::HTTPHTMLHeader;
using cgicc::form_iterator;

int main (int argc, char **argv)
{
	try {
		Cgicc cgi;

		// HTML output start up
		cout << HTTPHTMLHeader() << endl;
		cout << cgicc::html() << cgicc::head(cgicc::title("CATPOO Motion Response")) << endl;
		cout << cgicc::body() << endl;

		// grab input
		form_iterator
			ic = cgi.getElement("command"),
			id = cgi.getElement("direction");

		string command   = "";
		int    direction = 0;

		if (ic != cgi.getElements().end()) command = **ic;
		if (id != cgi.getElements().end()) direction = std::atoi((**id).c_str());

		cout << "<table>"
			<< "<tr><th>Command</th><td>" << command << "</td></tr>\n"
			<< "<tr><th>Direction</th><td>" << direction << "</td></tr>"
			<< "</table><hr />";

		// process command
		if (command == "move") {
			CATPOO::motion::move(direction);
		} else if (command == "turn") {
			CATPOO::motion::turn(direction);
		} else if (command == "stop") {
			CATPOO::motion::stop();
		} else {
			cout << "<h1>Error: &ldquo;" << command << "&rdquo; not recognized</h1>";
		} // switch

		cout << cgicc::body() << cgicc::html();

	} catch (exception &e) {
		std::cout << "Caught error: " << e.what() << endl;
	}

	return 0;
}

namespace CATPOO {

	namespace motion {

		void status(string message)
		{
			cout << "<div>" << message << "</div>\n";
		}

		template <typename T>
		T clamp(T value, T min, T max)
		{
			if (value < min) return min;
			if (value > max) return max;
			return value;
		}

		void execute(unsigned char *commands, int count)
		{
			std::fstream fs(CATPOO::commonConstants().CATPOO_SERVO_DEV.c_str());
			if (!fs.is_open()) {
				status("Unable to open input");
			} else {
				status("Opened serial port");
			}

			fs.write((const char*)commands, count);

			std::stringbuf buffer;
			std::ostream os (&buffer);
			os << "Wrote " << count << " bytes";
			status(buffer.str());
		}

		void setAllWheels(unsigned int right, unsigned int left)
		{
			unsigned char commands[3];
			commands[0] = COMMAND_MINI_SSC;

			commands[1] = CATPOO::commonConstants().CATPOO_SERVO_RIGHT;
			commands[2] = right;
			execute(commands, 3);

			commands[1] = CATPOO::commonConstants().CATPOO_SERVO_LEFT;
			commands[2] = left;
			execute(commands, 3);
		}

		void move(int direction)
		{
			direction = clamp(direction, -126, 126);

			// determine values for front wheels
			unsigned int rightTarget = (127 - direction),
					leftTarget = (127 + direction);

			cout << "Moving " << direction <<  "Left=" << leftTarget << " Right=" << rightTarget << endl;
			setAllWheels(leftTarget, rightTarget);

		}

		void turn(int direction)
		{
			direction = clamp(direction, -126, 126);
			cout << "Turning " << direction << endl;

			// determine values for front wheels
			unsigned int rightTarget = (127 - direction),
				leftTarget = (127 - direction);

			setAllWheels(leftTarget, rightTarget);
		}

		void stop(int channel)
		{
			// vector<unsigned char> commands;
			unsigned char commands[] = {
				COMMAND_SET_TARGET, CATPOO::commonConstants().CATPOO_SERVO_RIGHT, 0, 0,
				COMMAND_SET_TARGET, CATPOO::commonConstants().CATPOO_SERVO_LEFT,  0, 0
			};
			execute(commands, 4*4);
		}

		void stop()
		{
			cout << "Stopping" << endl;

			stop(0); stop(1);
		}
	}
}
