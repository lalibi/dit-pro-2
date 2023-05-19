minsweeper: main.o minesweeper.o
	gcc -o minesweeper main.o minesweeper.o

main.o: minesweeper.h main.c
	gcc -c main.c

minesweeper.o: minesweeper.h minesweeper.c
	gcc -c minesweeper.c

clean:
	rm *.o minesweeper
