PCproblem: ain.o consumer.o producer.o
  gcc -o PCproblem main.o consumer.o producer.o
main.o: Main.c
  gcc -c Main.c
consumer.o: Consumer.c
  gcc -c Consumer.c
producer.o: Producer.c
  gcc -c Producer.c
