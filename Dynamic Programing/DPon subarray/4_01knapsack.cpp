#include<bits/stdc++.h>
using namespace std;
int f(int ind,int wt,vector<int>a,vector<int>val,vector<vector<int>>dp){
    if(ind==0){
        if(a[0]<=wt){
            return val[0];
        }
        return 0;
    }
    if(dp[ind][wt]!=-1){
        return dp[ind][wt];
    }
    int nottake=f(ind-1,wt,a,val,dp);
    int take=0;
    if(a[ind]<=wt){
        take=a[ind]+f(ind-1,wt-a[ind],a,val,dp);
    }
    return dp[ind][wt]= max(take,nottake);
}
int main(){
    int n;
    cin>>n;
    int wt;
    cin>>wt;
    vector<int> weight; vector<int> value; int n; int maxWeight;
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
	for(int i=weight[0];i<=maxWeight;i++){
		dp[0][i]=value[0];
	}
	for(int i=1;i<n;i++){
		for(int w=0;w<=maxWeight;w++){
			int nottake=dp[i-1][w];
			int take=0;
			if(weight[i]<=w){
				take=value[i]+dp[i-1][w-weight[i]];
			}
			dp[i][w]=max(take,nottake);
		}
	}
	return dp[n-1][maxWeight];
    return 0;
}