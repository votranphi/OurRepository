#include <iostream>

int main()
{
    long long n = 0;
    std::cin >> n;
    if (n == 1)
        std::cout << 0;
    else
    {
        long long pr[2];
        long long result = 0;
        long long temp = 0;
        std::cin >> temp;
        pr[0] = temp;
        std::cin >> temp;
        pr[1] = temp;
        if (pr[1] < pr[0])
        {
            result += pr[0] - pr[1];
            pr[1] = pr[0];
        }
        for (long long i = 2; i < n; ++i)
        {
            long long temp = 0;
            std::cin >> temp;
            pr[0] = pr[1];
            pr[1] = temp;
            if (pr[1] < pr[0])
            {
                result += pr[0] - pr[1];
                pr[1] = pr[0];
            }
        }
        std::cout << result;
    }
}