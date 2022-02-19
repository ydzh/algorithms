#include <iostream>
#include <vector>

int LeftChild(int i)
{
    return i * 2 + 1;
}

void PercDown(std::vector<int> &arr, int root, int length)
{
    int child;
    int tmp = arr[root];
    for (; LeftChild(root) < length; root = child)
    {
        child = LeftChild(root);
        if (child + 1 < length && arr[child] < arr[child + 1])
        {
            child++;
        }
        if (tmp < arr[child])
        {
            arr[root] = arr[child];
        }
        else
        {
            break;
        }
    }
    arr[root] = tmp;
}

void SwapEle(std::vector<int> &arr, int first, int second)
{
    int tmp = arr[first];
    arr[first] = arr[second];
    arr[second] = tmp;
}

void HeapSort(std::vector<int> &arr)
{
    // build heap
    for (int leaf = arr.size() / 2 - 1; leaf >= 0; leaf--)
    {
        PercDown(arr, leaf, arr.size());
    }
    // sort
    for (int i = arr.size() - 1; i > 0; i--)
    {
        SwapEle(arr, 0, i);
        PercDown(arr, 0, i);
    }
}

int main()
{
    std::vector<int> arr = {4, 3, 8, 9, 2, 7, 8, 2, 1};
    HeapSort(arr);
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}