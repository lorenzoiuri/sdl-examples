OBJECTS=main.o circle.o Particle.o SDL_utils.o PVector.o utils.o
CC=gcc

PROGRAM_NAME=bounce_ball

$(PROGRAM_NAME):$(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROGRAM_NAME) -lSDL2
	@echo Done, run with ./$(PROGRAM_NAME)
	
clean:
	@echo Removing the object files:
	rm -f *.o bounce_ball
