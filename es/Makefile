CC = gcc
TARGET = main.elf
SRC = main.c funtion.c
INCLUDE_PATH = ./include

CFLAGS = -I $(INCLUDE_PATH)

OBJ = $(SRC:.c=.o)

# First rule this will trigger $(TARGET) rule
all: $(TARGET) cmp_size

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compile .c files into .o object files

# main.o: main.c
# 	gcc -c -o main.o main.c
#
# function.o: function.c
# 	gcc -c -o function.o function.c

# Using wildcards it is possible to rewrite the instructions above as follow:
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Useful because in real projects is often to compile milions of .c files and so is 
# needed to link milions of .o files

cmp_size:
	size $(TARGET: .elf=.o)
	size $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

