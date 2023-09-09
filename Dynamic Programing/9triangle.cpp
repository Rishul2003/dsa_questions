#include<bits/stdc++.h>
using namespace std;
int maxsum(int i,int j,int n,vector<vector<int>>&a,vector<vector<int>>&dp){
    if(i==n-1){
        dp[i][j]=a[i][j];
        return a[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int down=a[i][j]+maxsum(i+1,j,n,a,dp);
    // int top=INT16_MAX
    int right=a[i][j]+maxsum(i+1,j+1,n,a,dp);
    // int left=INT16_MAX;
    dp[i][j]=min(down,right);
    return min(down,right);
}
int maxsum(int i,int j,int n,vector<vector<int>>&a,vector<vector<int>>&dp){
    if(i==n-1){
        dp[i][j]=a[i][j];
        return a[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int down=maxsum(i+1,j,n,a,dp);
    // int top=INT16_MAX
    int right=maxsum(i+1,j+1,n,a,dp);
    // int left=INT16_MAX;
    dp[i][j]=min(down,right);
    return min(down,right);
}
int main(){
    int n;
    cin>>n;
    int a[n][n];
    vector<int>dp(n);
    for(int j=0;j<n;j++){
        dp[j]=a[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        vector<int>temp(n);
        for(int j=i;j>=0;j--){
            int top=a[i][j]+dp[j];
            int left=a[i][j]+dp[j+1];
            temp[j]=min(left,top);
        }
        dp=temp;
    }
    return dp[0];

}