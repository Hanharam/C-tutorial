#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand((int)time(NULL));
    printf("첫번째 주사위: %d\n두번째 주사위: %d\n",rand()%6+1,rand()%6+1);
    return 0;
}