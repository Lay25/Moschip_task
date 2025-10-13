CC = gcc
SRC = ex2.8.c
OBJ = ex2.8.o
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
	
