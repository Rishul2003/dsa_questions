#include<bits/stdc++.h>
using namespace std;
int maxpathsum(vector<vector<int>>&a,int i,int j,int n,int m,vector<vector<int>>&dp){
      if(j<0||j>m){
        return INT16_MIN;
      }
      if(i==0){
        dp[i][j]=a[i][j];
        return a[i][j];
      }
      if(dp[i][j]!=-1){
        return dp[i][j];
      }
      int top=a[i][j]+maxpathsum(a,i-1,j,n,m,dp);
      int left=a[i][j]+maxpathsum(a,i-1,j-1,n,m,dp);
      int right=a[i][j]+maxpathsum(a,i-1,j+1,n,m,dp);
      dp[i][j]=max(left,max(top,right));;
      return max(left,max(top,right));
}
int main(){
    vector<vector<int>>a{{2,1,3},{6,5,4},{7,8,9}};
    int n=a.size(),m=a[0].size();
    int k=INT16_MIN;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int j=0;j<m;j++){
        k=max(k,maxpathsum(a,n-1,j,n,m,dp));
    }
    cout<<k<<endl;


    //tabulation
    vector<vector<int>>dp1(n,vector<int>(m,-1));
    for(int j=0;j<n;j++){
      dp[0][j]=a[0][j];
      for(int i=1;i<n-1;i++){
        for(int j=0;j<n-1;j++){

          int top=INT16_MIN;
          int right=INT16_MIN;
          int left=INT16_MIN;
          top=a[i][j]+dp[i-1][j];
          if((j-1)>=0){
          left=a[i][j]+dp[i-1][j-1];
          }
          if((j+1)<m){

          right=a[i][j]+dp[i-1][j+1];
          }
          int a1=max(top,max(left,right));
          dp[i][j]=a1;
        }

      }
      int ans=dp[n-1][0];
      for(int j=0;j<m;j++){
        ans=max(ans,dp1[n-1][j]);
      }
      cout<<ans<<endl;
    }
}