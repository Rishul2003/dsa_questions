#include<bits/stdc++.h>
using namespace std;
void funct(vector<int>&v,unordered_map<int,int>&m,vector<int>&ds){
    if(ds.size()==v.size()){
        for(auto i:ds){
            cout<<i<<" ";
        }
        cout<<endl;
    }    
    for(int i=0;i<v.size();i++){
        if(m[v[i]]==0){
            m[v[i]]=1;
            ds.push_back(v[i]);
            funct(v,m,ds);
            ds.pop_back();
            m[v[i]]=0;
        }
    }
}
int main(){
    unordered_map<int,int>m;
    vector<int>v={1,2,3};
    vector<int>ds;
    funct(v,m,ds);
    return 0;
}