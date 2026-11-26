/*실습 3: 구조체에 대한 동적 할당*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book{
    int number;
    char title[10];
};

int main(void){
    int i;
    struct Book **bookshelf;

    //alloc
    bookshelf = (struct Book**)malloc(3*sizeof(struct Book*));
    for (i=0;i<3;i++)
        bookshelf[i] = (struct Book*)malloc(10*sizeof(struct Book));
    
    //이중포인터 형태의 동적 메모리 접근 및 반납
    bookshelf[1][3].number = 5;
    strcpy(bookshelf[1][3].title, "C++ programming");

    (bookshelf[2]+4)->number=3;
    strcpy((bookshelf[2]+4)->title, "Communications Theory");

    printf("book (1,3): %i권, 책 이름: %s\n",(bookshelf[1]+3)->number,(bookshelf[1]+3)->title);
    printf("book (2,4): %i권, 책 이름: %s\n",bookshelf[2][4].number,bookshelf[2][4].title);

    //2차원 구조체 메모리 반남
    for(i=0;i<3;i++){
        free(bookshelf[i]);  //malloc과 역순으로 똑같이 해지
    }
    free(bookshelf); //3층짜리의 책단 자체도 해지

    return 1;
    
}