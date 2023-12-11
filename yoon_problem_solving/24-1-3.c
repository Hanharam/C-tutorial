#include <stdio.h>

int main(){
    FILE* fp = fopen("mystory.txt","rt");
    char a;
    if(fp==NULL){
        puts("파일오픈 실패");
        return -1;
    }

    while((a=fgetc(fp))!=EOF){
        fputc(a,stdout);
    }

    if(feof(fp)!=0);
    else puts("실패");

    fclose(fp);
    return (0);
}