all: Bat_signal.o
	gcc -o main Bat_signal.o
Bat_signal.o: Bat_signal.c
	gcc -c Bat_signal.c
run: 
	./main
