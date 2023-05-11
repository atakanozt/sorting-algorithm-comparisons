CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
LDFLAGS =
SRCDIR = .
OBJDIR = obj
BINDIR = .

# List of source files (excluding compare.c and utility.c)
SRCS = $(filter-out $(SRCDIR)/compare.c $(SRCDIR)/utility.c, $(wildcard $(SRCDIR)/*.c))
# List of object files (excluding compare.o and utility.o)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
# List of header files
HEADERS = $(wildcard $(SRCDIR)/*.h)
# Name of the executable
TARGET = $(BINDIR)/sort

all: $(TARGET)

$(TARGET): $(OBJS) $(SRCDIR)/compare.o $(SRCDIR)/utility.o
	@mkdir -p $(BINDIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean
