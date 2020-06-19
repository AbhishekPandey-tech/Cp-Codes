#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	  
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    int l=1;
	    int max=INT_MIN;
	    int arr1[n],arr2[n];
	   arr1[0]=1;
	    for(int i=1;i<n;i++){
	      
	        if(arr[i]>arr[i-1]){
	            arr1[i]=arr1[i-1]+1;
	            
	        }
	        else{
	          arr1[i]=1;
	            
	        }
	       
	    }
        arr2[n-1]=1;
	  
	    for(int i=n-2;i>=0;i--){
	       
	        if(arr[i]>arr[i+1]){
	            arr2[i]=arr2[i+1]+1;
	        }
	        else{
	            arr2[i]=1;
	            
	        }
	       
	    }
	   
	    for(int i=0;i<n-1;i++){
	        if(arr[i]!=arr[i+1])
	        if(max<(arr1[i]+arr2[i+1]))
	        max=arr1[i]+arr2[i+1];
	    }
	  cout<<(max)<<endl;
	}
	return 0;
}
