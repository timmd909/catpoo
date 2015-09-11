AUTOMAKE_OPTIONS = subdir-objects

bin_PROGRAMS = motion

motion_SOURCES = \
	src/motion.cpp \
	src/motion.h

motion_CPPFLAGS = \
	-I $(srcdir)/../3rdparty/pololu-usb-sdk \
	-I $(srcdir)/../lib/ \
	-fpermissive

motion_LDADD = \
	-lcgicc \
	-lstdc++ \
	-lthrift \
	../lib/libcatpoo.a
