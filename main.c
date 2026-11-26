/*실습 2: 구조체에 대한 동적 할당*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book{
    int number;
    char title[20];
};

int main(void){
    struct Book *p;

    p = (struct Book *)malloc(2*sizeof(struct Book)); //BOOK 구조체 2개 동적 할당

    if (p == NULL)
    {
        printf("memory allocation error!\n");
        return -1;
    }

    p->number = 1;
    strcpy(p->title, "C Programming");

    (p+1)->number = 2;
    strcpy((p+1)->title, "Electronics");

    printf("%i : %s\n", p->number,p->title);
    printf("%i : %s\n",(p+1)->number,(p+1)->title);
    free(p);

    return 0;
}