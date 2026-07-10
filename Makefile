CFLAGS = -std=c11 -Wall -Wextra -g -O0 -Iinclude

mini_agent : main.o tui.o input.o
	gcc $(CFLAGS) -o mini_agent main.o tui.o input.o -lncurses
	./mini_agent

main.o : main.c tui.h input.h
	gcc $(CFLAGS) -c main.c -o main.o

tui.o : tui.c tui.h
	gcc $(CFLAGS) -c tui.c -o tui.o

input.o : input.c input.h tui.h
	gcc $(CFLAGS) -c input.c -o input.o

# draft : draft.o
# 	gcc $(CFLAGS) -o draft draft.o -lncurses
# 	./draft

clean : 
	rm -f mini_agent main.o tui.o input.o
	
.PHONY : clean