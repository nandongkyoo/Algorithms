CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = linkedListMain
OBJS = linkedListMain.o linkedList.o

# 기본 타겟: 링크
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 컴파일 (linkedList.h가 바뀌면 둘 다 재빌드됨)
linkedListMain.o: linkedListMain.c linkedList.h
	$(CC) $(CFLAGS) -c linkedListMain.c

linkedList.o: linkedList.c linkedList.h
	$(CC) $(CFLAGS) -c linkedList.c

# 정리
clean:
	rm -f $(TARGET) $(OBJS)

# 실행
run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
