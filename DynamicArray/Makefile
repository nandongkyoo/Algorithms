CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = dynamicArrayMain
OBJS = dynamicArrayMain.o dynamicArray.o

TEST_TARGET = test10
TEST_OBJS = test10.o dynamicArray.o

# 기본 타겟: 링크
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 컴파일 (dynamicArray.h가 바뀌면 둘 다 재빌드됨)
dynamicArrayMain.o: dynamicArrayMain.c dynamicArray.h
	$(CC) $(CFLAGS) -c dynamicArrayMain.c

dynamicArray.o: dynamicArray.c dynamicArray.h
	$(CC) $(CFLAGS) -c dynamicArray.c

# 테스트 컴파일
test10.o: test10.c dynamicArray.h
	$(CC) $(CFLAGS) -c test10.c

# 테스트 링크
$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

# 테스트 빌드 후 실행
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# 정리
clean:
	rm -f $(TARGET) $(OBJS) $(TEST_TARGET) $(TEST_OBJS)

# 실행
run: $(TARGET)
	./$(TARGET)

.PHONY: clean run test
