#include <stdio.h>
int main()
{
    long long n = 0;
    scanf("%lld", &n);
    long long sum = 0;
    for (long long i = 0; i < n; ++i)
    {
        long long temp = 0;
        scanf("%lld", &temp);
        sum += temp;
    }

    printf("%lld", n * (n + 1) / 2 - sum);
    return 0;
}