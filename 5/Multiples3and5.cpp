#include <vector>
#include <iostream>

int main()
{
    std::vector<int> multiplesOfThreeAndFive;
    int count;

    for (int i = 0; i < 1000; ++i)
    {
        if (i % 5 == 0 || i % 3 == 0)
        {
            std::cout << i << std::endl;
            count += i;
        }
    }

    std::cout << count;
    return 0;
}
