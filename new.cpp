#include <iostream>
#include <vector>
using namespace std;

int computation(int value)
{
    return value * 2;
}
int main()
{
    const int N = 10000;

    std::vector<int> result(N);

    for (int i = 0; i < N; i++)
    {
        result[i] = computation(i + 1);
    }
    std::cout << "Result: ";
    for (int i = 0; i < N; i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
