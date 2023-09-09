#include<bits/stdc++.h>
using namespace std;
void funct(vector<int>& candidates,int target,vector<vector<int>>&ans,vector<int>&v,int ind){
      if(ind==v.size()){
        if(target==0){
          ans.push_back(v);
          cout<<"HI"<<endl;
        }
        return;
      }
      if((candidates[ind])<=(target)){
        v.push_back(candidates[ind]);
        funct(candidates,target-candidates[ind],ans,v,ind);
        v.pop_back();
      }
      funct(candidates,target,ans,v,ind+1);
    }
int main(){
    vector<int>candidates={2,3,6,7};
    int target=7;
    vector<vector<int>>ans;
       vector<int>v;
       funct(candidates,target,ans,v,0);
       for(auto i :ans){
        for(auto j :i){
            cout<<j<<" ";
        }
        cout<<endl;
       }
    return 0;
}