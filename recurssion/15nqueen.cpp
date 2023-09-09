#include<bits/stdc++.h>
using namespace std;
bool issafe(int row,int colu,vector<string>&v,int n){
    int r1=row,c1=colu;
    while(c1>=0){
        if(v[row][c1]=='Q'){
            return false;
        }
        c1--;
    }
    r1=row;c1=colu;
    while(r1>=0 &&c1>=0){
        if(v[r1][c1]=='Q'){
            return false;
        }
        r1--;
        c1--;
    }
    r1=row;c1=colu;
    while(r1<n && c1>=0){
        if(v[r1][c1]=='Q'){
            return false;
        }
        r1++;
        c1--;
    }
    return true;

}
int nnqueen(vector<string>&v,vector<vector<string>>&a,int n,int ind,int ans){
    if(ind==n){
        
        a.push_back(v);
        for(int i=0;i<n;i++){
            cout<<v[i]<<endl;
        }
        cout<<endl;
        ans++;
    }
    for(int i=0;i<n;i++){
        if(issafe(i,ind,v,n)){
            v[i][ind]='Q';
            ans=nnqueen(v,a,n,ind+1,ans);
            v[i][ind]='.';
        }
    }
    return ans;
}
void nqueen(vector<string>&v,vector<vector<string>>&a,int n,int ind){
    if(ind==n){
        
        a.push_back(v);
        // for(int i=0;i<n;i++){
        //     cout<<v[i]<<endl;
        // }
        // cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(issafe(i,ind,v,n)){
            v[i][ind]='Q';
            nqueen(v,a,n,ind+1);
            v[i][ind]='.';
        }
    }
    return;
}
int main(){
    vector<vector<string>>a;
    int n;
    cin>>n;
    string s(n,'.');
    cout<<s<<endl;
    vector<string>v(n);
    for(int i=0;i<n;i++){
        v[i]=s;
    }
    cout<<nnqueen(v,a,n,0,0)<<endl;
    
    return 0;
}