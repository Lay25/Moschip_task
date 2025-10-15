CC = gcc
SRC = ex4.2.c
OBJ = ex4.2.o
OUT = myProgram
all: $(OUT)

$(OUT):$(OBJ)
	@echo "building the file"
	$(CC) -o $@ $^ -lm
%.o: %.c
	@echo "compiling the file"
	$(CC) -c -o $@ $^

clean:
	rm -f $(OBJ) $(OUT)


