CFLAGS+=-W -Wall 
LDFLAGS+=-lid3
EXEC=id3Rename
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
CC=g++
all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean mrproper

clean:
	@rm -f $(OBJECTS)

mrproper:
	@rm -f $(EXEC)
