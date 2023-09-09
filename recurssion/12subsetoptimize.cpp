#include<bits/stdc++.h>
using namespace std;
void funct(vector<int>&v,int ind,vector<int>&v1,vector<vector<int>>&v2){
    v2.push_back(v1);
    // cout<<"IND "<<ind<<endl;
    for(int i=ind ;i<v.size();i++){
        // cout<<i<<" "<<v[i]<<" HELLO"<<endl;
        if(i!=ind && v[i]==v[i-1]) continue;
        // cout<<i<<" "<<v[i]<<" BYE"<<endl;
        v1.push_back(v[i]);
        funct(v,i+1,v1,v2);
        v1.pop_back();
    }
    return;
}
int main(){
    vector<int>v={1,1,2};
    int n=v.size(); 
    vector<int>v1;
    vector<vector<int>>v2;
    funct(v,0,v1,v2);
    for(auto i:v2){
        for(auto j :i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}