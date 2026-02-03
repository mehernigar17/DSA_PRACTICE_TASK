#include<bits/stdc++.h>
using namespace std;
vector<int>vec;
void selection_sort(){

for(int i=0;i<vec.size()-1;i++){
    int minIndex=i;
    for(int j=i+1;j<vec.size();j++){
        if(vec[j]<vec[minIndex]){
            minIndex=j;

        }
    }
    swap(vec[i],vec[minIndex]);
}





}

int main(){

int n,x;
cin>>n;
for(int i=0;i<n;i++){
    cin>>x;
    vec.push_back(x);
}

selection_sort();


for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
return 0;}
