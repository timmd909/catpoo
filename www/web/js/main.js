
require({
	baseUrl: 'js/',
	packages: [],
	paths: {
		// 'jquery': '../../../suit/src/js/lib/jquery',
	}
}, [
	'knockout'
],
function (ko) {
	'use strict';

	var viewModel = {
		moving: ko.observable(0.0),
		turning: ko.observable(0.0),

		onScreenMovement: function (ignored, event) {
			debugger;
			return false;
		}
	};

	ko.applyBindings(viewModel);
});
