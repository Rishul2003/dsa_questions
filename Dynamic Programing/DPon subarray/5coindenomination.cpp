#include<bits/stdc++.h>
using namespace std;
int f(int ind,int t,vector<int>a,vector<vector<int>>&dp){
    if(ind==0){
        if(t%a[ind]==0){
            return (t/a[ind]);
        }
        return INT32_MAX;
    }
    if(dp[ind][t]!=-1){
        return dp[ind][t];
    }
    int nottake=0+f(ind-1,t,a,dp);
    int take=INT32_MAX;
    if(a[ind]<=t){
        take=1+f(ind,t-a[ind],a,dp);
    }
    dp[ind][t]=min(take,nottake);
    return  min(take,nottake);
}
int main(){
    int n,t;
    cin>>n>>t;
    vector<int>a;
    vector<vector<int>>dp(n,vector<int>(t+1,1e9));
    //tabulation
    for(int i=0;i<=t;i++){
        if(i%a[0]==0){
            dp[0][i]=i/a[0];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=t;j++){
            if(j==0){
                dp[i][j]=0;
            }
            int nottake=dp[i-1][j];
            int take=INT16_MAX;
            if(a[i]<=j){
                take=1+dp[i][j-a[i]];
            }
            dp[i][j]=min(take,nottake);
        }
    }
    return dp[n-1][t];

}
