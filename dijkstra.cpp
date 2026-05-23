#include<iostream>
using namespace std;

#define max 999


int choose(int dist[],int visited[],int N)
{
  int mi_n=max,min_index;

  for(int i=0;i<N;i++)
  {
      if(dist[i]<mi_n && visited[i]==0)
      {
        mi_n=dist[i];
        min_index=i;
      }
  }
  return min_index;
}

int dijkstra(int G[30][30],int src,int N)
{
  int dist[N],visited[N];

  for(int i=0;i<N;i++)
  {
     visited[i]=0;
     dist[i]=max;

  }

  dist[src]=0;

  for(int cnt=0; cnt<N-1;cnt++)
  {
    int u=choose(dist,visited,N);

    visited[u]=1;

      for(int v=0;v<N;v++)
      {
          if(visited[v]==0 &&G[u][v]!=0 && dist[u]+G[u][v]<dist[v] ){

            dist[v]=dist[u]+G[u][v];

        }
      }
  }

  cout<<"shortest  distance from  source \n ";
  for(int i=0;i<N;i++)
  {
      cout<<dist[i]<<" ";
  }

}




int main()
{
  int N,E;
   cout<<"\nEnter the no of nodes/vertices  and edges";
   cin>>N>>E;

  int visit[30],G[30][30] ;

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        G[i][j]=0;
      }
    }

      int a,b,wgt;
  // cout<<"enter the nodes in between edges are present";
   for(int k=0;k<E ;k++)
   { cout<<"enter nodes in between edge is there";
     cin>>a>>b;
     cout<<"Enter the cost of that node";
     cin>>wgt;
     G[a][b]=wgt;
     G[b][a]=wgt;
   }
   for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        cout<<G[i][j]<<" ";
    }cout<<"\n";
   }
    int v;
    cout<<"Enter from node you want to start";
    cin>>v;

    dijkstra(G,v,N);



}
