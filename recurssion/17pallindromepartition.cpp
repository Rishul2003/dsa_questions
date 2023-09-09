#include<bits/stdc++.h>
using namespace std;
bool pallindrome(string &a,int index,int i){
    for(int j=index,k=i;j<=k;j++,k--){
        if(a[j]!=a[k]){
            return false;
        }
    }
    return true;
}
void partition(vector<vector<string>>&v,string &a,vector<string> &ans,int ind,int n){
    if(ind==n){
        v.push_back(ans);
        return;
    }
    for(int i=ind;i<n;i++){
        if(pallindrome(a,ind,i)){
            ans.push_back(a.substr(ind,i-ind+1));
            partition(v,a,ans,i+1,n);
            ans.pop_back();
        }
    }
    return;
}
int main(){
    
    string a="aabb";
    vector<string>ans;
    vector<vector<string>>v;
    int n=4;
    int ind=0;
    partition(v,a,ans,ind,n);
    for(auto i:v){
        for(auto j :i){
            cout<<j;
        }
        cout<<endl;
    }

    return 0;

}