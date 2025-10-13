CC = gcc
SRC = ex2.4.c
OBJ = ex2.4.o
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
	
