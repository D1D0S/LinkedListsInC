#
CFLAGS=-Wall -g -I./Include
# Link
#

bin/test_list:obj/list.o obj/test_list.o |bin/gcc -o bin/test_list obj/list.o obj/test_list.o 
# To be completed

#
# Objets of TP Lists
#

obj/list.o:src/list.c include/list.h |obj/gcc $(CFLAGS) -o -c src/list.c
# To be completed
obj/test_list.o:src/test_list.c include/list.h |obj/gcc $(CFLAGS) -o obj/test_list.o -c src/test_list.c 
# To be completed
obj: mkdir -p obj
bin/:mkdir -p bin

#
# Listing creation in pdf
#

listing:a2ps -o listing.ps include/list.h src/list.c src/test_list.c ps2pdf listing.ps rm listing.ps
# To be completed

#
# Remove files
#

clean : rm -f obj/*.o bin/test_list
# To be completed

#
# Test the functionality 
#

test :bin/test_list ./bin/test_list		.$(EXEC)
# To be completed
