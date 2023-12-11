#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct point{
    int xpos;
    int ypos;
}Point;

typedef struct rectangle{
    Point a;
    Point b;
}Rectangle;


void ShowRange(Rectangle rec){
    printf("Area: %d\n",(rec.b.xpos-rec.a.xpos)*(rec.b.ypos-rec.a.ypos));
}

void ShowPos(Rectangle rec){
    printf("[%d,%d]\t[%d,%d]\n[%d,%d]\t[%d,%d]\n\n",rec.a.xpos,rec.b.ypos,rec.b.xpos,rec.b.ypos,rec.a.xpos,rec.a.ypos,rec.b.xpos,rec.a.ypos);
}

int main(){
    Rectangle rec1 ={{1,1},{4,4}};
    Rectangle rec2 = {{0,0},{7,5}};
    ShowRange(rec1);
    ShowPos(rec1);
    ShowRange(rec2);
    ShowPos(rec2);
    return(0);
}
