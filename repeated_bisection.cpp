#include<bits/stdc++.h>
using namespace std;

vector<double>a= {1,-6,11,-6};

double f(double x)
{
    double result =a[0];
    for(int i=1; i<a.size(); i++)
    {
        result=result*x+a[i];
    }
    return result;
}

int main()
{
    double ds,error,root,x1,x2,f1,f2,f0;
    double sb=sqrt((pow(a[1]/a[0],2))-(2*(a[2]/a[0])));
    cout <<"Search Bracket:[-"<<sb<<","<<sb<<"]"<<endl;
    x1=-sb;
    ds=0.2;
    x2=x1+ds;
    while(x2<sb)
    {
        double prevRoot=x1;
        if(f(x1)*f(x2)<0)
        {
            double l=x1;
            double r=x2;
            do{
                f1=f(l);
                f2=f(r);
                root=(l+r)/2;
                f0=f(root);
                error=fabs((root-prevRoot)/2);
                if(f0==0)
                {
                    break;
                }
                else if(f1*f0<0)
                {
                    r=root;
                }else{
                    l=root;
                }
                prevRoot=root;
            }
            while(error>=0.00001);
            cout<<"Final Root:"<<root<<endl;
        }
        x1+=ds;
        x2=x1+ds;
    }
}
