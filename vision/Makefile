CXXFLAGS = -O2 -g -Wall -fmessage-length=0

OBJS = vision.o frame.o 

LIBS = -lthrift -lopencv_highgui -lopencv_video -lopencv_core -lopencv_imgproc

TARGET = vision

# -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- 

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
