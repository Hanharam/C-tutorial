#include <stdio.h>

void turn90(int(*p1)[4],int(*p2)[4]){
    int i,j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++){
            p1[j][3-i] = p2[i][j];
        }

        for (j = 0; j < 4; j++){
            p1[j][3-i] = p2[i][j];
        }

        for (j = 0; j < 4; j++){
            p1[j][3-i] = p2[i][j];
        }

        for (j = 0; j < 4; j++){
            p1[j][3-i] = p2[i][j];
        }
    }
    
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            p2[i][j] = p1[i][j];
        }
    }
}

void print_pr(int (*p1)[4]){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("|%d|",p1[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}


int main(){
    int pr1[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int pr2[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    print_pr(pr1);

    turn90(pr1,pr2);
    print_pr(pr1);


    turn90(pr1,pr2);
    print_pr(pr1);


    turn90(pr1,pr2);
    print_pr(pr1);



    return(0);
}