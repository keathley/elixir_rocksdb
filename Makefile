CC=clang++
CPPFLAGS=-std=c++11 -Wall
LDFLAGS=-I/usr/local/lib -lrocksdb

OBJECTS=main.o

db: $(OBJECTS)
	$(CC) $(CPPFLAGS) $(OBJECTS) -o db $(LDFLAGS)

all: db

.PHONY: clean
clean:
	rm -f *~ *.o db
