							CC=gcc
LIBS=-lGL -lGLU -lglut

all: src/congestion_avoidance.c bic.o reno.o both.o
	gcc $(CFLAGS) src/congestion_avoidance.c $(LIBS) -o src/congestion_avoidance.o

bic.o : src/bic.c
	gcc  $(CFLAGS) src/bic.c $(LIBS) -o src/bic.o

reno.o: src/reno.o
	gcc $(CFLAGS) src/reno.c $(LIBS) -o src/reno.o

both.o: src/reno.o
	gcc $(CFLAGS) src/both.c $(LIBS) -o src/both.o

clean:
	-@rm -f src/*.o
	-@rm -rf build
