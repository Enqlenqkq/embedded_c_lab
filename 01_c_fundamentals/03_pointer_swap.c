/*
문제 3 — 포인터 매개변수로 두 변수 값 교환

요구 사항:

1. `swap` 함수는 정수 포인터 두 개를 인자로 받는다.
2. 함수 안에서 임시 변수 한 개를 이용해 호출자의 두 정수 값을 교환한다.
3. `main`에서 `x=10`, `y=20`으로 초기화하고 `swap`에 각 변수의 **주소**를 전달한다.
4. 호출 전·후 값을 출력한다.
5. 추가 미션: `add_ten(int *value)`을 작성해 호출자의 값을 10 증가시킨다.

성공 조건: 교환 전 `x=10, y=20`, 교환 후 `x=20, y=10`. 확장 미션은 10 증가 확인.

추가 탐구: C 함수는 인자를 어떤 방식으로 전달하는가? 포인터 `a`와 `*a`의 의미는? 함수에 변수 값만 전달하면 왜 원본을 바꾸기 어려운가?
*/

#include <stdio.h>

void swap(int *a, int *b)
{
    if (a == NULL || b == NULL)
        return;
    // TODO 1: 임시 변수 선언
    int tmp;
    // TODO 2: 역참조를 이용해 두 정수의 값 교환
    tmp = *b;
    *b = *a;
    *a = tmp;
}

// TODO 3 (추가 미션): add_ten 함수 구현
void add_ten(int *value)
{
    if (value == NULL)
        return;
    *value += 10;
}

int main(void)
{
    int x = 10;
    int y = 20;

    printf("before: x=%d, y=%d\n", x, y);

    // TODO 4: swap에 x와 y의 주소 전달
    swap(&x, &y);

    printf("after:  x=%d, y=%d\n", x, y);

    // TODO 5 (추가 미션): add_ten 호출 및 결과 출력
    add_ten(&x);
    printf("x = %d\n", x);

    return 0;
}

/*
C 함수는 인자를 어떤 방식으로 전달하는가? -> 값에 의한 전달. Call by Value
포인터 `a`와 `*a`의 의미는? -> 포인터 a는 메모리 주소이고, 역참조 연산자를 붙인 포인터 *a는 해당 메모리의 값을 뜻한다.
함수에 변수 값만 전달하면 왜 원본을 바꾸기 어려운가? -> C에서 함수에 변수값만 전달하는 행위는 원본 데이터 접근이 아닌 복사 후 사용하기 때문이다.
*/