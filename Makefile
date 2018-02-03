CC=gcc
flags = -w -lm -lSDL2 -lSDL2_image
objects = main.o game.o window.o tiles.o
targets = Cythen

all: $(targets)
	make $(targets)

Cythen: $(objects)
	$(CC) $(flags) -o $@ $(objects)

main.o: game.h
game.o: window.h game.h
window.o: window.h
tiles.o: tiles.h

.PHONY: clean
clean:
	rm $(targets) $(objects)
