#include <stdio.h>

int main() {
    char* p = "abcdefgghdasf";
    char* p1 = "zzzzzz s xdf \0 qwedsdasd";
    char str0[] = "cvdfer\0qwedzxcvk";
    char str[] = "abcde";
    char str1[] = "가나다라";
    
    printf("%llu\n", sizeof(p)); // 8
    printf("%s\n", p);           // abcdefgghdasf
    printf("%s\n", p1);          // zzzzzz s xdf
    printf("%s\n", str0);        // cvdfer
    printf("%c\n", *p);          // a
    printf("%llu\n", sizeof(*p));   // 1
    printf("%llu\n", sizeof(str));  // 6
    printf("%llu\n", sizeof(str1)); // 9
    printf("%llu\n", sizeof(str0)); // 17
    return;
}
