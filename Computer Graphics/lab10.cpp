//lab 10 - Write a program to draw a Polygon

#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    /* Declaring a variable */
    int gdriver, gmode;
    /* Polygon array to define points on the polygon shape */
    int poly[10];
    
    /* Initialize the variables */
    gdriver = DETECT;
    /* Initialize the graph and set the path to BGI files */
    initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
    
    /* Polygon Points in Pairs */
    poly[0] = 20;   /* 1st vertex */
    poly[1] = 100;
    poly[2] = 120;  /* 2nd vertex */
    poly[3] = 140;
    poly[4] = 240;  /* 3rd vertex */
    poly[5] = 260;
    poly[6] = 120;  /* 4th vertex */
    poly[7] = 320;
    poly[8] = poly[0]; /* The polygon does not close automatically, so we close it */
    poly[9] = poly[1];
    
    /* Draw the Polygon */
    drawpoly(5, poly);
    
    getch();
    /* Close the graph */
    closegraph();
    
    return 0;
}

