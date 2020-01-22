#include<stdio.h>
#include<stdlib.h>
void main()
{
    static int m=0;
    malloc(32);
    printf("Ran %d times",m);
    m++;
    main();
}