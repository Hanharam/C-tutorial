#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
int main(){
    int i,c;
    int win=0,draw=0,lose=0;
    srand((int)time(NULL));
    do{
        printf("바위는 1, 가위는 2, 보는 3: ");
        scanf("%d",&i);
        c = rand()%3 + 1;
        switch(i){
            case 1:
                if(c==1){
                    printf("당신은 바위 선택, 컴퓨터는 바위 선택, 비겼습니다!\n");
                    draw++;
                }
                else if(c==2){
                    printf("당신은 바위 선택, 컴퓨터는 가위 선택, 이겼습니다!\n");
                    win++;
                }
                else{
                    printf("당신은 바위 선택, 컴퓨터는 보 선택, 졌습니다!\n");
                    lose++;
                }
                break;
            case 2:
                if(c==1){
                    printf("당신은 가위 선택, 컴퓨터는 바위 선택, 졌습니다!\n");
                    lose++;
                }
                else if(c==2){
                    printf("당신은 가위 선택, 컴퓨터는 가위 선택, 비겼습니다!\n");
                    draw++;
                }
                else{
                    printf("당신은 가위 선택, 컴퓨터는 보 선택, 이겼습니다!\n");
                    win++;
                }
                break;
            case 3:
                if(c==1){
                    printf("당신은 보 선택, 컴퓨터는 바위 선택, 이겼습니다!\n");
                    win++;
                }
                else if(c==2){
                    printf("당신은 보 선택, 컴퓨터는 가위 선택, 졌습니다!\n");
                    lose++;
                }
                else{
                    printf("당신은 보 선택, 컴퓨터는 보 선택, 비겼습니다!\n");
                    draw++;
                }
                break;
        }
    }while(lose == 0 && i<4 && i>0);
    printf("\n게임의 결과: %d승, %d무\n",win,draw);       
}
*/

//함수를 이용함, 가위바위보 승패여부를 최적화함

int GetUsrSel(void);
int GetComSel(void);
int WhoIsWin(int s1,int s2);

int main(){
    int usr,com,result;
    int win = 0, draw = 0;
    srand((int)time(NULL));

    while(1){
        usr = GetUsrSel();
        com = GetComSel();
        result = WhoIsWin(com,usr);

        if(result == 1){
            printf("이겼습니다!\n");
            win++;
        }
        else if(result == -1){
            printf("비겼습니다!\n");
            draw++;
        }
        else{
            printf("졌습니다!\n");
            break;
        }
    }
    printf("\n게임의 결과: %d승, %d무\n",win,draw);
}


int GetUsrSel(){
    int i;
    printf("바위는 1, 가위는 2, 보는 3: ");
    scanf("%d",&i);
    if(i==1) printf("당신은 바위 선택, ");
    else if(i==2) printf("당신은 가위 선택, ");
    else printf("당신은 보 선택, ");
    return i;
}

int GetComSel(){
    int i;
    i = rand()%3 +1;
    if(i==1) printf("컴퓨터는 바위 선택, ");
    else if(i==2) printf("컴퓨터는 가위 선택, ");
    else printf("컴퓨터는 보 선택, ");
    return i;
}

int WhoIsWin(int s1,int s2){
    if(s1 == s2) return 0;
    else if(s1 == (s2+1)%3) return 1;
    else return -1;
}