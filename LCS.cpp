#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int c[1000][1000];
int b[1000][1000];
string x = "ABCBDAB";
string y = "BDCABA";
int m = x.size()+1;
int n = y.size()+1;


// diagonal = 1
// left = 2
// up = 3

void printLCS(int i, int j)
{
    if(i == 0  || j == 0)
    {
        return;
    }
    if(b[i][j] == 1)
    {
        printLCS(i-1,j-1);
        cout << x[i-1];
    }
    else if(b[i][j] == 3)
    {
        printLCS(i-1,j);
    }
    else{
          printLCS(i,j-1);
    }
}

void LCS()
{
    for(int i = 0; i < m; i++)
    {
        c[i][0]=0;
    }
    for(int i = 0; i < n; i++)
    {
        c[0][i]=0;
    }
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 1;
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 3;
            }
            else{
                c[i][j] = c[i][j-1];
                b[i][j] = 2;
            }
        }
    }
}

int main()
{
   LCS();
   cout << c[m-1][n-1];
   cout << endl;
   printLCS(m-1, n-1);
}


