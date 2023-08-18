//16. Integrating a function using Composite Simpsons 1/3 Rule

#include <stdio.h>
#include <math.h>

float f(float x)
{
   // return 1.0 - exp(-x / 2.0);
    return x * x * exp(sqrt(x));
}

// program to integrate a function using composite simpson's 1/3 rule
int main()
{
    int m, n, i;
    float a, b, h, sum = 0.0, ics, x;

    printf("Enter the lower limit of integration a: ");
    scanf("%f", &a);
    printf("Enter the upper limit of integration b: ");
    scanf("%f", &b);

    do
    {
        printf("Give number of segments 'n' (Even number): ");
        scanf("%d", &n);
    } while (n % 2 != 0);
    h = (b - a) / n;
    m = n / 2;

    for (i = 1; i <= m; i++)
    {
        x = a + (2 * i - 1) * h;
        sum = sum + 4 * f(x);

        if (i != m)
        {
            sum = sum + 2 * f(x + h);
        }
    }
    sum = sum + f(a) + f(b);
    ics = sum * h / 3.0;
    printf("\nIntegration between %f and %f when h = %f is %f\n", a, b, h, ics);

    return 0;
}
