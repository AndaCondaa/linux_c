#include <stdio.h>


int main(){
    char a = -1;

    //char Val = 0;
    char printVal = 0;

    printVal = a & (1<<7);
    printVal = printVal >> 7;
    printf("%d ", printVal);

    printVal = a & (1<<6);
    printVal = printVal >> 6;
    printf("%d ", printVal);

    printVal = a & (1<<5);
    printVal = printVal >> 5;
    printf("%d ", printVal);

    printVal = a & (1<<4);
    printVal = printVal >> 4;
    printf("%d ", printVal);

    printVal = a & (1<<3);
    printVal = printVal >> 3;
    printf("%d ", printVal);

    printVal = a & (1<<2);
    printVal = printVal >> 2;
    printf("%d ", printVal);

    printVal = a & (1<<1);
    printVal = printVal >> 1;
    printf("%d ", printVal);

    printVal = a & (1<<0);
    printVal = printVal >> 0;
    printf("%d ", printVal);
    
    printf("\n");

    char test1 = 0xC6;
    char test2;
    test2 = test1 << 2;


    printf("%#x\n", test1);
    printf("%#x\n", test1 << 1);
    printf("%#x\n", test1 >> 2 );
    printf("size: %d\n", sizeof(test1));
    printf("%#x\n", test2);

    return 0;
}
