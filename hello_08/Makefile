CC = gcc
CFLAGS = -Wall -g -std=c99
LDFLAGS = -lm 

circle: circle.o circulararea.o 
	$(CC) $(LDFLAGS) -o $@ $^

circle.o: circle.c my.h 
	$(CC) $(CFLAGS) -o $@ -c $<

circulararea.o: circulararea.c
	$(CC) $(CFLAGS) -o $@ -c $< 

clean:
	rm *.o
	rm circle