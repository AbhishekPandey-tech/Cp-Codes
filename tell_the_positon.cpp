#include<bits/stdc++.h>
using namespace std;
bool comparator(string a,string b)
{
    return a<b;
}
int main()
{
    int n,s1,s2,s3;
    cin>>n;
    string s;
    map<int,vector<string>> mark;
    for(int i=0;i<n;i++)
    {

        cin>>s;
        cin>>s1;
        cin>>s2;
        cin>>s3;
        mark[(s1+s2+s3)].push_back(s);
    }
    int m=1;
//    for(auto i=mark.begin();i!=mark.end();i++)
//        cout<<(i->first)
    for(auto i=mark.rbegin();i!=mark.rend();i++)
    {
        int l=(i->second).size();
        if(l>1)
        {
            sort((i->second).begin(),((i->second).end()),comparator);
        }
        for(int j=0;j<l;j++)
        {
            cout<<m<<" "<<(i->second)[j]<<"\n";
            m++;
        }

    }
	return 0;
}

