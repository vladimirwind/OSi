MAIN	=	main
SUB	=	main2

all:	program

program: $(MAIN) $(SUB)
	gcc -o main obj/$(MAIN).o
	gcc -o sub obj/$(SUB).o

$(MAIN): obj
	gcc -c -o obj/$(MAIN).o src/$(MAIN).c

$(SUB): obj
	gcc -c -o obj/$(SUB).o src/$(SUB).c

obj:
	mkdir obj

clean:
	rm -rf obj/$(MAIN).o
	rm -rf obj/$(SUB).o
	rmdir obj
