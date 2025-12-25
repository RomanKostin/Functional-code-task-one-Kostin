#include <iostream>
#include <ctime>

size_t modular_pow(size_t base, size_t index, size_t modulus);

long long gcd(long long a, long long b);

bool test_ferma(size_t number,size_t k);

bool test_soloveia_shtrassena(size_t number, size_t k);

bool test_millera_rabina(size_t number, size_t k);

int main()
{
    size_t k = 100;
    srand(time(0));
    size_t value = 0;
    std::cin >> value;
    std::cout << test_ferma(value, k) << std::endl<<test_soloveia_shtrassena(value,k)<<std::endl<<test_millera_rabina(value,k);
    return 0;
}

size_t modular_pow(size_t base, size_t index, size_t modulus)
{
    size_t c = 1;
    for (size_t i = 0; i < index; i++)
    {
        c = (c * base) % modulus;
    }
    return c;
}
long long gcd(long long a, long long b)
{
    while (a && b)
        if (a > b) a %= b;
        else b %= a;
    return a + b;
}

bool test_ferma(size_t number,size_t k)
{
    if (number <= 3)
    {
        throw std::invalid_argument("number must be higher than 3");
    }
    for (size_t i = 0; i < k; i++)
    {
        size_t a = rand() % (number - 3) + 1;
        if (modular_pow(a, number - 1, number) != 1) return false;
    }
    return true;
}

bool test_soloveia_shtrassena(size_t number, size_t k)
{
    if (number <= 3)
    {
        throw std::invalid_argument("number must be higher than 3");
    }
    for (size_t i = 0; i < k; i++)
    {
        size_t a = rand() % (number - 3) + 2;
        if (gcd(a, number) > 1) return false;
        size_t mod_result = modular_pow(a, (number - 1) / 2, number);
        if (mod_result != number - 1 && mod_result != 1) return false;
    }
    return true;
}

bool test_millera_rabina(size_t number, size_t k)
{
    size_t s = 0,d = 0, n = number-1;
    while (n%2==0)
    {
        n = n / 2;
        s++;
    }
    d = (number - 1)/(std::pow(2,s));
    size_t y = 0;
    for (size_t i = 0; i < k; i++)
    {
        size_t a = rand()% (number - 4) + 2;
        size_t x = modular_pow(a,d,number);
        for (size_t j = 0; j < s; j++)
        {
            y = modular_pow(x, 2, number);
            if (y == 1 && x != 1 && x != number - 1) return false;
            x = y;
        }
        if (y != 1)
        {
            return false;
        }
    }
    return true;
}
