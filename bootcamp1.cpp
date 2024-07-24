#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// Insertion Sort
void insertionSort(std::vector<int> &arr)
{
    for (size_t i = 1; i < arr.size(); ++i)
    {
        int key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

// Merge Sort
void merge(std::vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort
int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 측정 시간 함수
template <typename Func>
void measure_time(Func sort_function, std::vector<int> arr, const char *sort_name, const char *order)
{
    auto start = std::chrono::high_resolution_clock::now();
    sort_function(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << sort_name << " on " << order << " array took " << duration.count() << " seconds." << std::endl;
}

template <typename Func>
void measure_time_with_indices(Func sort_function, std::vector<int> arr, const char *sort_name, const char *order)
{
    auto start = std::chrono::high_resolution_clock::now();
    sort_function(arr, 0, static_cast<int>(arr.size()) - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << sort_name << " on " << order << " array took " << duration.count() << " seconds." << std::endl;
}

int main()
{
    const size_t SIZE = 10000000;
    std::vector<int> ascending(SIZE);
    std::vector<int> descending(SIZE);
    std::vector<int> random(SIZE);

    for (size_t i = 0; i < SIZE; ++i)
    {
        ascending[i] = static_cast<int>(i + 1);
        descending[i] = static_cast<int>(SIZE - i);
        random[i] = rand() % SIZE;
    }

    measure_time(insertionSort, ascending, "Insertion Sort", "ascending");
    measure_time(insertionSort, descending, "Insertion Sort", "descending");
    measure_time(insertionSort, random, "Insertion Sort", "random");

    measure_time_with_indices(mergeSort, ascending, "Merge Sort", "ascending");
    measure_time_with_indices(mergeSort, descending, "Merge Sort", "descending");
    measure_time_with_indices(mergeSort, random, "Merge Sort", "random");

    measure_time_with_indices(quickSort, ascending, "Quick Sort", "ascending");
    measure_time_with_indices(quickSort, descending, "Quick Sort", "descending");
    measure_time_with_indices(quickSort, random, "Quick Sort", "random");

    return 0;
}