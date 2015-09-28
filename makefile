CC=gcc
CFLAG=-Wall
TARGET=one buf test

all: $(TARGET)

one:
	$(CC) $(CFLAG) one_by_one.c -o one

buf:
	$(CC) $(CFLAG) read_by_buffer.c -o buf

test:
	$(CC) $(CFLAG) create_test_data.c -o test

rm:
	rm $(TARGET)
