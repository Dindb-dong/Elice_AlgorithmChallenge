#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int> &arr, int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;
    int n = arr.size();
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Element is not present in array" << endl;
    else
        cout << "Element is present at index " << result << endl;
    return 0;
}

// 복잡도: O(log n)