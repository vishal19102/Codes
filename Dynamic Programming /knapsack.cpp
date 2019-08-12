#include<bits/stdc++.h>

using namespace std;

int maxValue(int *val,int *weig,int maxCap,int n){
    int ans=0;
    int option1=0;
    if(n==0)
        return  0;

    if(maxCap<=0)
        return 0;
    if(weig[0]<maxCap){
    option1=val[n-1]+maxValue(val,weig,maxCap-weig[0],n-1);
    }

    int option2 =maxValue(val,weig,maxCap,n-1);

    ans=max(option1,option2);

    return ans;
}

int main(){

    int val[]={60,100,120};
    int weight[]={10,20,30};
    int kna=50;
    int n=3;
    int result = maxValue(val,weight,kna,n);
    cout<<result<<endl;
}
