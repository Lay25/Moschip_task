CC = gcc
SRC = ex1.21.c
OBJ = ex1.21.o
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


