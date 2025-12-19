#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int main(){

int n,x;
cin>>n;
for(int i=0;i<n;i++){
    cin>>x;
    vec.push_back(x);
}
for(int i=0;i<=n-2;i++){
        if(vec[i]%2!=0)continue;
    int minIndex=i;

    for(int j=i+1;j<=n-1;j++){
        if(vec[j]%2==0&&vec[j]<vec[minIndex]){
        minIndex=j;


        }

    }

    swap(vec[i],vec[minIndex]);

}



for(int i=0;i<n;i++){
    cout<<vec[i]<<endl;
}




return 0;}
