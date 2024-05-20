#include <bits/stdc++.h>
using namespace std;

void recursiveReverse(int i , int n , int arr[]){
    if(i>n/2){
        return ;
    }
    swap(arr[i],arr[n-1-i]);
    recursiveReverse(i+1,n,arr);
}
int main() {
    int n;
    cout<<"Give the input below \n";
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    recursiveReverse(0,n,arr);
    
    for(int i =0; i< n;i++){
        cout<<arr[i]<<"";
    }
    return 0;
}