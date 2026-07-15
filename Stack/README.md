# Stack

## 소개
기본 배열과 linkedList를 활용한 스택 구현

## 파일 구성
- `arrayBaseStack.c`: array를 활용한 스택 구현
- `listBaseStack.c`: linkedList를 활용한 스택 구현

## 동작 방식
- array 방식: 최상위 인덱스를 top이라는 변수로 관리하여 push, pop, top을 구현.(단, 배열 사이즈는 고정)
- linkedList 방식: 마지막으로 삽입된 Node를 Node 포인터 타입 변수 top으로 가리키도록 하여 push, pop, top을 구현.(노드는 data값과 다음 노드를 가리키는 포인터 변수를 보유)

## 빌드 및 실행

```bash
make
./arrayBaseStack
./listBaseStack
```

## array vs linkedList
1. 최대 크기 고정 여부: array 방식은 최대 크기를 미리 정해야하는 반면 linkedList 방식은 크기를 동적으로 할당한다.
2. 속도: array 방식은 연속으로 메모리가 존재하기 때문에 빠르나 linkedList 방식은 malloc 오버헤드 때문에 상대적으로 느리다.
3. 메모리: linkedList 방식은 array 방식과 다르게 필요한 만큼만 메모리를 사용 가능하다.
4. 메모리 관리: array 방식은 메모리를 관리할 필요가 없지만 linkedList 방식은 free를 해주지 않으면 메모리 누수가 발생한다.
