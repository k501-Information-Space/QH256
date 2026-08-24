CC ?= cc
CFLAGS ?= -std=c11 -O2 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wstrict-prototypes
LDFLAGS ?=

TARGET = qh256_validation
OBJECTS = qh256.o test_qh256_validation.o

.PHONY: all clean test run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJECTS)

qh256.o: qh256.c qh256.h
	$(CC) $(CFLAGS) -c qh256.c -o $@

test_qh256_validation.o: test_qh256_validation.c qh256.h
	$(CC) $(CFLAGS) -c test_qh256_validation.c -o $@

test: $(TARGET)
	./$(TARGET)

run: test

clean:
	rm -f $(TARGET) $(OBJECTS)
