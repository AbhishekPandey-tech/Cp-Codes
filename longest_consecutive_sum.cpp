#include<bits/stdc++.h>
using namespace std;
#include <vector>
#include<map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    vector<int>result;
    if(n==1){
        result.push_back(arr[0]);
        return result;
    }
    map<int,int>lcs;
    for(int i=0;i<n;i++)
        lcs[arr[i]]=i;
        lcs[INT_MAX]=INT_MAX;

    	int max=0,count=0;
    	auto s=lcs.begin(),e=lcs.begin(),s1=lcs.begin(),s2=lcs.begin();
    auto j=lcs.begin();
    j++;
        for(;j!=lcs.end();j++){

            if((s->first)+1==j->first){
                count++;
                s++;
            }
              else
            { s++;
                 if(max==count)
                {
                     //cout<<s1->second<<" "<<s2->second<<endl;
                    if(s1->second>s2->second)
                    {

                        s1=s2;
                        e=j;
                    }

                }
				if(max<count)
                {
                    max=count;
                    s1=s2;
                    e=j;
                }

                count=0;
              s2=j;
            }
//            if(s==lcs.end())
//            {
//                 if(max==count)
//                {
//                     cout<<s1->first<<" "<<s2->first<<endl;
//                    if(s1->second<s2->second)
//                    {
//
//                        s1=s2;
//                        e=j;
//                    }
//
//                }
//				if(max<count)
//                {
//                    max=count;
//                    s1=s2;
//                    e=j;
//                }
//            }

        }
    for(auto st=s1;st!=e;st++)
        result.push_back(st->first);
    return result;
}

int main(){
  int size;

  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);

  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }

  delete arr;
}

