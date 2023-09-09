#include<bits/stdc++.h>
using namespace std;
int cal(int i,int j,vector<vector<int>>dp){
    if(i==0 && j==0){
        dp[i][j]=1;
        return dp[i][j];
    }
    if(i<0||j<0){
        return -1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=cal(i-1,j,dp);
    int left=cal(i,j-1,dp);
    dp[i][j]=up+left;
    return dp[i][j];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    
    //tabulation

    vector<vector<int>>dp(n,vector<int>(m));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i-1)>=0){
                dp[i][j]=dp[i][j]+dp[i-1][j];
            }
            if((j-1)>=0){
                dp[i][j]=dp[i][j]+dp[i][j-1];
            }
        }
    }
    cout<<dp[n-1][m-1]<<endl;

    //space optimize

    vector<int> dp2(n,0);
    for(int i=0;i<n;i++){
    vector<int> tem(n);
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                tem[j]=1;
            }
            if((i-1)>=0){
                tem[j]=tem[j]+dp2[j];

            }
            if((j-1)>=0){
                tem[j]=tem[j]+tem[j-1];
            }
        }
        dp2=tem;
    }
    return 0;
}