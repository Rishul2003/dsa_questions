#include<bits/stdc++.h>
using namespace std;
int fibn(int n,vector<int>&dp){
    if(n<=1){
        dp[n]=n;
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=fibn(n-1,dp)+fibn(n-2,dp);
}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<fibn(n,dp)<<endl;


    //Tabulation
    vector<int>dp1(n+1);
    dp1[1]=0;
    dp1[2]=1;
    for(int i=3;i<=n;i++){
        dp1[i]=dp1[i-1]+dp1[i-2];
    }
    cout<<dp1[n]<<endl;



    // without space

    int prev1=0;
    int prev2=1;
    for(int i=2;i<=n;i++){
        int k=prev1+prev2;
        prev2=prev1;
        prev1=k;

    }
    cout<<prev1+prev2<<endl;
    return 0;
}