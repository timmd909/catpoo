/**
 * @copyright 2015 Tim Doerzbacher
 */
module.exports = function (grunt) {
	grunt.registerTask('volo:download', [
		'volo:add:-f:-nostamp:twbs/bootstrap/3.3.0:bootstrap'
	]);
};
