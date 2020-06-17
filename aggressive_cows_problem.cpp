#include<bits/stdc++.h>
using namespace std;
bool helper(int n,int cows,long long arr[],long long mid){
    long long check=arr[0];
    int coun=1;
 for(int i=1;i<n;i++){
    if(arr[i]-check>=mid){
        coun++;
        check=arr[i];
        }
    if(coun==cows){
       return true;
        }

     }
	return false;
}
int main() {
int t;
    cin>>t;
    while(t--){
        int n,cows;
        cin>>n>>cows;
       long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        long long start=0;
        long long endit=arr[n-1]-arr[0];
        long long ans=-1;
        while(start<=endit){
        long long mid=start+(endit-start)/2;
            if(helper(n,cows,arr,mid)){
                ans=mid;
                start=mid+1;
            }
            else
                endit=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
