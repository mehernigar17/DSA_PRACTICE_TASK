#include<bits/stdc++.h>
using namespace std;

void merge_sort(vector<int>& a,int low,int mid,int high){

int i=low;
int j=mid+1;
int k=low;
int temp[100];


while(i<=mid &&j<=high){
    if(a[i]<a[j]){
        temp[k]=a[i];
        i++;
    }
    else{
        temp[k]=a[j];

        j++;
    }
    k++;
}

while(i<=mid){
    temp[k]=a[i];
    i++;
    k++;
}

while(j<=high){
    temp[k]=a[j];
    j++;
    k++;

}
for(int x=low;x<=high;x++){
    a[x]=temp[x];
}
}


void MergeSort(vector<int>& a,int low,int high){
if(low<high){


int mid=(low+high)/2;
MergeSort(a,low,mid);
MergeSort(a,mid+1,high);

merge_sort(a,low,mid,high);


}



}


int main(){

vector<int> a={1,2,6,9,4,5,8};
 MergeSort(a,0,a.size()-1);



for(int i = 0; i < a.size(); i++){
    cout << a[i] << " ";
}




return 0;}






