#include<bits/stdc++.h>
using namespace std;
void funct(int a[],int b[],int n,int i,int j){
    if(i>=n){
        for(int p=0;p<j;p++){
            cout<<b[p]<<" ";
        }
        cout<<endl;
        return;
    }
    b[j]=a[i];
    funct(a,b,n,i+1,j+1);
    funct(a,b,n,i+1,j);

}
int main(){
    int a[]={1,2,3};
    int b[5];
    funct(a,b,3,0,0);
    return 0;
}