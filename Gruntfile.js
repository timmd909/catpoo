/*eslint-env node*/

'use strict';

/**
 * @author Tim Doerzbacher <tim@tim-doerzbacher.com>
 * @copyright 2015 Tim Doerzbacher
 */
module.exports = function(grunt) {
	var path = require('path'),
			fs = require('fs'),
			_ = require('lodash');

	var GRUNT_CONFIG_DIR = path.join(process.cwd(), 'grunt/config'),
			GRUNT_TASKS_DIR = path.join(process.cwd(), 'grunt/tasks');

	require('load-grunt-config')(grunt, {
		// path to task.js files, defaults to grunt dir
		configPath: GRUNT_CONFIG_DIR,

		// auto grunt.initConfig
		init: true,

		// data passed into config.  Can use with <%= test %>
		data: {
		}
	});

	var taskFiles = fs.readdirSync(GRUNT_TASKS_DIR);

	_.forEach(taskFiles, function (filename) {
		if (filename.match(/.*\.js$/)) {
			var moduleFilename = path.join(GRUNT_TASKS_DIR, filename);
			require(moduleFilename)(grunt);
		} else {
			console.log('Ignoring file: ' + filename);
		}
		return;
	});

};
