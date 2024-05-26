CC = gcc

SRCS = pet_manager.c 
OBJS = $(SRCS:.c=.o)

TARGET = pet_manager

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@
