CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = maze
OBJS = main.o maze.o

# 기본 타겟: 링크
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 컴파일 (maze.h가 바뀌면 둘 다 재빌드됨)
main.o: main.c maze.h
	$(CC) $(CFLAGS) -c main.c

maze.o: maze.c maze.h
	$(CC) $(CFLAGS) -c maze.c

# 정리
clean:
	rm -f $(TARGET) $(OBJS)

# 실행
run: $(TARGET)
	./$(TARGET)

.PHONY: clean run