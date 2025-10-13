CC = gcc
SRC = ex2.7.c
OBJ = ex2.7.o
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
	
