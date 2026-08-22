#include<bits/stdc++.h>
using namespace std;

double f(vector <double> &a,double x)
{
    double result = a[0];
    for(int i =1; i < a.size(); i++)
    {
        result = result * x + a[i];
    }
    return result;
}
double fd(vector <double> &a,double x, int n)
{
    double result = 0;
    for(int i =0; i < n; i++)
    {
        result = result * x + (n-i) * a[i];
    }
    return result;
}

int main()
{
    double error,prevRoot, root,x1,x2,l,r,f1,f2,f0;
    vector <double> shohog = {1,-3,-3,11,-6};


    int n = 4;
    double sb = sqrt(pow(shohog[1]/shohog[0],2) - (2*(shohog[2]/shohog[0])));
    cout << "Search Bracket: [" << sb << " , " << sb << "]" << endl;
    prevRoot = sb;
    int noOffroot = 1;
    int itr = 1;
    while(n > 1)
    {
        cout << "Connverginng to root no. : " << noOffroot << endl;
        do{
           f1 = f(shohog,prevRoot);
           f2 = fd(shohog,prevRoot,n);
           root = prevRoot - (f1/f2);
           error = abs((root - prevRoot)/root);
           prevRoot = root;

           printf("%3d | %10.6f | %10.6f | %10.6f | %10.6f |", itr,root,prevRoot,f(shohog,root), error );
           cout << endl;
           itr++;
        }
        while(error > 0.00001);
        cout << "root : " << root << endl;
        vector <double> newCoeff(n);
        newCoeff[0] = shohog[0];
        for(int i =1 ; i < n; i++)
        {
            newCoeff[i] = shohog[i] + newCoeff[i-1] * root;
        }
        shohog = newCoeff;
        n--;
        noOffroot++;
        itr = 1;
        cout << endl;
    }
    cout << "Connverginng to root no. : " << noOffroot << endl;
    cout << "root : " << - (shohog[1]/shohog[0]) << endl;
    cout << endl;

}
