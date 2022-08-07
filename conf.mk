#Config list for gcc flags, bin dirs, and install dirs

CC		:= gcc
CFLAGS		:= -std=gnu90 -Wall -pedantic -pipe
#OFLAGS		:= -Os
OFLAGS		:= -g -O0

LIBS		:= -lncurses -lpanel
OUTDIR		:= ./bin
