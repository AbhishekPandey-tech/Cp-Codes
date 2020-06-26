#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m,l,r,arrival;
	    cin>>n>>m;
	    int c=0;
	    int lat=0;
	    vector<pair<int,int>> interval;
	    for(int i=0;i<n;i++){
	        cin>>l>>r;
	        interval.push_back(make_pair(l,r));
	    }
	    sort(interval.begin(),interval.end());
	    for(int i=0;i<m;i++){
	        cin>>arrival;
           // cout<<"!";

	        int low=lower_bound(interval.begin(),interval.end(),make_pair(arrival,0))-interval.begin();
	        cout<<"!";
	        cout<<(*lower_bound(interval.begin(),interval.end(),make_pair(arrival,0))).first;
	        cout<<" ";
	        cout<<(*lower_bound(interval.begin(),interval.end(),make_pair(arrival,0))).second;
	        cout<<"!";
            if(low==0){
                    int ans=interval[0].first-arrival;
               cout<<ans<<endl;
            }
           else {
                int ans=-1;
            if(interval[low-1].second>arrival)
                ans=0;
           else if(low<interval.size())
            ans=interval[low].first-arrival;

            cout<<ans<<endl;
	    }
	}
	}
	return 0;
}

