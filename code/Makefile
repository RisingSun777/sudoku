PROGRAM=sudoku

INCDIRS=include/
SRCDIR=source/
BINDIR=../out/
OBJDIR=../obj/

INC=$(addprefix -I, $(INCDIRS))

CC=gcc
CFLAGS=-g -std=gnu99 -pedantic -Wall -Wextra $(INC)
LDLIBS=

SOURCES=$(wildcard $(SRCDIR)*.c)
OBJFILES=$(addprefix $(OBJDIR), $(patsubst %.c, %.o, $(notdir $(SOURCES))))

$(PROGRAM): $(OBJFILES)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $(BINDIR)$(PROGRAM) $(OBJFILES) $(LDLIBS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $?

clean:
	rm -rf ../out/ ../obj/
