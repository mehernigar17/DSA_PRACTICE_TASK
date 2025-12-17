#include<bits/stdc++.h>
using namespace std;
vector<int> vec;


bool isSquare(int n){

if(n<2) return true;
int l=1,h=n/2;

while(l<=h){
        int mid=(l+h)/2;
        int sqrt=mid*mid;
    if(sqrt==n){
        return true;
    }
    else if(sqrt<n){
            h=mid-1;

    }
     else if(mid<n){
        l=mid+1;
    }


}
return false;

}



int main(){

int n;
cin>>n;

cout<<isSquare(n);



return 0;



}
