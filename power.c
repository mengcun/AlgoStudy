/*
*Power operations: X^N = X^(N/2) * X^(N/2) When the N is Even.
*                  X^N = X^((N-1)/2) * X^((N-1)/2) * X When the N is Odd.    
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 50
#define X 3
long int Pow(long int x, unsigned int n);
bool IsEven(unsigned int i);

int main(void)
{
    long int powerValue;
    powerValue = Pow(X, N);
    printf("%ld\n", powerValue);
}

long int Pow(long int x, unsigned int n)
{
    if(n == 0)
        return 1;
    if(IsEven(n))
        return Pow(x*x, n/2);
    else
        return Pow(x*x, n/2)*x;
}

bool IsEven(unsigned int i)
{
    return i % 2 == 0;
}
