#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n,coin;
    cin>>n;

 int count=0;
    bool ans=true;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(arr[0]!=5)
        ans=false;
        else{
            map<int,int>freq;
            freq[5]=1;
            freq[10]=0;
            freq[15]=0;
            for(int i=1;i<n;i++){

                if(arr[i]==5){
                    freq[5]++;
                }
                if(arr[i]==10){
                    if(freq[5]>0){
                        freq[5]--;
                        freq[10]++;
                    }
                    else{
                        ans=false;
                        break;
                    }
                }

                    if(arr[i]==15){
                        if(freq[10]<=0&&freq[5]<2){
                            ans=false;
                            break;
                        }

                        if(freq[10]>0){
                            freq[10]--;
                        }

                        else if(freq[5]>=2){
                            freq[5]-=2;
                        }

                    }

                }
            }






    if(ans==true)
    cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

}

return 0;
}
