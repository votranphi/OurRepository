#include <stdio.h>

int main()
{
    long long n = 0;
    scanf("%lld", &n);
    printf("%lld ", n);
    while (n != 1)
    {
        (n % 2) ? (n = 3 * n + 1) : (n /= 2);
        printf("%lld ", n);
    }
}