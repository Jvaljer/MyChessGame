#this is the makefile for 'MyChessGame'

CC=gcc     #used compiler
TRGT=main  #target file name (executable)
TST=test   #target test file name (executable)

compile:
	$(CC) -o $(TRGT) main.c Coord.c Slot.c Token.c Board.c Game.c Turn.c Coord.h Slot.h Token.h Board.h Game.h Turn.h

clean:
	rm $(TRGT)
	rm $(TST)

run:
	./$(TRGT)

test:
	$(CC) -o $(TST) tests.c Test.c Coord.c Slot.c Token.c Board.c Game.c Turn.c Test.h Coord.h Slot.h Token.h Board.h Game.h Turn.h
	./$(TST)
	rm $(TST)

execute:
	make compile
	make run 
	rm $(TRGT)