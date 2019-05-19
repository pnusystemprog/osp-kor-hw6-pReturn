OBJS = phoneBookMain.o register.o print.o search.o delete.o

HEADER = phone.h

all : main
%.o : %.c
	gcc -c $< 
main : $(OBJS) $(HEADER)
	gcc -o main $^
clean :
	rm -f main $(OBJS)  
