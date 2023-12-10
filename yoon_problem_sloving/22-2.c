#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee{
    char name[20];
    char id[15];
    int pay;
}Employee;

int main(){
    Employee arr[3];
    int i;

    for(i=0;i<3;i++){
        printf("\n%d번째 사람\n",i+1);
        printf("name: "); scanf("%s",arr[i].name);
        printf("id: "); scanf("%s",arr[i].id);
        printf("pay: "); scanf("%d",&arr[i].pay);
    }

    for(i=0;i<3;i++){
        printf("\nname: %s\n",arr[i].name);
        printf("id: %s\n",arr[i].id);
        printf("pay: %d\n", arr[i].pay);
    }
    return(0);
}

