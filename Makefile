LIBS = -lGL -lGLU -lglut -lSOIL

all : src/reno src/bic src/both src/draw_bmp src/congestion_avoidance.c
	@mkdir build

reno : src/reno.c
	gcc src/reno.c $(LIBS) -o src/reno.o

bic : src/bic.c
	gcc src/bic.c $(LIBS) -o src/bic.o

both : src/both.c
	gcc src/both.c $(LIBS) -o src/both.o

draw_bmp : src/draw_bmp.c
	gcc src/draw_bmp.c $(LIBS) -o src/draw_bmp.o

congestion_avoidance.c : src/congestion_avoidance.c
	gcc src/congestion_avoidance.c $(LIBS) -o build/congestion_avoidance.c

clean:
	-@rm -f src/*.o
	-@rm -rf build
