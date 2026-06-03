#include <bits/stdc++.h> 

// quick sort has simple funda ek pivot pakdo usko uski sahi position pe lao
// uski sahi position ke baad uske left sub array aur right sub array mein same kaam kr do
// sahi position ke liye pivot ki value se chhote saare value left mein krte jao
// fir jb usse saare chote left ho jayein tb pivot element ko just agle right mein daal do

int partition(vector<int>& arr, int low, int high) {
    int pi = arr[high];
    int p = low;
    for(int i=low; i<high; i++) {
        if(arr[i]<pi) {
            swap(arr[i], arr[p]);
            p++;
        }
    }
    swap(arr[p], arr[high]);
    return p;
}

void quick(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    
    int pivot = partition(arr, low, high);
    quick(arr, low, pivot-1);
    quick(arr, pivot+1, high);
}

vector<int> quickSort(vector<int> arr)
{
    quick(arr, 0, arr.size()-1);
    return arr;
}
