#include<bits/stdc++.h>
using namespace std;
int maxsubs(int ind,vector<int>&dp,int a[]){
    // cout<<ind<<endl;
    if(ind==0){
        dp[ind]=a[ind];
        return a[ind];

    }
    if(ind<0){
        return 0;
    }if(dp[ind]!=-1){
        return dp[ind];
    }
    int pick=a[ind]+maxsubs(ind-2,dp,a);
    int notpic=maxsubs(ind-1,dp,a);
    dp[ind]=max(notpic,pick);
    return dp[ind];
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>dp(n+1,-1);
    cout<<maxsubs(n,dp,a)<<endl;
    vector<int>dp2(n+1);
    dp2[0]=a[0];

    for(int i=1;i<n;i++){
        int left=INT16_MIN;
        if(i>=2){
            left=a[i]+dp[i-2];
        }
        int right=0+dp[i-1];
        dp[i]=max(left,right);
    }

    cout<<dp[n-1]<<endl;
    return 0;
}