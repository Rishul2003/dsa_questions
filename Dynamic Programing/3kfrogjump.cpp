#include<bits/stdc++.h>
using namespace std;
int energy(int h[],int n,vector<int>&dp,int k){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int min1=INT32_MAX;
    for(int i=1;i<=k;i++){
        if((n-i)>=0){
        int k=abs(h[n]+h[n-i])+energy(h,n-i,dp,k);
        }
        else{
            break;
        }
        min1=min(k,min1);
    }
    dp[n]=min1;
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
    vector<int>dp[n+1];
    //space optimized solution

    int k;
    cin>>k;
    list<int>l;
    int count=0;
    l.push_front(0);
    for(int i=1;i<n;i++){
        int minstep=INT16_MAX;
        int j=j+count;
        for(int i:l){
            int k=abs(h[i]-h[i-j])+i;
            
            j++;
            minstep=min(k,minstep);
        }
        l.push_front(minstep);
        if(l.size()>=k){
            l.pop_back();
            count++;
        }
    }



    return 0;
}