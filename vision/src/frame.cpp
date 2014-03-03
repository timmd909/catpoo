//============================================================================
// Name        : server.cpp
// Author      : Tim Doerzbacher <tim@tim-doerzbacher.com>
// Version     : nunyabidness
// Copyright   : See LICENSE
// Description : CATPOO Thrift Server
//============================================================================

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

#include <opencv2/opencv.hpp>

#include "colors.h"
#include "vision.h"

using namespace std;
using namespace cv;

namespace CATPOO
{

	void captureFrame(int videoChannel)
	{
		Mat frame;
		VideoCapture cap;

		cap = VideoCapture(videoChannel);
		if (!cap.isOpened()) {
			throw 1; /// <@todo Make a custom Thrift class for this
		}
		cap.set(CV_CAP_PROP_FRAME_WIDTH,  CATPOO::FRAME_WIDTH);
		cap.set(CV_CAP_PROP_FRAME_HEIGHT, CATPOO::FRAME_HEIGHT);

		cap >> frame;

		cout << colors::WHITE << "Grabbing frame " << colors::BLUE << frame.cols << colors::GREEN
				<< "x" << colors::BLUE << frame.rows << colors::RESET << " ";

		// encode frame
		vector<uchar> jpegFrame;
		imencode(".jpg", frame, jpegFrame);

		cout << jpegFrame.size() << " bytes long...";

		// for now, we'll just dump the data to a file
		ofstream ofs("/tmp/frame.jpeg", std::ofstream::out);
		ofs.write((const char*)jpegFrame.data(), jpegFrame.size());
		//ofs << "Hello";
		ofs.close();

		// clean up and return
		cout << endl;
		return;
	}


}
