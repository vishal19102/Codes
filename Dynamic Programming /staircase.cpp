#include<bits/stdc++.h>

using namespace std;

int noOfways(int n){
    int ans=0;

    if (n == 1 || n == 0)  
        return 1; 
    else if (n == 2)  
        return 2; 
    
    int option1=noOfways(n-1);
    int option2=noOfways(n-2);
    int option3=noOfways(n-3);
    
    ans= option1+option2+option3;

    return ans;
}
int noOfwaysDP(int n,int *dp){

    int ans;
    
    if(dp[n]!=-1)
        return dp[n];

    if (n == 1 || n == 0)  
        return 1; 
    else if (n == 2)  
        return 2; 
    
    
    int option1=noOfwaysDP(n-1,dp);
    int option2=noOfwaysDP(n-2,dp);
    int option3=noOfwaysDP(n-3,dp);
    
    ans= option1+option2+option3;

    dp[n]=ans;

    return dp[n];
}
int main(){

    int n;
    cin>>n;
    
    int *p= new int[n];
   
    for(int i=0;i<=n;i++)
        p[i]=-1;

    //int ans= noOfways(n);
    int ans2= noOfwaysDP(n,p);

     cout<<ans2<<endl;
    return 0;
}