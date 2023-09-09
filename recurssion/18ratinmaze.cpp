#include<bits/stdc++.h>
using namespace std;
void move(string m[],int n,bool visit[][4],int row,int col, vector<char>&ans){
    if(row==n-1 && col==n-1){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    if(row+1<n &&visit[row+1][col]!=true && m[row+1][col]=='1'){
        visit[row][col]=true;
        ans.push_back('D');
        move(m,n,visit,row+1,col,ans);
        ans.pop_back();
        visit[row][col]=false;
    }
    if(row-1>=0 &&visit[row-1][col]!=true && m[row-1][col]=='1'){
        visit[row][col]=true;
        ans.push_back('L');
        move(m,n,visit,row-1,col,ans);
        ans.pop_back();
        visit[row][col]=false;
    }
    if(col+1<n &&visit[row][col+1]!=true && m[row][col+1]=='1'){
        visit[row][col]=true;
        ans.push_back('R');
        move(m,n,visit,row,col+1,ans);
        ans.pop_back();
        visit[row][col]=false;
    }
    if(col-1>=0 &&visit[row][col-1]!=true && m[row][col-1]=='1'){
        visit[row][col]=true;
        ans.push_back('U');
        move(m,n,visit,row,col-1,ans);
        ans.pop_back();
        visit[row][col]=false;
    }
    return;
}
int main(){
    string m[4]={
        "1000",
        "1101",
        "1100",
        "0111"
    };
    vector<char>ans;
    bool visit[4][4]={false};
    move(m,4,visit,0,0,ans);
    return 0;
}