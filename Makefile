CFLAGS+=-W -Wall -Werror -pedantic
LDFLAGS+=-lid3 -lsqlite3
EXEC=id3Rename
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
CC=g++
all: $(EXEC)
debug: CFLAGS= -Wall -W -DDEBUG -g
debug: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean mrproper

clean:
	@rm -f *.o

mrproper:
	@rm -f $(EXEC)
