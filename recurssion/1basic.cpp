#include<bits/stdc++.h>
using namespace std;
void functbacktrack(int i,int n){
    if(i<1){
        return;
    }
    functbacktrack(i-1,n);
    cout<<i<<endl;
}
void funct(string name,int i){
    if(i>5){
        return;
    }
    funct(name,i+1);
    cout<<i<<endl;
}
int main(){
    funct(":RISHUL",1);
    functbacktrack(4,4);
    return 0;
}