//program to compute the sum of x four times and the cube of x
#include <stdio.h>
#include <math.h>

int fourtimessquare(int x);
int cube(int x);

int main()
{
    int x;

    printf("Input the value of x: ");
    scanf("%d", &x);

    printf("x = %d\n", x);
    printf("Sum of x four times = %d\n", fourtimessquare(x));
    printf("Cube of x = %d\n", cube(x));

    return 0;
}

int fourtimessquare(int x)
{
    return 4 * pow(x, 2);
}

int cube(int x)
{
    return x * x * x;
}