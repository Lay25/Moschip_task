CC = gcc
SRC = ex2.3.c
OBJ = ex2.3.o
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
	