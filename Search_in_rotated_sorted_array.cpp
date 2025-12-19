#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int searchindex(int target){
int l=0,h=vec.size()-1;

while(l<=h){
    int mid=(l+h)/2;
    if(vec[mid]==target){
        return mid;
    }
    if(vec[l]<=vec[mid]){
        if(target>=vec[l] && target<vec[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    else{
            if(target>vec[mid] && target<=h){
                l=mid+1;
            }
            else{
                h=mid-1;
            }

    }
}



return -1;

}

int main(){

int n,x,target;
cin>>n;

for(int i=0;i<n;i++){
    cin>>x;
    vec.push_back(x);
}
cin>>target;
cout<<searchindex(target)<<endl;



return 0;}
