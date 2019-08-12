#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int diffEncoding(int *arr,int size,int *dp){

    if(size==1||size==0)    
        return 1;
    
    if(dp[size]!=0)
        return dp[size];

    int option1= diffEncoding(arr,size-1,dp);
    int option2=0;
    if(arr[size-2]*10 + arr[size-1]<=26)    
        option2= diffEncoding(arr,size-2,dp);

    int ans = option1+option2 ;

    dp[size]=ans;

    return dp[size]%MOD;
}
int main(){

    int n;
    cin>>n;

    int *arr= new int[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int *dp = new int[n];
    for(int i=0;i<=n;i++)
        dp[i]=0;

    int ans = diffEncoding(arr,n,dp);
    
    cout<<ans<<endl;

    delete[] arr;

    return 0;

}