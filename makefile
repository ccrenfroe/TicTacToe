CC = g++
# CFLAGS =
DEPS = player.hpp board.hpp game.hpp point.hpp

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< #$(CFLAGS)

tictactoemake:	main.o player.o board.o game.o point.o
		$(CC) -o tictactoe main.o player.o board.o game.o point.o
