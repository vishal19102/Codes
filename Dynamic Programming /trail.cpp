#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,l;
    cin>>t;
    int i=0;
    string s[t];
    l=t;
    while(l--)
   { 
          
        getline(cin,s[i]);
        i++;
    }
    for(int k=0;k<t;k++)
        cout<<s[i].size()<<endl;
}


