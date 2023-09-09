#include<bits/stdc++.h>
using namespace std;
void funct(vector<int>&v,int ind){
    if(ind==v.size()){
        for(auto i :v){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=ind;i<v.size();i++){
        swap(v[i],v[ind]);
        // ds.push_back(v[i]);
        funct(v,ind+1);
        swap(v[i],v[ind]);

        // ds.pop_back();
        // swap(v[i],v[ind]);
    }
}
int main(){
    vector<int>v={1,2,3};
    vector<int>ds;
    funct(v,0);
    return 0;
}