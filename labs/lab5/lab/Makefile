CFLAGS = -Wall -Werror
LFLAGS = -lm
SOURCES := $(wildcard *.c)
#OBJS := prelab_main.o prelab4.o 
OBJS := $(SOURCES:.c=.o)
CC = gcc

%.o : %.c
	@echo "Compiling the c files..."
	@$(CC) $(CFLAGS) -c $(SOURCES)

a.out: $(OBJS)
	@echo "Linking..."
	@$(CC) $(LFLAGS) -o $@ $(OBJS)
	@echo "Done!"


clean:
	@echo "Cleaning..."
	@rm -f *.o a.out
	@echo "Done!"

