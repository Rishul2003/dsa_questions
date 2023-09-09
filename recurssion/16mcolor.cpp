#include<bits/stdc++.h>
using namespace std;
bool possible(int col[],vector<vector<int>>&v,int node,int color){
    cout<<"Possible "<<color<<" "<<node<<endl; 
    for(int j :v[node]){
        cout<<j<<endl;
        if(col[j]==color){
            return false;    
        }
    }
    return true;
}
bool coloring(int col[],int n,int m,int i,vector<vector<int>>&v){
    if(i==n){
        return true;
    }
    cout<<"i "<<i<<endl;
    for(int j=1;j<=m;j++){
        if(possible(col,v,i,j)){
            cout<<"colouring "<<i<<"  "<<j<<endl;
            col[i]=j;
            if(coloring(col,n,m,i+1,v)){
                return true;
            }
            col[i]=0;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int m=3;
    int col[n+1]={0};
    vector<vector<int>>v(n);
    v[0].push_back(2);
    v[0].push_back(3);
    v[0].push_back(1);
    v[1].push_back(0);
    v[1].push_back(2);
    v[1].push_back(3);
    v[2].push_back(1);
    v[2].push_back(0);
    v[3].push_back(0);
    v[3].push_back(1);
    // for(int i=0;i<v.size();i++){
    //     cout<<i<<endl;
    //     for(int j=0;j<v[i].size();j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<coloring(col,n,m,0,v)<<endl;
    for(int i=0;i<n;i++){
        cout<<col[i]<<endl;
    }

}