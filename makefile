CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp CameraThread.cpp MemManager.cpp Reflex.cpp TrnThread.cpp
OBJECTS=$(SOURCES:.cpp=.o)
LIBDIRS=-lpthread
EXECUTABLE=Net
out_obj=./out
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBDIRS) -o $(out_obj)/$@
	rm -rf *o
clean:
	 rm -rf *o Net $(out_obj)/*
