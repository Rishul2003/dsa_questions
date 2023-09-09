#include<bits/stdc++.h>
using namespace std;
int energy_min(int n,int h[],vector<int>&dp){
    if(n==0){
        dp[n]=0;
        return dp[n];
    }
    if(n==1){
        dp[n]=abs(h[n]-h[n-1]);
        return dp[n];
    }
    int left=abs(h[n]-h[n-1]);
    int right=abs(h[n]-h[n-2]);
    if(dp[n-1]!=-1){
        left=left+dp[n-1];
    }else{
        left=left+energy_min(n-1,h,dp);
    }
    if(dp[n-2]!=-1){
        right=right+dp[n-2];
    }
    else{
        right=right+energy_min(n-2,h,dp);
    }
    dp[n]=min(left,right);
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    int h[n+1];
    vector<int>dp(n+1,-1);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    cout<<energy_min(n-1,h,dp)<<endl;
    return 0;
}