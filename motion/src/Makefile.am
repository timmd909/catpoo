bin_PROGRAMS = catpoo_motion

catpoo_motion_SOURCES = \
	motion.cpp motion.h \
	Serial.cpp Serial.h

catpoo_motion_CPPFLAGS = \
	-I $(srcdir)/../../3rdparty/pololu-usb-sdk \
	-fpermissive

catpoo_motion_LDADD = \
	-lboost_system \
	-lcgicc \ 
	-lstdc++
