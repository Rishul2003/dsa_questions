#include<bits/stdc++.h>
using namespace std;
bool printsumk(int a[],int i,int n,vector<int>&v,int sum,int k){
    if(i==n){
        if(sum==k){

            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
            return true;
        }
        return false;
    }
    v.push_back(a[i]);
    sum=sum+a[i];
    if(printsumk(a,i+1,n,v,sum,k)){
        return true;
    }
    v.pop_back();
    sum=sum-a[i];
    
    if(printsumk(a,i+1,n,v,sum,k)){
        return true;
    }
    return false;
}
int main(){
    int a[5]={1,1,2,1,3};
    int n=5;
    vector<int>v;

    int sum=0;
    printsumk(a,0,n,v,sum,3);
    return 0;
}