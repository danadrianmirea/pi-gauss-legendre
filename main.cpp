#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double calculatePIUsingLeibniz(int iterations)
{
    double pi = 0.0f;
    int sign = 1;

    for (int i = 0; i < iterations; i++)
    {
        pi += sign * (4.0 / (2 * i + 1)); // Leibniz formula
        sign *= -1;                       // Alternate sign for each term
    }

    return pi;
}

double calculatePIUsingGaussLegendre(int iterations)
{
    // Initial values
    double a = 1.0;
    double b = 1.0 / sqrt(2);
    double t = 0.25;
    double p = 1.0;

    double a_next, b_next, t_next;

    // Perform iterations
    for (int i = 0; i < iterations; i++)
    {
        a_next = (a + b) / 2;
        b_next = sqrt(a * b);
        t_next = t - p * (a - a_next) * (a - a_next);
        p *= 2;

        a = a_next;
        b = b_next;
        t = t_next;
    }

    // Approximate value of Pi
    double pi = ((a + b) * (a + b)) / (4 * t);

    return pi;
}

int main()
{
    double res1 = calculatePIUsingLeibniz(10000);       // 10000 iterations and still very far off:             3.141492653590034
    double res2 = calculatePIUsingGaussLegendre(3);     // converges well enough after just three iterations    3.141592653589794

    printf("PI with Leibniz: %.15f\n", res1);
    printf("PI with Gauss-Legendre: %.15f\n", res2);

    return 0;
}