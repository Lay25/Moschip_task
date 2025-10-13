CC = gcc
SRC = ex2.10.c
OBJ = ex2.10.o
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
	
