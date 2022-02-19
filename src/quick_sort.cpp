#include<iostream>
#include<vector>
#include<utility>

int swapEle(std::vector<int> &arr, int first, int second){
    int tmp = arr[first];
    arr[first] = arr[second];
    arr[second] = tmp;
    return 0;
}

int partition(std::vector<int> &arr, int left, int right, int pivotIndex){
    int pivotValue = arr[pivotIndex];
    swapEle(arr, pivotIndex, right);
    int storeIndex = left;
    for(int i = left; i <= right - 1; i++){
        if(arr[i] < pivotValue){
            swapEle(arr, i, storeIndex);
            storeIndex++;
        }
    }
    swapEle(arr, right, storeIndex);
    return storeIndex;
}

int pickPivotIndex(std::vector<int> &arr, int left, int right){
    int pivotIndex = left;
    if(left > right){
        int midIndex = (right + left) / 2;
        if(arr[midIndex] >= arr[left]){
            if(arr[midIndex] <= arr[right]){
                pivotIndex = midIndex;
            }
            else if(arr[right] >= arr[left]){
                pivotIndex = right;
            }
            else{
                pivotIndex = left;
            }
        }
        else{
            if(arr[left] <= arr[right]){
                pivotIndex = left;
            }
            else{
                pivotIndex = right;
            }
        }
    }
    return pivotIndex;
}

int qucikSort(std::vector<int> &arr, int left, int right){
    if(right > left){
        int pivotIndex = pickPivotIndex(arr, left, right);
        int newPivotIndex = partition(arr, left, right, pivotIndex);
        qucikSort(arr, left, newPivotIndex - 1);
        qucikSort(arr, newPivotIndex + 1, right);
    }
    return 0;
}

int main(){
    std::vector<int> arr = {4, 3, 8, 9, 2, 7, 8,2,1};
    qucikSort(arr, 0, arr.size() - 1);
    for(auto it = arr.begin(); it != arr.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

}