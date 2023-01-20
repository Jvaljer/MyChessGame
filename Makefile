#this is the makefile for 'MyChessGame'

CC=gcc     #used compiler
TRGT=main  #target file name (executable)

compile:
	$(CC) -o $(TRGT) main.c Coord.c Slot.c Token.c Board.c Game.c Coord.h Slot.h Token.h Board.h Game.h 

clean:
	rm $(TRGT)
	
run:
	./$(TRGT)
