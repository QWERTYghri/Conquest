# Compilation config file
#
# Specify different compile flags and values
#
# @QWERTYghri

CC	 := gcc
CFLAGS	 := -std=gnu99 -pedantic -Wall -Wextra -pipe
CPPFLAGS := -D_POSIX_C_SOURCE=200809L
LIB	 := -lncurses -lpanels

#Optimization flag
OFLAG	 := -g -O0
#OFLAG	 := -Os

VERSION  := "Version 1.0R: Please help I'm rewriting all my shit code"
