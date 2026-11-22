/*
문제 1 — 자료형, 크기, 변수 주소

요구사항:

1. `char`, `int`, `double` 변수를 각각 선언하고 원하는 초기값을 저장한다.
2. 각 변수의 값과 `sizeof`로 확인한 크기를 `printf`로 출력한다.
3. `int` 변수의 주소를 `%p` 형식으로 출력한다. 포인터 인자는 `(void *)`로 변환한다.
4. 자료형 크기는 환경마다 다를 수 있으므로, 숫자를 고정하지 말고 실제 측정값을 사용한다.

성공 조건: 변수 값 3개, 자료형 크기 3개, 주소 1개가 정상 출력된다.

추가 탐구: `value`와 `&value`의 차이는? `sizeof(char)`는 왜 항상 1인가? 주소가 실행마다 같아야 하는가?
*/

/*
===================================================================
• 기본 정수형 (길이 수식자: hh=char, h=short, (없음)=int, l=long, ll=long long)
    • %d, %i   : 부호 있는 10진수 int
    • %u       : 부호 없는 10진수 unsigned int
    • %x, %X   : 16진수 (소문자 / 대문자)
    • %o       : 8진수
    • %ld, %lu : long / unsigned long
    • %lld, %llu: long long / unsigned long long

• 시스템 및 크기/포인터 관련 (★C99 핵심)
    • %zu      : size_t (sizeof의 반환형, 부호 없는 크기)
    • %zd      : ssize_t (부호 있는 크기)
    • %td      : ptrdiff_t (두 포인터 간의 주소 차이/거리)
    • %p       : 메모리 주소값 (void *로 캐스팅 권장)

• 실수형 (Floating-Point)
    • %f, %lf  : 10진수 실수 (float, double)
    • %e, %E   : 지수 표기법
    • %g, %G   : %f와 %e 중 더 간결한 형식 자동 선택 (끝자리 불필요한 0 제거)

• 문자 및 기타
    • %c       : 단일 문자 (char)
    • %s       : 문자열 (char *, null-terminated)
    • %%       : '%' 문자 자체 출력
===================================================================
*/

#include <stdio.h>

int main(void)
{
    // TODO 1: char, int, double 변수 3개 선언 및 초기화
    char c = 'A';
    int i = 1;
    double d = 3.14;

    // TODO 2: 각 변수의 값과 sizeof 결과 출력
    // 힌트: sizeof 결과에 대응하는 형식 지정자를 찾아보자.
    printf("Size of char %c: %zu\n", c, sizeof(c));
    printf("Size of int %d: %zu\n", i, sizeof(i));
    printf("Size of double %.2f: %zu\n", d, sizeof(d));

    // TODO 3: int 변수의 주소 출력
    // 힌트: 주소를 구하는 연산자는?
    int *ptr = &i;
    printf("Address of int i: %p\n", (void *)ptr);

    return 0;
}