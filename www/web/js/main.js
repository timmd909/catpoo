
require({
	baseUrl: 'js/',
	packages: [],
	paths: {
		// 'jquery': '../../../suit/src/js/lib/jquery',
	}
}, [
	'knockout',
	'lodash',
],
function (ko, _) {
	'use strict';

	function ajaxMotion(command, direction) {
		$.ajax({
			data: {
				command: command,
				direction: direction
			},
			dataType: 'html',
			url: '../motion.cgi',
			success: function (data) {
				console.log('Successfully ajaxd', data);
			},
			error: function (data) {
				console.log('Failed ajaxing', data);
			}
		});
	}

	function moveForward() {
		ajaxMotion('move', 200);
		setTimeout(stopMoving, 500);
	}

	function moveBackward() {
		ajaxMotion('move', -200);
		setTimeout(stopMoving, 500);
	}

	function turnLeft() {
		ajaxMotion('turn', -70);
		setTimeout(stopMoving, 100);
	}

	function turnRight() {
		ajaxMotion('turn', 70);
		setTimeout(stopMoving, 100);
	}

	function stopMoving() {
		ajaxMotion('stop', 0);
	}

	function toggleIR() {
		$.ajax({
			'url': '../toggle-ir.cgi',
			'dataType': 'text'
		});
	}

	function resizeVideoScreen() {
		console.log('centering video');
		var $videoScreen = $('.video-screen'),
				$videoScreenImage = $videoScreen.find('.video-screen_image');

		$videoScreenImage.css({
			top: 0,
			left: 0,
			right: 0,
			bottom: 'auto',
			width: '100%',
			height: 'auto'
		});

		var outerHeight = parseInt($videoScreen.height(), 10),
				outerWidth = parseInt($videoScreen.width(), 10),
				imageHeight = parseInt($videoScreenImage.height(), 10),
				imageWidth = parseInt($videoScreenImage.width(), 10);

		var expandVertically = function () {
			var newHeight = outerWidth * 9.0 / 16.0;
			$videoScreenImage.css({
				'width': outerWidth,
				'top': (outerHeight - newHeight) / 2.0
			});
		};

		var expandHorizontally = function () {
			var newWidth = outerHeight * 16.0 / 9.0;
			$videoScreenImage.css({
				'height': '100%',
				'left': ((outerWidth - newWidth) / 2.0),
				'width': newWidth
			});
		};


		if (outerHeight > outerWidth) {
			if (outerHeight > imageHeight) {
				expandHorizontally();
			} else {
				expandVertically();
			}
		} else {
			if (outerHeight > imageHeight) {
				expandHorizontally();
			} else {
				expandVertically();
			}
		}

		return;
	} // function resizeVideoScreen()

	var viewModel = {
		moving: ko.observable(0.0),
		turning: ko.observable(0.0),

		onScreenMovement: function (ignored, event) {
			debugger;
			return false;
		},

		moveForward: moveForward,
		moveBackward: moveBackward,
		turnLeft: turnLeft,
		turnRight: turnRight,
		stopMoving: stopMoving,
		toggleIR: toggleIR
	};

	$(window).on('resize', resizeVideoScreen);

	ko.applyBindings(viewModel);

	setTimeout(resizeVideoScreen, 0);
});
