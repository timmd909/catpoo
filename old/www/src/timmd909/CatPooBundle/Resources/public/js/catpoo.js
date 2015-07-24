var VIDEO_SCREEN;
var MOUSE_STATUS;
var GENERAL_STATUS;

var OLD_SCREEN_X = -1;
var OLD_SCREEN_Y = -1;

var BUTTON_DOWN = false;

$(document).ready(function() {
	VIDEO_SCREEN = $('#video-screen');
	MOUSE_STATUS = $('#mouse-status');
	GENERAL_STATUS = $('#general-status');
	
	clearScreenIndicators();
	
	$(window).focusout(function() {
		GENERAL_STATUS.html("Window lost focus");
		stopMoving();
	});
	
//	VIDEO_SCREEN.mouseout(onMouseUp);
//	VIDEO_SCREEN.focusout(onMouseUp);
	VIDEO_SCREEN.mousedown(onMouseDown);
	VIDEO_SCREEN.mouseup(onMouseUp);
	VIDEO_SCREEN.mousemove(onMouseMove);
	
	VIDEO_SCREEN.on("tap", onMouseUp);
	VIDEO_SCREEN.on("vmousedown", onMouseDown);
	VIDEO_SCREEN.on("vmouseup"  , onMouseDown);
	VIDEO_SCREEN.on("vmousemove", onMouseMove);

	
	VIDEO_SCREEN.on("swipeleft", function() {
		startTurning(60);
	});
	VIDEO_SCREEN.on("swiperight", function() {
		startTurning(-60);
	});
	
	GENERAL_STATUS.html("Loaded.");
	
	$(window).on('keypress', function (event) {
		window.console.log(event);
		
		stopMoving(); 
		startTurning();
		
		switch (event.key) {
		case 'Left':
			window.console.log('Turning left');
			startTurning(event.shiftKey ? -80 : -40 );
			break;
		case 'Right':
			window.console.log('Turning right');
			startTurning(event.shiftKey ? 80 : 40 );
			break;
		case 'Up': 
			startMoving(event.shiftKey ? 80 : 40);
			break;
		case 'Down': 
			startMoving(event.shiftKey ? -80 : -40);
			break;
		}
	});
	
});

function onMouseUp(event)
{
	MOUSE_STATUS.html("Mouse is up");
	VIDEO_SCREEN.removeClass('active');
	
	stopMoving();
	
	OLD_SCREEN_X = -1;
	OLD_SCREEN_Y = -1;
	
	BUTTON_DOWN = false;
}

function clearScreenIndicators()
{
	$('#video-screen .right').hide();
	$('#video-screen .left').hide();
	$('#video-screen .forward').hide();
	$('#video-screen .back').hide();
}

function onMouseDown(event)
{
	MOUSE_STATUS.html("Mouse is down");
	VIDEO_SCREEN.addClass('active');

	OLD_SCREEN_X = event.screenX;
	OLD_SCREEN_Y = event.screenY;

	BUTTON_DOWN = true;
}

function clamp(input, min, max)
{
	if (input < min) return min;
	if (input > max) return max;
	return input;
}

function onMouseMove(event) 
{
	var dx = 0; 
	var dy = 0;
	
	if (OLD_SCREEN_X >= 0) {
		dx = event.screenX - OLD_SCREEN_X;
	}
	if (OLD_SCREEN_Y >= 0) {
		dy = event.screenY - OLD_SCREEN_Y;
	}
	
	var screenWidth  = $(window).width(),
		screenHeight = $(window).height();
	
	var scaling; 
	
	var newStatus = "New position: " + event.screenX + ", " +
		event.screenY + "<br />" +
		"Change: " + dx + ", " + dy + "<br />";

	clearScreenIndicators();
	
//	OLD_SCREEN_X = event.screenX;
//	OLD_SCREEN_Y = event.screenY;

	// if the mouse isn't down, we don't need to do anything else 
	if (!BUTTON_DOWN) return;
	
	// determine how to respond
	if (Math.abs(dx) > Math.abs(dy)) {
		
		scaling = dx / (screenWidth+0.0) * 2.5;
		scaling = clamp(scaling, -1.0, 1.0);
		
		newStatus += "Turning (dx="+dx+") scaling=" + scaling;
		
		if (dx < 0) {
			$('#video-screen .left').show();
		} else {
			$('#video-screen .right').show();
		}
		startTurning(scaling*-100);
	} else {
		newStatus += "Moving";
		
		scaling = dy / (screenHeight+0.0) * 3.0;
		scaling = clamp(scaling, -1.0, 1.0);
		
		if (dy < 0) {
			// forward
			$('#video-screen .forward').show();
		} else {
			// back
			$('#video-screen .back').show();
		}
		startMoving(scaling*-100);
	}
		
	GENERAL_STATUS.html(
		newStatus
	);
}

function blockingGet(url) 
{
	$.ajax({
		"url": url,
		"async": false
	});
}

function startMoving(value)
{
//	$.get('/cgi/motion/catpoo_motion?command=move&direction=' + value)
	blockingGet('/cgi/motion/catpoo_motion?command=move&direction=' + value);
}

function startTurning(value)
{
	//$.get('/cgi/motion/catpoo_motion?command=turn&direction=' + value)
	blockingGet('/cgi/motion/catpoo_motion?command=turn&direction=' + value);
}

function stopMoving()
{
	$.get('/cgi/motion/catpoo_motion?command=stop');
}