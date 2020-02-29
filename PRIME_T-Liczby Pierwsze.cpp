#include <iostream>
bool prime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int num_tests;
    std::cin >> num_tests;

    for (int i = 0; i < num_tests; ++i)
    {
        int num;
        std::cin >> num;
        if (prime(num) == true)
        {
            std::cout << "TAK\n";
        }
        else 
        {
            std::cout << "NIE\n";
        }
    }
}
