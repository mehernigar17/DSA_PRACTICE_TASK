#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int n, int target){

    int low = 0;
    int high = n-1;

    while(low <= high){

        int mid = (low + high)/2;

        if(arr[mid] == target)
            return true;

        else if(arr[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return false;
}


int main(){

    int n;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }


  int unique[n],count=0;
  for(int i=0;i<n;i++){
  if(!binarySearch(unique,n,arr[i])){

    unique[count]=arr[i];
    count++;


  }

  }

  for(int i=0;i<count;i++){
    cout<<unique[i]<<endl;



  }
    return 0;
}
