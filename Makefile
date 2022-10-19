CC=gcc
CFLAGS=-I$(IDIR) -Wall
LDFLAGS=-I$(IDIR)

# Source, object, and binary file dirs
IDIR=inc
SDIR=src
ODIR=obj
BDIR=bin

# Required header files
DEPS=parkerwords.h
# Object files that need source files
OBJ=parkerwords.o parkerwords_funcs.o

ifeq ($(optimize),yes)
CFLAGS+=-static -O3
endif

ifeq ($(debug),yes)
CFLAGS+=-DDEBUG
endif

$(BDIR)/parkerwords: $(patsubst %,$(ODIR)/%,$(OBJ))
	mkdir -p $(@D)
	$(CC) -o $@ $^ $(LDFLAGS)

$(ODIR)/%.o: $(SDIR)/%.c $(patsubst %,$(IDIR)/%,$(DEPS))
	mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm -fr $(ODIR)
	rm -fr $(BDIR)
