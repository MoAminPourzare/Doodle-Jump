CC := g++
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: doodleJump.out

doodleJump.out: main.o shape.o functions.o doodle.o platform.o mplatform.o bplatform.o enemy.o spring.o rsdl.o
	$(CC) main.o shape.o rsdl.o spring.o enemy.o bplatform.o mplatform.o platform.o doodle.o functions.o $(CCFLAGS) -o doodleJump.out

main.o: rsdl.hpp shape.hpp doodle.hpp main.cpp
	$(CC) -c main.cpp -o main.o

functions.o: rsdl.hpp shape.hpp doodle.hpp platform.hpp mplatform.hpp bplatform.hpp spring.hpp enemy.hpp functions.hpp functions.cpp
	$(CC) -c functions.cpp -o functions.o

shape.o: rsdl.hpp shape.hpp shape.cpp
	$(CC) -c shape.cpp -o shape.o

doodle.o: rsdl.hpp shape.hpp doodle.hpp doodle.cpp
	$(CC) -c doodle.cpp -o doodle.o

platform.o: rsdl.hpp shape.hpp platform.hpp platform.cpp
	$(CC) -c platform.cpp -o platform.o

mplatform.o: rsdl.hpp shape.hpp mplatform.hpp mplatform.cpp
	$(CC) -c mplatform.cpp -o mplatform.o

bplatform.o: rsdl.hpp shape.hpp bplatform.hpp bplatform.cpp
	$(CC) -c bplatform.cpp -o bplatform.o

enemy.o: rsdl.hpp shape.hpp enemy.hpp enemy.cpp
	$(CC) -c enemy.cpp -o enemy.o

spring.o: rsdl.hpp shape.hpp spring.hpp spring.cpp
	$(CC) -c spring.cpp -o spring.o

rsdl.o: rsdl.hpp rsdl.cpp
	$(CC) -c rsdl.cpp -o rsdl.o

.PHONY: clean
clean:
	rm -r *.o