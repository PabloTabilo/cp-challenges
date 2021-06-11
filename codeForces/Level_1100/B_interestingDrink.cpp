#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

// https://codeforces.com/problemset/problem/706/B
using namespace std;

void printArr(vector<int> arr1, int n){
    cout<<endl;
    for(int x = 0; x < n; x++){
        cout<<arr1[x]<<" ";
    }
    cout<<endl;
}

int binarySearch(vector<int> arr1, int l, int r, int k){
    int mid = (l+r)/2;
    if(l<r){
        if(arr1[mid] == k)
            return mid;
        else if(arr1[mid] > k)
            return binarySearch(arr1, l, mid-1, k);
        else if(arr1[mid] < k)
            return binarySearch(arr1, mid+1, r, k);
    }
    return max(l,r);
}

void myMerge(vector<int> &arr1, int l, int mid, int r){
    const int n1 = mid - l + 1;
    const int n2 = r - mid;
    int L[n1];
    int R[n2];
    for(int i = 0; i < n1; i++)
        L[i] = arr1[l+i];
    for(int i = 0; i < n2; i++)
        R[i] = arr1[mid + 1 + i];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] < R[j])
            arr1[k] = L[i++];
        else
            arr1[k] = R[j++];
        k++;
    }
    for(;i<n1;i++){
        arr1[k++] = L[i];
    }
    for(;j<n2;j++){
        arr1[k++] = R[j];
    }
}

void mergeSort(vector<int> &arr1, int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr1, l, mid);
        mergeSort(arr1, mid+1, r);
        myMerge(arr1, l, mid, r);
    }
}

int main()
{
    int N, Q;
    cin >> N;
    vector<int> arr;
    arr.reserve(N);
    copy_n(istream_iterator<int>(cin), N, back_inserter(arr));
    mergeSort(arr, 0, N-1);
    cin >> Q;
    while(Q--){
        int q;
        cin >> q;
        int res = binarySearch(arr, 0, N-1, q);
        //cout<<res<<endl;
        if (q >= arr[res])
            res++;
        //if(res > N-1)


        cout<<res<<endl;
    }
    return 0;
}
