#include <iostream>
using namespace std;

int factorialIterative(int n)
{
    int result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int number = 5;
    cout << "Factorial of " << number << " is " << factorialIterative(number) << endl;
    return 0;
}

// 복잡도: O(n)