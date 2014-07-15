//============================================================================
// Name        : Serial.h
// Author      : Tim Doerzbacher <tim@tim-doerzbacher.com>
// Version     : nunyabidness
// Copyright   : See LICENSE
// Description : CATPOO Motion serial
//============================================================================

#include <string>

#include <boost/asio.hpp>

#ifndef __CATPOO_SERIAL_H_
#define __CATPOO_SERIAL_H_

namespace CATPOO {
	namespace motion {
		class Serial {
		private:
			boost::asio::io_service _io;
			boost::asio::serial_port _serial;

		public:
			Serial(std::string port, unsigned int baud_rate);

			void write(const std::string &s);
			void write(void *bytes, int num_bytes);
			void write(void *byte);

		}; // class Serial
	} // namespace Motion
} // namespace CATPOO


#endif
