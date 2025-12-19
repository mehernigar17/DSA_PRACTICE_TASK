
#include<bits/stdc++.h>
using namespace std;
vector <int> vec;
int main(){

int x,n;
cin>>n;
for(int i=0;i<n;i++){
    cin>>x;
    vec.push_back(x);
}

int k;
cin>>k;
for(int i=0;i<k;i++){
        int minIndex=i;
    for(int j=i+1;j<=n-1;j++){
        if(vec[j]<vec[minIndex]){
            minIndex=j;
        }

    }
    swap(vec[i],vec[minIndex]);

}




for(int i=0;i<n;i++){
cout<<vec[i]<<endl;
}





return 0;}
