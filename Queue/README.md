# Circular Queue

## 파일 구성
- `circularQueue.h`: 원형 큐 구현에 필요한 구조체 및 함수 정의
- `circularQueue.c`: 큐 초기화, enqueue, dequeue 등 구현
- `circularMain.c`: 메인함수

## 동작 방식
- front: 다음에 dequeue할 데이터의 인덱스, back: 다음에 enqueue될 데이터가 들어갈 인덱스
- enqueue 시 back 위치에 값을 넣고 back을 (back + 1) % MAX_SIZE로 이동시켜, 배열의 끝에 도달하면 인덱스 0으로 순환한다.
- dequeue 시 front 위치의 값을 꺼내고 (front + 1) % MAX_SIZE로 이동시킨다.
- front == back만으로는 큐가 가득 찬 상태인지 확인할 수 없기 때문에 count 변수로 원소의 개수를 저장한다.

## 빌드 및 실행
```bash
make
./circularMain
```
## 인덱스를 순환시키는 이유
일반 배열 큐처럼 back 인덱스를 계속 증가시키기만 하면, dequeue로 배열 앞쪽에 빈 공간이 생겨도 back이 배열 끝에 도달하는 순간 더 이상 enqueue를 할 수 없다. 원형 큐는 back과 front를 ```% MAX_SIZE```로 순환시켜 이 앞쪽 빈 공간을 사용함으로써 이 문제를 해결하였다.