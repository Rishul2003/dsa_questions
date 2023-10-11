#include<bits/stdc++.h>
using namespace std;
int f(int ind,int length,vector<int>price,vector<vector<int>>&dp){
    if(ind==0){
        return (price[ind]*length);
    }
    if(dp[ind][length]!=-1){
        return dp[ind][length];
    }
    int nottake=f(ind-1,length,price,dp);
    int take=0;
    if(length>=(ind+1)){
        take=price[ind]+f(ind,length,price,dp);
    }
    dp[ind][length]=max(take,nottake);
    return max(nottake,take);

}
int main(){
    
    return 0;
}