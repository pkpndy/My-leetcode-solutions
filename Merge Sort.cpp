void merge(vector<int>& arr, int l, int mid, int r) {
    // we determine the length of both the halves so that 
    // we can take the help of another arrays to merge them in ascending order
    int lsize = mid-l + 1;
    int rsize = r-mid; // r-mid kyuki right array ka start mid ke just baad se hota hai

    // then we create two arrays jime hm sorted wale numbers store krenge
    int L[lsize];
    int R[rsize];
    int k=l;
    for(int a=0; a<lsize; a++) {
        L[a] = arr[k];
        k++;
    }
    for(int b=0; b<rsize; b++) {
        R[b] = arr[k];
        k++;
    }

    // fir undono khud mein sorted arrays ko merge krenge in the right order
    k=l;
    int i=0, j=0;
    while(i<lsize && j<rsize) {
        if(L[i]<=R[j]) {
            arr[k]=L[i];
            i++;
        } else {
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    // dono mein se kisi bhi array ke elements reh jayenge toh unko add krenge
    while(i<lsize) {
        arr[k]=L[i];
        i++;    k++;
    }
    while(j<rsize) {
        arr[k]=R[j];
        j++;    k++;
    }
}

// what we simply do is that we split the array every time
// then merge the resulting arrays in their ordered position
void solve(vector<int>& arr, int l, int r) {
    // if left and right meet that means there is only single element array
    // hence return since an arraay having sinlge element is sorted
    if(l==r)    return;

    // we find the mid by this as directly using r-l might 
    // result in a mid point that is in the left half not current right half
    int mid = l+(r-l)/2;

    solve(arr, l, mid); //ask recursion to solve left half
    solve(arr, mid+1, r); //ask recursion to solve the right half
    merge(arr, l, mid, r); //then merge both the halves in ascending order of elements
}

void mergeSort(vector < int > & arr, int n) {
    if(arr.size() == 1) return;

    solve(arr, 0, n-1); //we simply call the solve function to sort and merge
}