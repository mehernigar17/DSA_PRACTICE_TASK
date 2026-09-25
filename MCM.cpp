#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int m[1000][1000];
int s[1000][1000];
vector <int> p = {30,35,15,5,10,20,25};
int n = p.size()-1;

void printMCM(int i,int j)
{
    if(i == j)
    {
        cout << "A" << i;
    }
    else{
        cout << "(";
        printMCM(i,s[i][j]);
        printMCM(s[i][j]+1,j);
        cout << ")";

    }
}

void MCM()
{
    for(int l = 1; l <=n; l++)
   {
       m[l][l] = 0;
   }
   for(int l = 2; l <= n ; l++)
   {
       for(int i = 1; i <= n-l+1; i++)
       {
           int j = i + l - 1;
           m[i][j] = inf;
           for(int k = i; k <= j-1; k++)
           {
             int q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
             if(m[i][j] > q)
             {
                 m[i][j] = q;
                 s[i][j] = k;
             }
           }
       }

   }
}

int main()
{
   MCM();
   cout << m[1][6];
   cout << endl;
   printMCM(1,6);

}
