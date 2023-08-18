//Lab 1: To implement DDA algorithm for drawing a line segment between two given end points A(x1, x2) and B(x2, y2).

#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

int main(){
	int gd=DETECT,gm;
	int x1,y1,x2,y2,steps,k;
	float xincr,yincr,x,y,dx,dy;
	printf("Enter x1,y1: ");
	scanf("%d%d",&x1,&y1);
	printf("Enter x2,y2: ");
	scanf("%d%d", &x2,&y2);
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	xincr=dx/steps;
	yincr=dy/steps;
	x=x1;
	y=y1;
	for(k=1;k<=steps;k++){
		putpixel(x,y,WHITE);
		x+=xincr;
		y+=yincr;
		delay(50);
	}
	getch();
	closegraph();
	return 0;
}
