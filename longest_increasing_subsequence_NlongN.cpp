#include<bits/stdc++.h>
using namespace std;
int binary(int *dp,int l,int r,int key){
    
    while(r-l>1){
        int m=l+(r-l)/2;
        if(dp[m]>=key){
            r=m;
        }
        else
        l=m;
    }
    return r;
}
int longestIncreasingSubsequence(int n,int *arr){
    int length=1;
    int dp[n];
    dp[0]=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<dp[0])
        dp[0]=arr[i];
        else if(arr[i]>dp[length-1])
        dp[length++]=arr[i];
        
        else{
            
            int ind=binary(dp,-1,length-1,arr[i]);
            dp[ind]=arr[i];
        }
        
        
    }
   return length; 
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<longestIncreasingSubsequence(n,arr)<<endl;
        
    }
    
    return 0;
}
