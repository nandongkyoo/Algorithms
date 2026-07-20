CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = dynamicArrayMain
OBJS = dynamicArrayMain.o dynamicArray.o

# 기본 타겟: 링크
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 컴파일 (dynamicArray.h가 바뀌면 둘 다 재빌드됨)
dynamicArrayMain.o: dynamicArrayMain.c dynamicArray.h
	$(CC) $(CFLAGS) -c dynamicArrayMain.c

dynamicArray.o: dynamicArray.c dynamicArray.h
	$(CC) $(CFLAGS) -c dynamicArray.c

# 정리
clean:
	rm -f $(TARGET) $(OBJS)

# 실행
run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
