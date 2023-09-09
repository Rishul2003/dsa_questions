#include<bits/stdc++.h>
using namespace std;
int f(vector<vector<int>>a,int i,int j ,vector<vector<int>>&dp){
    if(i==0 && j==0){
        dp[i][j]=1;
        return 1;
    }
    if(i<0|| j<0){
        return 0;
    }
    if(a[i][j]==-1){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int left=f(a,i,j-1,dp);
    int up=f(a,i-1,j,dp);
    dp[i][j]=up+left;
    return dp[i][j];
}
int main(){
    return 0;
}