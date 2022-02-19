#include <iostream>
#include <vector>

int InsertSort(std::vector<int> &arr)
{
    int n;
    for (int m = 1; m < arr.size(); m++)
    {
        int tmpValue = arr[m];
        for (n = m; n > 0 && arr[n - 1] > tmpValue; n--)
        {
            arr[n] = arr[n - 1];
        }
        arr[n] = tmpValue;
    }
    return 0;
}

int main()
{
    std::vector<int> arr = {4, 3, 8, 9, 2, 7, 8, 2, 1};
    InsertSort(arr);
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}