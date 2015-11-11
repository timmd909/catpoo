'use strict';

var FILES = {
	'www/web/css/bootstrap.css': 'www/app/Resources/less/bootstrap.less',
	'www/web/css/font-awesome.css': 'www/app/Resources/less/font-awesome.less',
	'www/web/css/style.css': 'www/app/Resources/less/style.less'
};

module.exports = {
	options: {
		compress: false
	},
	dev: {
		files: FILES
	},
	prod: {
		options: {
			compress: true
		},
		files: FILES
	}
};
