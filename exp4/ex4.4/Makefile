CC = gcc
SRC = ex4.4.c
OBJ = ex4.4.o
OUT = myProgram
all: $(OUT)

$(OUT):$(OBJ)
	@echo "building the file"
	$(CC) -o $@ $^
%.o: %.c
	@echo "compiling the file"
	$(CC) -c -o $@ $^

clean:
	rm -f $(OBJ) $(OUT)


