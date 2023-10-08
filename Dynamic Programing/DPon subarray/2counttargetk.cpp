#include<bits/stdc++.h>
using namespace std;
int countsubset(int ind ,int s,vector<int>&a,vector<vector<int>>dp){
    if(ind==0){
        if(a[0]==s){
            if(s==0 && a[0]==0){
                return 2;

            }
            else if(s==0 || a[0]==s){
                return 1;

            }
            else{
                return 0;

            }
        }
        else{
            return 0;
        }
    }
    if(dp[ind][s]!=-1){
        return dp[ind][s];
    }
    int notpick=countsubset(ind-1,s,a,dp);
    int pick=0;
    if(a[ind]<=s){
        pick=countsubset(ind-1,s-a[ind],a,dp);
    }
    return dp[ind][s]=pick+notpick;
}
int main(){
    vector<vector<int>>dp;
    vector<int>a;
    int n;int s;
    cin>>n;
    //tabulation
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    if(a[0]==s){
    dp[0][s]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<s;j++){
            int nottake=dp[i-1][j];
            int take=0;
            if(a[i]<=j){
                take=dp[i-1][j-a[i]];
            }
            dp[i][j]=take+nottake;
        }

    }
    cout<<dp[n-1][s]<<endl;
    return 0;
}