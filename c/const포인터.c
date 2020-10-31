#include <stdio.h>

#define print(p) printf("%d\n", *p)
#define set(p, i) *p = i

int main() {
    int val = 3;
    int const* p1 = &val;   // 포인터가 가리키는 값에 변경불가 접근
    const int* p2 = &val;   // 포인터가 가리키는 값에 변경불가 접근
    int* const p3 = &val;   // 포인터 자체에 상수

    print(p1);
    print(p2);
    print(p3);

    // set(p1, 5);  // 포인터로 수정 불가
    // set(p2, 5);  // 포인터로 수정 불가
    set(p3, 7);     // 포인터로 수정 가능

    print(p1);
    print(p2);
    print(p3);

    int a = 10;
    p1 = &a;
    p2 = &a;
    // p3 = &a; // 포인터에 수정된 값 수정 불가

    print(p1);
    print(p3);

    return 0;
}