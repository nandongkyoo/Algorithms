CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = circularMain
OBJS = circularMain.o circularQueue.o

# 기본 타겟: 링크
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 컴파일 (circularQueue.h가 바뀌면 둘 다 재빌드됨)
circularMain.o: circularMain.c circularQueue.h
	$(CC) $(CFLAGS) -c circularMain.c

circularQueue.o: circularQueue.c circularQueue.h
	$(CC) $(CFLAGS) -c circularQueue.c

# 정리
clean:
	rm -f $(TARGET) $(OBJS)

# 실행
run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
