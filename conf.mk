#Config list for flags, bin dirs, and install dirs

CC		:= gcc
CFLAGS		:= -std=gnu99 -Wall -pedantic -pipe
#OFLAGS		:= -Os
OFLAGS		:= -g -O0

# I am way to fucking lazy to learn menus and forms
LIBS		:= -lncurses -lpanel -lpthread
