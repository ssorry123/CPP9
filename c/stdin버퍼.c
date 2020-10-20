#include <stdio.h>

int main() {
    struct card {
        char name[20];
        int age;
        char code;
        double key;
    };

    struct card info;

    scanf_s("%s", info.name, 20);
    printf("check1 %s\n", info.name);

    scanf_s("%d", &info.age);
    setbuf(stdin, NULL);
    printf("check2 %d\n", info.age);

    // 문자 c를 제대로 입력받지 못하는 문제가 발생했다
    scanf_s("%c", &info.code, 1);
    printf("check3 %c\n", info.code);

    scanf_s("%lf", &info.key);
    printf("check4 %lf\n", info.key);

    /*
    버퍼를 비워줌으로써 해결하였습니다.

    scanf는 키보드에서 입력받은 값을
    stdin이라는 버퍼에 저장합니다(표준입력)
    그리고 버퍼에 있는 내용을
    %d나 %c같은 것을 보고 변수에 저장하게 됩니다.

    나이를 입력받을때, 20을 쓰고 엔터를 치면
    버퍼에는 (int)20과 (char)'\n'이 저장되게 됩니다.
    '\n'은 줄바꿈 문자입니다.

    (int)20을 나이에 저장하고 나면
    stdin버퍼에는 (char)'\n' 문자가 남아있게 되고

    그 상태에서 scanf(%c)를 하게되면
    남아있는 줄바꿈문자가 char이므로 부서 코드에는 줄바꿈문자가 들어와버리게 됩니당
    scanf(%d)를 하게 된다면, 줄바꿈문자는 int가 아니므로 무시하고 버퍼에서 int를 만나면 넣겠지만,,
    scanf(%c)를 하게 되어서 무시하지 않고 줄바꿈 문자가 들어와버립니당..

    그래서 char를 입력받기 전에, stdin버퍼에 있는 내용을 모두 비워주었습니다
    setbuf(stdin, NULL);
    */

    return 0;
}