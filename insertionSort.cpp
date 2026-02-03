#include<bits/stdc++.h>
using namespace std;
vector<int>a;
void insertion_sort(){
for(int i=1;i<a.size()-1;i++){
    int key=a[i];
    int j=i-1;
    while(j>=0&&a[j]>key){
        a[j+1]=a[j];
        j=j-1;
    }
    a[j+1]=key;

}









}








int main(){

int n,x;
cin>>n;
for(int i=0;i<n;i++){
    cin>>x;
    a.push_back(x);
}

insertion_sort();


for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
return 0;}
