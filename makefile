CC = gcc 
CFLAGS = --std=gnu99 -Wall -g

# Source and header files
SRCS = ll_main.c ll_utils.c
HDRS = ll_utils.h

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = ll_exe

# Default rule
all: clean $(EXEC)

# Compile and link directly from source files
$(EXEC): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

# Clean rule
clean:
	rm -f $(EXEC) $(OBJS)

#Valgrind
v:
	valgrind -v ./$(EXEC)

#valgrind with leakcheck
vv:
	valgrind --leak-check=full ./$(EXEC)

# Clean build + valgrind with leak check + summary
vvv: clean $(EXEC)
	valgrind --leak-check=full -s ./$(EXEC)
	
.PHONY: all clean