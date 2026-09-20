CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = shellforge

SRC = src/main.c src/token.c src/lexer.c src/builtin.c
OBJ = src/main.o src/token.o src/lexer.o src/builtin.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) -lreadline

src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/token.o: src/token.c
	$(CC) $(CFLAGS) -c src/token.c -o src/token.o

src/lexer.o: src/lexer.c
	$(CC) $(CFLAGS) -c src/lexer.c -o src/lexer.o

src/builtin.o: src/builtin.c
	$(CC) $(CFLAGS) -c src/builtin.c -o src/builtin.o

clean:
	rm -f $(OBJ) $(TARGET)
