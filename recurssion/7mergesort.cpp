#include<bits/stdc++.h>
using namespace std;
void mergesort(int a[],int low,int high){
    if(low==high){
        return;
    }
    int mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);

    int i=0;
    int j=mid+1;
    int k=0;
    vector<int>v;
    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            v[k++]=a[i++];
        }
        else{
            v[k++]=a[j++];
        }
    }
    while(i<=mid){
        v[k++]=a[i++];
    }
    while(j<=high){
        v[k++]=a[j++];
    }
    


}
int main(){
    int a[5]{10,5,6,8,1};
}