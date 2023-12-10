#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct point{
    int xpos;
    int ypos;
}Point;

void SwapPoint(Point* pos1,Point* pos2){
    Point spos;
    spos = *pos1;
    *pos1 = *pos2;
    *pos2 = spos;
}

int main(){
    Point pos1={2,4};
    Point pos2={5,7};
    SwapPoint(&pos1,&pos2);
    printf("pos1 [%d, %d]\npos2 [%d, %d]",pos1.xpos,pos1.ypos,pos2.xpos,pos2.ypos);
    return(0);
}
