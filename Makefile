binfirst := fifo
binsecond := fifocheck
binthird := sys5
obj1 := fifo.o
obj2 := fifocheck.o
obj3 := sys5.o

all: $(binfirst) $(binsecond) $(binthird)

$(binfirst): $(obj1) 
	gcc $< -o $(binfirst) 

$(binsecond): $(obj2)
	gcc $< -o $(binsecond) 

$(binthird): $(obj3)
	gcc $< -o $(binthird) 

%.o: %.c
	gcc -c $< -o $@