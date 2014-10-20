#########################
# customise these
CDIR := src
CFILES := 11209\ -\ Together.cpp
PROG := together
CFLAGS := -Wall -Wextra -g
LDFLAGS :=
########################

# -MMD generates dependencies while compiling
CFLAGS += -MMD -std=c++11
CC := g++

#OBJFILES := $(CDIR)/$(CFILES:.c=.o)
#DEPFILES := $(CFILES:.c=.d)

$(PROG) : $(CDIR)/$(CFILES)
	$(CC) $(CFLAGS) -o $(PROG) $(CDIR)/$(CFILES) $(LDFLAGS)
#	$(LINK.o) $(LDFLAGS) -o $@ $^

clean :
	rm -f $(PROG).exe $(PROG).d $(PROG) $(PROG)-online $(PROG)-online.d

online : $(PROG)
	$(CC) $(CFLAGS) -DONLINE_JUDGE -o $(PROG)-online $(CDIR)/$(CFILES)
#$(OBJFILES) $(DEPFILES)

-include $(DEPFILES)
