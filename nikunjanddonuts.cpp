#include <bits/stdc++.h>
using namespace std;

void mergeIt(int arr[],int left,long long mid,int right){
long i=left;
    long j=mid;
    long temp[right-left+1];
    long k=0;
    while(i<mid&&j<=right){
        if(arr[i]>=arr[j]){

            temp[k++]=arr[i++];

        }
        else{

            temp[k++]=arr[j++];
        }
    }
    while(i<mid)
        temp[k++]=arr[i++];
    while(j<=right)
        temp[k++]=arr[j++];
    for(int i=left,k=0;i<=right;i++,k++)
        arr[i]=temp[k];

}
void merge_sort(int input[],int left,int right){
    if(left<right){
        long long mid=(left)+(right-left)/2;
        merge_sort(input,left,mid);
        merge_sort(input,mid+1,right);
        mergeIt(input,left,mid+1,right);
    }
}
int main()
{
    //Write your code here
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    merge_sort(arr,0,n-1);
    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<"\n";
    int s=0;
    for(int i=0;i<n;i++){
        s=s+((pow(2,i))*arr[i]);
    }
    cout<<s;
    return 0;
}
