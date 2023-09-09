#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n){
     
}
bool pallindrome(string s,int i){
    if(i>=(s.size())/2){
        return true;
    }
    if(s[i]!=s[s.size()-i-1]){
        return false;
    }
    return pallindrome(s,i+1);
}
void reverse(int a[],int n,int l,int r){
    if(l>=r){
        return;
    }
    swap(a[l],a[r]);
    reverse(a,n,l+1,r-1);
}
int main(){
    int a[5]={1,2,3,4,5};
    reverse(a,5,0,4);
    for(int i=0;i<5;i++){
        cout<<a[i]<<endl;
    }
    cout<<pallindrome("abba",0)<<endl;
    cout<<pallindrome("abcd",0)<<endl;
    return 0;
}
