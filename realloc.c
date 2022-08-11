#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *a;
    int b=sizeof(int);
    a=(int*)malloc(sizeof(int));
    *a=5;
    a=(int*)realloc(a,sizeof(int));
    *(a+b) = 10;
        a=(int*)realloc(a,sizeof(int));
    *(a+2*b) = 20;
    printf("%d %d %d",*a,*(a+b),*(a+b+b));
}