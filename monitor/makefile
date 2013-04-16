OBJS = runner.o file_reader.o
CC = g++
LIBS = -lzmq
INCLUDES = -I /usr/local/include

CFLAGS = -Wall -c
LFLAGS = -Wall

TARGET = -o monitor


all: $(OBJS)
	$(CC) $(INCLUDES) $(LIBS) $(TARGET) $(OBJS) main.cpp

runner.o: runner.h runner.cpp
	$(CC) $(CFLAGS) runner.cpp
	
file_reader.o: file_reader.h file_reader.h
	$(CC) $(CFLAGS) file_reader.cpp	

clean: clean-libs
	rm -Rf *.o monitor

clean-libs:
	rm -Rf libs/*.o

