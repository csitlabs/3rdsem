//3. Approximation of root of nonlinear equation using Newton Raphson Method

#include <stdio.h>
#include <math.h>

#define EPS 0.00001

float f(float x)
{
   // return x * sin(x) + cos(x);
    return x * x * x - 5 * x + 7;
}

float fd(float x)
{
   // return x * cos(x);
    return 3 * x * x - 5;
}

int main()
{
    float x0, x1;
    int n = 1;

    do{	printf("Enter a valid input point(x0): ");
        scanf("%f", &x0);
    } while (fd(x0) == 0);

    x1 = x0 - (f(x0) / fd(x0));
    while (fabs((x1 - x0) / x1) > EPS)
    {
        n++;
        x0 = x1;
        x1 = x0 - (f(x0) / fd(x0));
        if (f(x1) == 0)
            break;
    }

    printf("The approximate root of given function is: %f with %d number of iterations.", x1, n);
    return 0;
}
