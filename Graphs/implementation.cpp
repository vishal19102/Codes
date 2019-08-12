#include<bits/stdc++.h>

using namespace std;

int main(){

    int v,E;
    cin>>v>>E;
    int **edges=new int*[v];
    for(int i=0;i<v;i++)
        edges[i]=new int[v];
        for(int j=0;j<E;j++)
            {
                int u,v;
                cin>>u>>v;
                edges[u][v]=1;
                edges[v][u]=1;
            }

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)
            cout<<edges[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}



