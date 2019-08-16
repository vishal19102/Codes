#include<iostream>
#include<cstring>

using namespace std;


void dfs(int **edges,int i,int *visited,int v){

    if(visited[i]!=0)
        return ;
    cout<<i<<" ";
    visited[i]=1;

    for(int j=0;j<v;j++)
            if(edges[i][j])
                        dfs(edges,j,visited,v);
    return ;
}
int main(){

    int v,E;
    cin>>v>>E;
    int **edges= new int*[v];
    for(int i=0;i<v;i++){
        edges[i] = new int[v];
        for(int k=0;k<v;k++)
            edges[i][k]=0;
    }
    for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v ;
            edges[u][v]=1;
            edges[v][u]=1; 
        }
        int *visited = new int[v];
        memset(visited,0,sizeof(visited));
        dfs(edges,0,visited,v);

    return 0;
}