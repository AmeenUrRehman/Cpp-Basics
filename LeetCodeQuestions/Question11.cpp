#include<iostream>
using namespace std;

int getpivot(int arr[] , int n){
    
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;

    while (start<end){

        if(arr[mid] >= arr[0]){
            start = mid + 1;
        }
        else {
            end = mid;
        }
        
        mid = start + (end - start)/2;
    }

    return start;
}

int main(){

    int arr[5] = {0,10,17,3,1};
    cout << "Pivot Element is : "<< getpivot(arr , 5);

}