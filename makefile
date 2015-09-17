CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp NeuralThread.cpp MemManager.cpp Reflex.cpp
OBJECTS=$(SOURCES:.cpp=.o)
LIBDIRS=-lpthread
EXECUTABLE=Net

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBDIRS) -o $@
clean:
	 rm -rf *o Net