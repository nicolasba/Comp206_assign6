PCproblem: Main.o Consumer.o Producer.o
	gcc -o PCproblem Main.o Consumer.o Producer.o
Main.o: Main.c Producer.h Consumer.h
	gcc -c Main.c
Consumer.o: Consumer.c Consumer.h
	gcc -c Consumer.c
Producer.o: Producer.c Producer.h
	gcc -c Producer.c
