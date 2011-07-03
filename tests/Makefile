CFLAGS+=-W -Wall  -pedantic -I..
LDFLAGS+=-lid3 -lsqlite3 -I..
EXEC=test

SOURCES=$(wildcard *.cpp)
SOURCES+=$(wildcard ../sqladapter/*.cpp)
SOURCES+=$(wildcard ../browser/*.cpp)
SOURCES+=$(wildcard ../library/*.cpp)
SOURCES+=$(wildcard ../id3tool/*.cpp)
SOURCES+=$(wildcard ../defines/*.cpp)
SOURCES+=$(wildcard ../logger/*.cpp)
SOURCES+=$(wildcard ../utils/*.cpp)


OBJECTS=$(SOURCES:.cpp=.o)

CC=g++

all: $(EXEC)

debug: CFLAGS= -Wall -W -DDEBUG -g -I..

debug: $(EXEC)

$(EXEC): mrproper $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean mrproper

clean:
	@find .. -name '*.o' -exec rm -f {} \;

mrproper:
	@rm -f $(EXEC)
	@rm -f *.db
