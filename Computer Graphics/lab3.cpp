// Lab 3: To implement midpoint circle generation algorithm or Bresenham's circle algorithm for drawing a circle of given center (x_mid, y_mid) and radius r.

#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int main()
{
    int x,y,x_mid,y_mid,radius,dp;
    int gm,gd=DETECT;
    printf(" MID POINT Circle Drawing Algorithm\n\n");
    printf("\n Enter the coordinates of center: ");
    scanf("%d%d",&x_mid,&y_mid);
    printf("\n Enter the radius: ");
    scanf("%d",&radius);
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    x=0;
    y=radius;
    dp=1-radius;
    while(x<=y){
    putpixel(x_mid+x,y_mid+y,YELLOW);
    putpixel(x_mid+y,y_mid+x,WHITE);
    putpixel(x_mid-y,y_mid+x,WHITE);
    putpixel(x_mid-x,y_mid+y,YELLOW);
    putpixel(x_mid-x,y_mid-y,YELLOW);
    putpixel(x_mid-y,y_mid-x,YELLOW);
    putpixel(x_mid+y,y_mid-x,YELLOW);
    putpixel(x_mid+x,y_mid-y,YELLOW);
    if(dp<0) {
        dp+=(2*x)+1;
    }
    else{
        dp+=(2*x)-(2*y)+1;
        y=y-1;
    }
    x=x+1;
    }
    getch();
    return 0;
}

