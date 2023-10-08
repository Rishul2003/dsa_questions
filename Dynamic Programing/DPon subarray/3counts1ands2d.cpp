#include<bits/stdc++.h>
using namespace std;
int countsubset(int ind ,int target,vector<int>a){
    
    if(ind==0){
        if(target==0 && a[ind]==0){
            return 2;
        }
        else if(target==0|| a[0]==target){
            return 1;
        }
        else{
            return 0;
        }
    }
    int nottake=countsubset(ind-1,target,a);
    int take=0;
    if(a[ind]<=target){
        take=countsubset(ind-1,target-a[ind],a);
    }
    return take+nottake;
}
int main(){
    int n;
    cin>>n;
    int d;
    cin>>d;
    vector<int>a(n);
    int su=0;
    for(int i=0;i<n;i++){
        su=su+a[i];
    }
    int target=su-d;
    target=target/2;
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    if(a[0]==0){
        dp[0][0]=2;

    }
    else{
        dp[0][0]=1;

    }
    if(a[0]!=0 && a[0]==target){
        dp[0][a[0]]=1;

    }
    for(int i=1;i<n;i++){
        for(int s=0;s<=target;s++){
            int nottake=dp[i-1][s];
            int take=0;
            if(a[i]<=s){
                take=dp[i-1][s-a[i]];
            }
            dp[i][s]= take+nottake;
        }
    }
    
    return 0;
}