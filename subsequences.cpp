#include<bits/stdc++.h>
using namespace std;
int count_subsequences(string s,string arr[])
{
    if(s[0]=='\0')
    {
        arr[0]="";
        return 1;
    }
    int small=count_subsequences((s.substr(1)),arr);
    for(int i=0;i<small;i++){
        arr[i+small]=s[0]+arr[i];
    }
    return (2*small);
}
using namespace std;
int main(){
string s;
cin>>s;
int l=s.length();
int p=pow(2,l);
string *arr=new string[p];
int sub=count_subsequences(s,arr);
for(int i=0;i<sub;i++)
    cout<<arr[i]<<endl;
return 0;
}
