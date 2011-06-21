CFLAGS+=-W -Wall -Werror -pedantic -I.
LDFLAGS+=-lid3 -lsqlite3 -I.
EXEC=id3Rename

SOURCES=$(wildcard *.cpp)
SOURCES+=$(wildcard sqladapter/*.cpp)
SOURCES+=$(wildcard browser/*.cpp)
SOURCES+=$(wildcard library/*.cpp)
SOURCES+=$(wildcard id3tool/*.cpp)
SOURCES+=$(wildcard defines/*.cpp)
SOURCES+=$(wildcard main/*.cpp)

OBJECTS=$(SOURCES:.cpp=.o)

CC=g++

all: $(EXEC)

debug: CFLAGS= -Wall -W -DDEBUG -g -I.

debug: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean mrproper

clean:
	@find . -name *.o -exec rm -f {} \;

mrproper:
	@rm -f $(EXEC)
