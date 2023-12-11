#include <stdio.h>

int main(){
    FILE* fp = fopen("mystory.txt","at");
    char str[30];
    
    if(fp==NULL){
        puts("파일오픈 실패");
        return -1;
    }

    fputs("#즐겨먹는 음식: 짬뽕, 탕수육\n",fp);
    fputs("#취미: 축구",fp);

    fclose(fp);
    return(0);
}