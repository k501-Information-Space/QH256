CC ?= cc
CFLAGS ?= -std=c11 -O2 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wstrict-prototypes
TARGET = qh256_validation
OBJ = qh256.o test_qh256_validation.o
.PHONY: all clean test asan
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)
qh256.o: qh256.c qh256.h
	$(CC) $(CFLAGS) -c qh256.c -o $@
test_qh256_validation.o: test_qh256_validation.c qh256.h
	$(CC) $(CFLAGS) -c test_qh256_validation.c -o $@
test: $(TARGET)
	./$(TARGET)
asan:
	$(CC) -std=c11 -O1 -g -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wstrict-prototypes -fsanitize=address,undefined -fno-omit-frame-pointer -o qh256_validation_asan qh256.c test_qh256_validation.c
	./qh256_validation_asan
	rm -f qh256_validation_asan
clean:
	rm -f $(TARGET) qh256_validation_asan $(OBJ)
