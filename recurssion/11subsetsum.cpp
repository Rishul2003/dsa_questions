#include<bits/stdc++.h>
using namespace std;
void funct(vector<int>&v,int ind,int sum,set<int>&s){
    if(ind==v.size()){
      s.insert(sum);  
      return;
    }
    funct(v,ind+1,sum+v[ind],s);
    funct(v,ind+1,sum,s);
}
int main(){
    vector<int>v={3,1,2};
    set<int>s;
    int sum=0;   
    funct(v,0,sum,s);
    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;
    
}