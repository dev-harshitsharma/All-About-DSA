#include <bits/stdc++.h>
using namespace std;

// Recursive function to print all subsets with a sum equal to the target sum
void printSubsWithSumK(int index, vector<int> &ds, int s, int sum, int arr[], int n) {
    if (index == n) {
        if (s == sum) {  
            for (auto it : ds) 
                cout << it << " ";
            cout << endl; 
        }
        return; 
    }
    // Include the current element in the subset
    ds.push_back(arr[index]);
    s = s + arr[index];
    printSubsWithSumK(index + 1, ds, s, sum, arr, n);
    
    // Backtrack: Remove the current element from the subset
    ds.pop_back();
    s = s - arr[index];
    // Exclude the current element from the subset and proceed
    printSubsWithSumK(index + 1, ds, s, sum, arr, n);
}
int main() {
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
   
    printSubsWithSumK(0, ds, 0, sum, arr, n); 

    return 0;
}