CC = g++ -Wall
CFLAGS =
#LIBS = -lm

SRCS = main.cpp
HDRS = clist.h clist_node.h clist_iterator.h
EXEC = main

all : $(EXEC)

$(EXEC): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(EXEC)

clean :
	rm -f $(EXEC)
