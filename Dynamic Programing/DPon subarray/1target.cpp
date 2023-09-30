#include<bits/stdc++.h>
using namespace std;
bool subsetsumk(int ind,int target,vector<int>a,vector<vector<int>>&dp){
    if(target==0){
        dp[ind][target]=1;
        return true;
    }
    if(ind==0){
        if(a[0]==target){
            dp[ind][a[0]]=1;
            return true;
        }
        else{
            dp[ind][target]=0;
            return false;
        }
    }
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    bool nottake=subsetsumk(ind-1,target,a,dp);
    bool take=false;
    if(a[ind]<=target){
    take=subsetsumk(ind-1,target-a[ind],a,dp);
    }
    dp[ind][target]=take||nottake;
    return take||nottake;
}
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int>a;
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        a.push_back(v);
    }
    vector<vector<int>>dp(n,vector<int>(target,-1));
    //Tabulation

    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    dp[0][a[0]]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<target;j++){
            bool nottake=dp[i-1][target];
            bool take=false;
            if(a[i]<=target){
                take=dp[i-1][target-a[i]];
            }
            dp[i][target]=take||nottake;
        }
    }


    //space optimize
    vector<int>prev(target,0);
    vector<int>curr(target,0);
    curr[0]=true;
    prev[0]=1;
    prev[a[0]]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<target;j++){
            bool nottake=prev[target];
            bool take=false;
            if(a[i]<=target){
                take=prev[target-a[i]];
            }
            curr[j]=take|nottake;
        }
    }
    prev=curr;

}