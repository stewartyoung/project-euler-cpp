#include <iostream>
#include <stack>

int main()
{
    int fibonacciNumber1 = 1;
    int fibonacciNumber2 = 2;
    int fibonacci;
    int evenFibonacciSum = 2;

    while (fibonacci < 4'000'000)
    {
        fibonacci = fibonacciNumber2 + fibonacciNumber1;
        fibonacciNumber1 = fibonacciNumber2;
        fibonacciNumber2 = fibonacci;
        if (fibonacci % 2 == 0 && fibonacci < 4'000'000)
        {
            evenFibonacciSum += fibonacci;
        }
    }
    std::cout << evenFibonacciSum << std::endl;
}