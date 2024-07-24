#include <iostream>
using namespace std;

int factorialRecursive(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorialRecursive(n - 1);
}

int main()
{
    int number = 5;
    cout << "Factorial of " << number << " is " << factorialRecursive(number) << endl;
    return 0;
}

// 복잡도: O(n)