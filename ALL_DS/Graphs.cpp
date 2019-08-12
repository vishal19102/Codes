#include<iostream>
#include<vector>
#define vtList vector<int >
using namespace std;
void adjacencyMatrix(int **edges, int v,int E){

     for(int i=0;i<v;i++)
        {
            edges[i]=new int[v];
            for(int j=0;j<v;j++)
                    edges[i][j]=0;
        }   
        for(int i=0;i<E;i++)
                {
                    int u,v;
                    cin>>u>>v;
                    edges[u][v]=1;
                    edges[v][u]=1;
                }

}
void printMatrix(int **edges,int v){

for(int k=0;k<v;k++){
        for(int j=0;j<v;j++)
            cout<<edges[k][j]<<" ";
        
        cout<<endl;
    }

}
void adjacencyList(vtList vec[],int E){

    for(int i=0;i<E;i++)
        {   
            int u,v;
            cin>>u>>v;
            vec[u].push_back(v);
        }
    return ;
}
void printList(vtList vec[],int v){

    for(int i=0;i<v;i++){
        cout<<"Adjacency List of "<<i<<" is  head->";
            for(int k=0;k<vec[i].size();k++)
                cout<<vec[i][k]<<"->";
    cout<<endl;
    }
}
int main(){

     int v;
     int E;
     cin>>v>>E;
     int **edges= new int *[v];
        adjacencyMatrix(edges,v,E);
        printMatrix(edges,v);
        vtList vect[v];
        adjacencyList(vect,E);
        printList(vect,v);    

    return 0;
}