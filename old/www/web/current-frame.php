<?php

$TEMP_FILE = sprintf("/tmp/frame-%04d", rand(1, 9000));
exec("streamer -c /dev/video1 -o $TEMP_FILE -s 640x480 -f jpeg");
exec("convert $TEMP_FILE $TEMP_FILE.png");

header('Content-Type: image/png');
readfile($TEMP_FILE.'.png');

exec("rm $TEMP_FILE $TEMP_FILE.png");
