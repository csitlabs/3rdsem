//1. Approximation of root of nonlinear equation using Bisection Method

#include <stdio.h>
#include <math.h>

#define EPS 0.00001

float f(float x) {
  // return x * x * x - 2 * sin(x); // change this function for another run
  //  return x*x*x -3;
  return x * x * x - 5;
}

int main() {
    float a, b, c;
    int n = 0;

    do {
        printf("Enter two valid initial a and b: ");
        scanf("%f %f", &a, &b);
    } while (f(a) * f(b) >= 0);

    do {
        n++;
        c = (a + b) / 2;

        if (f(c) == 0) break;

        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    } while (fabs((b - a) / a) > EPS);

    printf("The approximate root of the given function is %f with %d number of iterations.", c, n);
    return 0;
}
