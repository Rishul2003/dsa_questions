#include<bits/stdc++.h>
using namespace std;
int mincost(int i,int j,int m,int n,vector<vector<int>>&a,vector<vector<int>>&dp){
    if(i==0 && j==0){
        dp[i][j]=a[i][j];
        return a[i][j];
    }
    if(i<0|| j<0){
        return INT16_MAX;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=a[i][j]+mincost(i-1,j,m,n,a,dp);
    int left=a[i][j]+mincost(i,j-1,m,n,a,dp);
    dp[i][j]=min(up,left);
    return dp[i][j];
}
int main(){

    //
    int n,m;
    cin>>n>>m;
    int a[n][m];
    vector<vector<int>>dp(n,vector<int>(m,-1));
    // dp[0][0]=a[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j]=0;
            }int up=INT16_MAX;
            int left=INT16_MAX;
            if((i-1)>=0){
             up=a[i][j]+dp[i-1][j];
             }
             if((j-1)>=0){
            int left=a[i][j]+dp[i][j-1];
            }
            dp[i][j]=min(up,left);
        }
    }

    vector<int>dp1(n,INT16_MAX);
    for(int i=0;i<n;i++){
        vector<int>temp(n);
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                temp[j]=a[i][j];
            }
            else{
                int up=a[i][j]+dp1[j];
                int left=a[i][j]+temp[j-1];
                temp[j]=min(up,left);
            }
        }
        dp1=temp;
    }
    return dp1[m-1];

    return (dp[n-1][m-1]);
    return 0;
}