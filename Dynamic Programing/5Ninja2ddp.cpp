#include<bits/stdc++.h>
using namespace std;
int f(int day,int ind,vector<vector<int>>&v,vector<vector<int>>&dp){
    if(day==0){
        int m1=0;
        for(int i=0;i<v[day].size();i++){
            if(i!=ind){
                m1=max(m1,v[day][i]);
            }

        }
        dp[day][ind]=m1;
        return dp[day][ind];
    }
    if(dp[day][ind]!=-1){
        return dp[day][ind];
    }
    int m1=0;
    for(int i=0;i<v[day].size();i++){
        if(i!=ind){
            int k=v[day][i]+f(day-1,i,v,dp);

            m1=max(m1,k);
        }
    }
    dp[day][ind]=m1;
    return dp[day][ind];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>v(n);
   vector<vector<int>>dp(n,vector<int>(4,-1));
    //TABULATION


    //base case
    vector<vector<int>>dp1(n,vector<int>(4,0));
    for(int i=0;i<v[0].size();i++){
        int maxi=0;
        for(int j=0;j<v[0].size();j++){
            if(i!=j){
                maxi=max(v[0][j],maxi);
            }
        }
        dp[0][i]=maxi;
    }
    for(int day=1;day<n;day++){
        for(int last=0;last<v[day].size();last++){
            dp[day][last]=0;
            int max1=0;
            for(int i=0;i<v[day].size();i++){
                if(i!=last){
                    max1=max(max1,dp[day-1][i]);
                }
            }
            dp[day][last]=max1;
        }
    }
    //space optimize

    vector<int>dp3(4);
    //base case
    for(int i=0;i<=v[0].size();i++){
        int maxi=0;
        for(int j=0;j<v[0].size();j++){
            if(i!=j){
                maxi=max(v[0][j],maxi);
            }
        }
        dp3[i]=maxi;
    }
    for(int day=1;day<n;day++){
        vector<int>temp(n);
        for(int last=0;last<=3;last++){
            temp[last]=0;
            int max1=0;
            for(int i=0;i<v[day].size();i++){
                if(i!=last){
                    max1=max(max1,dp3[i]);
                }
            }
            temp[last]=max1;
        }
        dp3=temp;
    }
    
    return 0;
}