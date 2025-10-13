#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 1;
    float num2 = 2;
    char letter = 'a';

    int * pon_int;
    pon_int = &num1;

    float * pon_real;
    pon_real = &num2;

    char * pon_char;
    pon_char = &letter;

    printf("%d", num1);
    printf("\n");
    printf("%f", num2);
    printf("\n");
    printf("%c", letter);
    printf("\n");
    printf("\n");
    printf("\n");


    *pon_int = 10;
    *pon_real = 20;
    *pon_char = 'b';

    printf("%d", num1);
    printf("\n");
    printf("%f", num2);
    printf("\n");
    printf("%c", letter);
    printf("\n");


    return 0;
}
