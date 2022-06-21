#include<iostream>
#include <vector>

using namespace std;

int makepartition(int arr[], int l, int r){
    int m = rand()%(r-l+1);
    m+=l;
    int res = m;
    m = arr[m];
    int pos = l;
    for(int i=l; i<=r; i++){
        if(arr[i]<m){
            int temp = arr[pos];
            arr[pos] = arr[i];
            arr[i] = temp; 
            pos++;
        }
    }
    pos = r;
    for(int i=r; i>=l; i--){
        if(arr[i]>=m){
            int temp = arr[pos];
            arr[pos] = arr[i];
            arr[i] = temp;
            pos--;
        }
    }
    return res;
}

void quicksort(int arr[], int l, int r){
    if(l>=r){
        return;
    }
    int m = makepartition(arr, l, r);
    quicksort(arr, l, m);
    quicksort(arr, m+1, r);
}

int main(){
    int n;
    cout<<"enter no of elements: ";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quicksort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}