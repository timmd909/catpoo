//============================================================================
// Name        : server.cpp
// Author      : Tim Doerzbacher <tim@tim-doerzbacher.com>
// Version     : nunyabidness
// Copyright   : See LICENSE
// Description : CATPOO Thrift Server
//============================================================================

#include <cstdlib>
#include <iostream>
#include <string>

#include "motion.h"

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

using std::cout;
using std::endl;
using std::string

using cgicc::Cgicc;
using cgicc::HTTPHTMLHeader;
using cgicc::form_iterator;

int main (int argc, char **argv)
{
	try {
		Cgicc cgi;
		cout << HTTPHTMLHeader() << endl;

		form_iterator ic = cgi.getElement("command"),
					  id = cgi.getElement("direction");

		string command = "", direction = "";

		if (ic != cgi.getElements().end()) {
			command = **ic;
		}

		if (id != cgi.getElements().end()) {
			direction = **id;
		}

		cout << "<div>Command: " << command << "</div>\n";
		cout << "<div>Direction: " << direction << "</div>\n";

	} catch (exception &e) {
		std::cout << "Caught error: " << e.what() << endl;
	}

	return 0;
}
