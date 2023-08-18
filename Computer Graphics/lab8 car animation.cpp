//lab 8 - car animation - Write a program to draw a car using in build graphics function and translate it from bottom left corner to right bottom corner of screen.

#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main()
{
    int gm, gd = DETECT;
    int i = 0;
    
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    while (i <= 800)
    {
        line(0, 300, 800, 300); // Path
        
        // Body of the car
        line(50 + i, 220, 100 + i, 220);
        line(50 + i, 220, 30 + i, 250);
        line(100 + i, 220, 120 + i, 250);
        rectangle(0 + i, 250, 160 + i, 270);
        
        // Tyres of the car
        circle(30 + i, 285, 12);
        circle(130 + i, 285, 12);
        
        delay(50);
        
        if (i >= 800)
        {
            break;
        }
        
        i = i + 2;
        clearviewport(); // clearing image which would make the illusion of moving car
    }
    
    getch();
    closegraph();
    return 0;
}

