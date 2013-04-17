OBJS = runner.o file_reader.o comms.o
CC = g++
ZMQ_LIBS = -lzmq
INCLUDES = -I /usr/local/include

CFLAGS = -Wall -c
LFLAGS = -Wall

TARGET = -o monitor


all: $(OBJS)
	$(CC)  $(TARGET) $(OBJS) $(INCLUDES) $(ZMQ_LIBS) main.cpp

comms.o: comms.h comms.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $(ZMQ_LIBS) comms.cpp

runner.o: runner.h runner.cpp
	$(CC) $(CFLAGS) runner.cpp
	
file_reader.o: file_reader.h file_reader.h
	$(CC) $(CFLAGS) file_reader.cpp	

clean: clean-libs
	rm -Rf *.o monitor

clean-libs:
	rm -Rf libs/*.o

