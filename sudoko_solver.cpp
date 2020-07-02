#include<bits/stdc++.h>
using namespace std;
bool findNumber(int arr[9][9],int &row,int &col){
for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        if(arr[i][j]==0){
            row=i;
            col=j;
            return true;
        }
    }
}
return false;
}
bool isSafeInRow(int arr[9][9],int r,int num){
    for(int i=0;i<9;i++){
        if(arr[r][i]==num)
        return false;
    }
    return true;
}
bool isSafeInColumn(int arr[9][9],int c,int num){
    for(int i=0;i<9;i++){
        if(arr[i][c]==num)
        return false;
    }
    return true;
}
bool isSafeInBox(int arr[9][9],int r,int c,int num){
   int r1=r-(r%3);
   int  c1=c-(c%3);
    for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
        if((arr[i+r1][j+c1])==num)
        return false;
    }
    }
    return true;
}
bool isSafe(int arr[9][9],int r,int c,int num){
    if(isSafeInRow(arr,r,num)&&isSafeInColumn(arr,c,num)&&isSafeInBox(arr,r,c,num))
    return true;

    return false;
}
bool solve(int arr[9][9]){
    int row,col;
    if(!findNumber(arr,row,col)){
        return true;
    }
    for(int i=1;i<=9;i++){
        if(isSafe(arr,row,col,i)){
            arr[row][col]=i;
            if(solve(arr))
            return true;
            arr[row][col]=0;
        }

    }
  return false;
 }
int main(){
    string s;
 int arr[9][9];
    for(int i=0;i<9;i++)
    {
        cin>>s;
        for(int j=0;j<9;j++)
            arr[i][j]=s[j]-'0';
    }
    solve(arr);
    cout<<endl;
     for(int j=0;j<9;j++){
     for(int i=0;i<9;i++){
         cout<<arr[j][i];
     }
     cout<<endl;
     }

    return 0;
}
