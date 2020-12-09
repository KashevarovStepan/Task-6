#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <windows.h>

void square(int x, int y, int len)
{
    rectangle(x-len,y-len,x+len,y+len);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(x-1,y-1,WHITE);
    floodfill(x-1,y+1,WHITE);
    floodfill(x+1,y-1,WHITE);
    floodfill(x+1,y+1,WHITE);
}

void draw(int n,int x,int y,int len)
{
    if(n>0)
    {
        int newlen=len/2;
        square(x-len,y-len,newlen);
        square(x-len,y+len,newlen);
        square(x+len,y-len,newlen);
        square(x+len,y+len,newlen);
        n--;
        draw(n,x-len,y-len,newlen);
        draw(n,x-len,y+len,newlen);
        draw(n,x+len,y-len,newlen);
        draw(n,x+len,y+len,newlen);
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    int gd=DETECT;
    int gm,n;
    printf("¬ведите глубину рекурсии(натуральное число)\n");
    scanf("%d",&n);
    initgraph(&gd, &gm,"");

    setcolor(WHITE);
    int x=300,y=200,length=80;
    square(x,y,length);
    draw(n-1,x,y,length);

    readkey();
    closegraph();
    return 0;
}

