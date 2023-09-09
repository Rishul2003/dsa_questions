#include<bits/stdc++.h>
using namespace std;
// int ans=0;
int sum(vector<int>&v,int ind,int target,vector<int>&ds,int ans){
    if(ind==v.size()){
        if(target==0){
            for(int i=0;i<ds.size();i++){
                cout<<ds[i]<<" ";
            }
            cout<<endl;
            ans++;
            return ans;
        }
        return 0;
    }
    int a1=0;
    if(v[ind]<=target){
        ds.push_back(v[ind]);
        a1=sum(v,ind,target-v[ind],ds,ans);
        ds.pop_back();
    }
    int a2=sum(v,ind+1,target,ds,ans);
    return a1+a2;
}
int main(){
    vector<int>v={2,3,6,7};
    int target=7;
    vector<int>ds;
    cout<<sum(v,0,target,ds,0)<<endl;

}