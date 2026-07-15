CC = gcc
CFLAGS = -Wall -Wextra -g

TARGETS = arrayBaseStack listBaseStack

# 기본 타겟: 둘 다 빌드
all: $(TARGETS)

arrayBaseStack: arrayBaseStack.c
	$(CC) $(CFLAGS) -o arrayBaseStack arrayBaseStack.c

listBaseStack: listBaseStack.c
	$(CC) $(CFLAGS) -o listBaseStack listBaseStack.c

# 정리
clean:
	rm -f $(TARGETS)

.PHONY: all clean
