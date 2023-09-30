#include<bits/stdc++.h>
using namespace std;
int funct(vector<vector<int>>&a,int i,int j1,int j2,int n,int m,vector<vector<vector<int>>>&dp){
    if(j1<0||j2<0||j1>=m||j2>=m){
        return INT_MIN;
    }
    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }
    if(i==n-1){
        if(j1==j2){
            dp[i][j1][j2]=a[i][j1];
            return a[i][j1];
            
        }
        else{
            dp[i][j1][j2]=a[i][j1]+a[i][j2];
            return a[i][j1]+a[i][j2];
        }
    }
    //explore all paths of alice and bob together
    int maxi=-1e8;
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            int value=0;
            if(j1==j2){

                value=a[i][j1];
            }
            else{
                value=a[i][j1]+a[i][j2];
                // k2=a[i][j1]+a[i][j2]+funct(a,i+1,j1+dj1,j2+dj2,n,m);
            }
            value=value+funct(a,i+1,j1+dj1,j2+dj2,n,m,dp);
            maxi=max(maxi,value);
        }
    }
    dp[i][j1][j2]=maxi;
    return maxi;
}
int main(){
    // dp[r][c][c];
    int n;int m;
    cin>>n>>m;
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));

    return 0;
}