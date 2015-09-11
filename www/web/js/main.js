
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
	}

	function moveBackward() {
		ajaxMotion('move', -200);
	}

	function turnLeft() {
		ajaxMotion('turn', -200);
	}

	function turnRight() {
		ajaxMotion('turn', 200);
	}

	function stopMoving() {
		ajaxMotion('stop', 0);
	}

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
		stopMoving: stopMoving
	};

	ko.applyBindings(viewModel);
});
