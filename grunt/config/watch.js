'use strict';

module.exports = {
	css: {
		files: 'www/app/Resources/less/*.less',
		tasks: [
			'less:dev'
		],
		options: {
			spawn: false
		}
	}

};
