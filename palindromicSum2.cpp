#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        vector<int>g;
        int n,d;
        cin>>n>>d;
        while(n>1)
        {
            int c=n;
            int r=0;
            while(c>0)
            {
                r=r*10+(c%10);
                c=c/10;
            }
            if(r==n)
            g.push_back(n);
            n--;
        }

        int s1=0;
         for (auto i = g.begin(); i != g.end(); ++i)
         {
           int p= *i;

           int t=sqrt(p);
           int j=1;
           while(j<t)
           {
               int s=0;
               int m=j;
               while(s<p)
               {
                   s=s+(m*m);
                   m=m+d;
               }
               if(s==p)
               s1=s1+p;
               j++;

           }
         }
         cout<<s1<<endl;
    }
    return 0;
}
