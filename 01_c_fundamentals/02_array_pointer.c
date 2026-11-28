/*
문제 2 — 배열과 포인터로 동일 요소 접근
요구 사항:

1. `int samples[4] = {10, 20, 30, 40};`를 사용한다.
2. 첫 번째 원소를 가리키는 `int *p` 변수를 선언하고 초기화한다.
3. 반복문에서 `samples[i]`와 포인터 연산으로 읽은 값이 같은지 출력한다.
4. 포인터를 이용해 **두 번째 원소를 25로 수정**한다. 배열 인덱스 표기법으로 대입하지 않는다.
5. `sizeof(samples)`와 `sizeof(samples[0])`를 비교해 출력한다.

성공 조건: 두 접근 방식의 출력이 모두 `10, 20, 30, 40`과 일치하고, 수정 후 두 번째 요소가 `25`다.

추가 탐구: `p + 1`은 주소를 몇 바이트 이동하는가? `sizeof(samples)`와 `sizeof(p)`가 항상 같은가? 배열 이름과 포인터 변수는 같은 객체인가?
*/

#include <stdio.h>

int main(void)
{
    int samples[4] = {10, 20, 30, 40};

    // TODO 1: 첫 번째 요소를 가리키는 int 포인터 p 선언
    int *p = samples;

    for (size_t i = 0; i < 4; ++i)
    {
        // TODO 2: 인덱스 접근 값과 포인터 접근 값을 함께 출력
        printf("%d\t", samples[i]);
        printf("%d\n", *(p + i));
    }

    // TODO 3: 포인터를 이용해 samples[1] 값을 25로 변경
    *(p + 1) = 25;

    // TODO 4: 변경된 배열 원소와 배열 전체/원소 크기 출력
    printf("samples[1]: %d, Size of array: %zu, Size of elements: %zu\n", *(p + 1), sizeof(samples), sizeof(*(p + 1)));

    return 0;
}

/*
`p + 1`은 주소를 몇 바이트 이동하는가? -> 포인터가 가리키는 자료형의 크기 단위 -> int니까 4byte 이동
`sizeof(samples)`와 `sizeof(p)`가 항상 같은가? -> 다르다. sizeof(samples)는 배열 전체 크기이고, sizeof(p)는 포인터 변수 크기인 8byte이다.
배열 이름과 포인터 변수는 같은 객체인가? ->
다르다. 배열 이름이 가리키는 곳은 배열 시작 메모리로 고정되어 있지만,
포인터 변수는 다른 메모리 위치를 가리키도록 수정할 수 있다.
*/