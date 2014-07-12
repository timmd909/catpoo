//============================================================================
// Name        : vision.h
// Author      : Tim Doerzbacher <tim@tim-doerzbacher.com>
// Version     : nunyabidness
// Copyright   : See LICENSE
// Description : CATPOO Vision
//============================================================================

#include <vector>
#include <opencv2/opencv.hpp>

#ifndef __CATPOO_SERVER_H_
#define __CATPOO_SERVER_H_

namespace CATPOO {

	namespace vision {
		static const float FPS = 1.0f;

		static const int FRAME_WIDTH  = 640;
		static const int FRAME_HEIGHT = 360;

		void captureFrame(int videoChannel);
	}

}

#endif
