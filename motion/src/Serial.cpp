//============================================================================
// Name        : Serial.cpp
// Author      : Tim Doerzbacher <tim@tim-doerzbacher.com>
// Version     : nunyabidness
// Copyright   : See LICENSE
// Description : CATPOO Motion serial
//============================================================================

#include <string>

#include "Serial.h"

namespace CATPOO {
	namespace motion {

		Serial::Serial(std::string port, unsigned int baud_rate):
			_io(), _serial(_io, port)
		{
			_serial.set_option(
				boost::asio::serial_port_base::baud_rate(baud_rate));
		}

		void Serial::write(const std::string &s) {
			write((void *)s.c_str(), s.size());

			// sometimes it doesn't work... as I think it's a servo controller
			// issue, and I'm not sure how to handle it, we're just going
			// to blast the same bits one extra time to be sure.
			write((void *)s.c_str(), s.size());
		}

		void Serial::write(void *bytes, int num_bytes) {
			boost::asio::write(_serial, boost::asio::buffer(bytes, num_bytes));
		}

		void Serial::write(void *byte) {
			boost::asio::write(_serial, boost::asio::buffer(byte, 1));
		}

	}
}
