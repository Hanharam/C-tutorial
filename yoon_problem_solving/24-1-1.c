#include <stdio.h>

int main(){
    FILE* fp = fopen("mystory.txt","wt");
    char str[30];

    if(fp==NULL){
        puts("파일열기 실패");
        return -1;
    }

    printf("이름 입력: ");
    fgets(str,sizeof(str),stdin);
    fputs("#이름: ",fp);
    fputs(str,fp);

    printf("주민번호 입력: ");
    fgets(str,sizeof(str),stdin);
    fputs("#주민번호: ",fp);
    fputs(str,fp);

    printf("전화번호 입력: ");
    fgets(str,sizeof(str),stdin);
    fputs("#전화번호: ",fp);
    fputs(str,fp);

    fclose(fp);
    return(0);
}