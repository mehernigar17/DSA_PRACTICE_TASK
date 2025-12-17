#include<bits/stdc++.h>
using namespace std;
vector <int>vec;


  int  searchbinary(int target){

  int l=0,h=vec.size()-1;

  while(l<=h){
        int mid=(l+h)/2;
    if(vec[mid]==target){
        return mid;
    }
    else if( vec[mid]>target){
        h=mid-1;
    }
    else if(vec[mid]<target){
        l=mid+1;
    }


  }
  return l;
  }

  int main(){

  int n,x,v;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>x;
    vec.push_back(x);
  }
  cin>>v;
  cout<<searchbinary(v);

  return 0;}
