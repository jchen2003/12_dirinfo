all: dirinfo.o
	gcc -o dirinfo dirinfo.o

dirinfo.o: dirinfo.c 
	gcc -c dirinfo.c
	
run: 
	./dirinfo
clean:
	rm *.o