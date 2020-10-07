#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* my_strrev(char* p_str) {
    char* start = p_str;    // 시작 주소 저장
    char* left = p_str;
    char ch;

    /* 1. char pointer p_str이 가리키는 char가 '\0'==(0==false==NULL)이 아니면 (*p_str != '\0')
          p_str은 다음 char를 가리킴 (p_str++)
       2. char pointer p_str이 가리키는 char가 NULL(=='\0')이면
          p_str은 다음 char를 가리킴(NULL다음 문자), 그리고 탈출 */
    while (*p_str++);

    // p_str이 NULL 왼쪽 char(문자열의 마지막 글자)를 가리키게 함
    p_str -= 2;

    // 왼쪽과 오른쪽이 서로 만나지 않았다면, 서로 swap
    while (left < p_str) {
        ch = *left;         // 임시 char 저장
        *left++ = *p_str;   // left가 가리키는 곳에, p_str이 가리키는 값을 쓰고, left이동
        *p_str-- = ch;      // p_str이 가리키는 곳에, ch를 쓰고, p_str이동
    }
    // 문자열의 시작 주소 반환
    return start;
}

char* my_strupr(char* p_str) {
    char diff = 'A' - 'a';
    // cp가 가리키는 char가 NULL==(0==false)이 아니면 계속한다
    for (char* cp = p_str; *cp; ++cp)
        if ('a' <= *cp && *cp <= 'z')
            *cp += diff;   // 소문자를 대문자로 변환(code 차이만큼 더해줌)
    // 문자열의 시작 주소 반환
    return p_str;
}

char* my_strLtrim(char* p_str) {
    // p_str이 가리키는 char가 NULL이 아니면
    while (*p_str) {
        // isspace -> ['', '\n', '\t', '\v', '\f', '\r']가 아니면 0(false) 반환
        if (!isspace(*p_str)) {   // 공백문자가 아니면(return값이 0이아니면(==true))
            return p_str;   // 공백문자가 아닌 char의 주소(공백제거한 문자열의 시작 주소)를 반환
        }
        p_str++;
    }
    // 문자열을 끝까지 검사했는데 다 공백 문자인 경우
    // 빈 문자열을 반환
    return (char*)"";
}

int main() {
    /* 문자와 문자열 개념 */
    char ch = 'a';      // a char
    // char* p_ch = 'b';  // char pointer, ''불가능, ""만 가능
    char* p_ch = &ch;   // char pointer, char의 주소 저장

    // str, p_str은 문자열의 시작 주소(첫번째 char 주소)를 나타냄

    // !! 변경할 수 있는 string (char의 배열)
    // 지역변수이므로, 함수가 사라지면 str은 사라진다
    // TMI : (하지만, "abcde"는 DATA영역에 남아있다)
    // (DATA영역의 상수"abcde"를 이용하여 새로운 char 배열(STACK영역에)을 만든다)
    char str[] = "abcde";
    str[3] = 'k';   // 가능

    // !! 변경할 수 없는 string (상수 형태의 문자열)
    // static, 정적 변수느낌으로, Data영역에 저장되고
    // 프로그램이 시작할때부터 종료될때까지 존재한다
    // (p_str은 DATA영역의 주소를 가리킴)
    char* p_str = "xyzab";
    // p_str[3] = 'k'; // 불가능


    /* strrev, 문자열 뒤집기 */
    {
        char str1[100] = "abcde12345";  // 짝수
        char str2[100] = "abcde1234";   // 홀수
        char* str3 = "xyzab";   // 변경할 수 없는 문자열

        // 변경할 수 있는 string의 시작 주소 전달
        printf("%s\n", my_strrev(str1));
        printf("%s\n", my_strrev(str2));
        //printf("%s\n", my_strrev(str3));  // 오류 발생
    }

    /* strupr 문자열 대문자로 변환 */
    {
        char str1[100] = "beautiful girl";
        char str2[100] = "BeAuTIful GiRl";
        printf("%s\n", my_strupr(str1));
        printf("%s\n", my_strupr(str2));
    }

    /* strltrim 문자열 왼쪽 공백 제거 함수 */
    {
        char str1[100] = "\n\t     abc";
        printf("%s\n", my_strLtrim(str1));
    }
    return 0;
}
