#include<bits/stdc++.h>
using namespace std;
int funct(vector<int>&v,int low,int high){
    int pivot=v[low];
    int i=low,j=high;
    while(i<j){
        while(v[i]<=pivot && i<=high-1){
            i++;
        }
        while(v[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(v[i],v[j]);
        }
    }
    swap(v[j],v[low]);
    return j;
}
void quicsort(vector<int>&v,int low,int high){
    if(low<high){
        int part=funct(v,low,high);
        quicsort(v,low,part-1);
        quicsort(v,part+1,high);
    }
}
int main(){
    vector<int>v={5,4,2,1,2,4};
    int n=v.size();
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<n<<endl;
    quicsort(v,0,n-1);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}