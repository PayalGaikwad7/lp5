#include <iostream>
#include <omp.h>
using namespace std;

void pbs(int* arr, int n){
    for (int i=0; i<n; i++){
        int phase = i%2;
        #pragma omp parallel for
        for(int j=phase; j<n-1; j+=2){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int n;
    cout<<"enter the no of elements: ";
    cin>>n;
    int* arr = new int[n];
    cout<<"enter elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    pbs(arr,n);
    cout<<"sorted array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
