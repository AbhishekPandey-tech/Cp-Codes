#include<bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
    long long s,n;
    cin>>s>>n;
    long long ans=0;
    if(s>=n){

            if(n%2!=0)
            n--;
        long long d=s/n;
        ans=d;
        long long r=s%n;
        if(r==1||(r%2==0&&r!=0))
            ans++;
        else if(r%2!=0){
            ans=ans+2;
        }



    }
    else
    {
       if(s%2==0)
            ans=1;
       else
        ans=2;

    }

    cout<<ans<<endl;
}


return 0;
}
