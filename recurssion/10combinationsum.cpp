#include<bits/stdc++.h>
using namespace std;
int fucnt(vector<int>&v,int ind,vector<int>&ds,int target,int ans){
    if(target==0){
        for(int i=0;i<ds.size();i++){
            cout<<ds[i]<<" ";
        }
        cout<<endl;
        ans++;
        return ans;
    }
    for(int i=ind;i< v.size();i++){
        if(i>ind && v[i]==v[i-1]){
            continue;
        }
        if(v[i]>target){
            break;
        }
        ds.push_back(v[i]);
        int k=fucnt(v,i+1,ds,target-v[i],ans);
        // cout<<" k "<<k<<endl;
        ds.pop_back();
        ans=k;

    }
    return ans;

}
int main(){
    
    vector<int>v={1,1,1,2,2};
    vector<int>ds;

    int target=4;
    cout<<fucnt(v,0,ds,target,0)<<endl;
    
    return 0;

}