#include <bits/stdc++.h>
using namespace std;
int findMin(int *a,int *b,int n,int x,int dp[][10000])
{
     if(dp[n][x]!=0)
         return dp[n][x];
    if(n<=0)
        return 0;
    if(x==0)
        return a[0]+findMin(a+1,b+1,n-1,1,dp);
    if(x==n)
        return b[0]+findMin(a+1,b+1,n-1,x-1,dp);
    else
    {dp[n][x]= min((a[0]+findMin(a+1,b+1,n-1,x+1,dp)),(b[0]+findMin(a+1,b+1,n-1,x-1,dp)));
     return dp[n][x];
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>b[i]>>a[i];

    int dp[10000][10000];
   cout<< findMin(a,b,n,0,dp)<<endl;
    return 0;
}  
