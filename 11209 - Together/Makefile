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

$(PROG) :
	$(CC) $(CFLAGS) -o $(PROG) $(CDIR)/$(CFILES)
#	$(LINK.o) $(LDFLAGS) -o $@ $^

clean :
	rm -f $(PROG).exe $(PROG).d
#$(OBJFILES) $(DEPFILES)

-include $(DEPFILES)