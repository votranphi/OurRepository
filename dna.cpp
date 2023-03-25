#include <iostream>

int main()
{
    std::string a = "";
    std::cin >> a;

    long long count = 1;
    long long max = INT64_MIN;
    if (a.length() == 1)
        std::cout << 1;
    else
    {
        for (size_t i = 0; i < a.length() - 1; ++i)
        {
            if (a[i] == a[i + 1])
                count++;
            else
                count = 1;
            if (count > max)
                max = count;
        }
        std::cout << max;
    }
    return 0;
}