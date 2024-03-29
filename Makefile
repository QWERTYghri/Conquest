# Compilation Makefile
#
# @QWERTYghri


include conf.mk

.PHONY: all clean

all: extra game.out

extra:
	@echo -e "\033[31;1;1mConquest Ncurses\033[0m" 
	@echo -e $(VERSION)
	@echo -e "Thanks for playing <3\n\n\n"

game.out: ./src/Public/*.h ./src/Private/*.c ./src/main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIB) -o $@ $^

clean:
	-rm -r *.o *.out
