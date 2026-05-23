#include<iostream>
#include<algorithm>
using namespace std;

struct Edge{
   int n,v,weight;
 };
 Edge edge[20];

 bool compare(struct Edge i,struct Edge j )
  {
    return i.weight<j.weight;
  }

void prims(int v,int N,int visit[20],int G[20][20])
{
    int sum=0,p,temp,Min,m,n;
     visit[v]=1;
    for(int k=0;k<N-1;k++)
    {    temp=999;
        for(int i=0;i<N;i++)
        {
           if(visit[i]==1)
           { Min=999;
            for(int j=0;j<N;j++)
             {
               if(G[i][j]!=0 )
               {
                 if(Min>=G[i][j] && visit[j]==0)
                 {
                     Min=G[i][j];
                     p=j;
                 }

               }
             }
             if(Min<temp)
             {
                 temp=Min;
                 m=i;
                 n=p;
             }

           }
        }
        sum=sum+G[m][n];
        cout<<"selected edge bw "<<m<<" to "<<n<<" is :"<<G[m][n]<<"\n";
        visit[m]=1;
        visit[n]=1;
    }
    cout<<"\nTotal min wgt is: "<<sum;
}


void kruskal(int N,int E)
{ int  mst_edges=0,
        mst_cost=0;
        int visited[N];
        for(int i=0;i<N;i++)
        {
            visited[i]=0;
        }
     for(int j=0;j<E;j++)
     { int n=edge[j].n;
       int v=edge[j].v;
       int weight=edge[j].weight;

       if(visited[n]==0 || visited[v]==0)
       { mst_cost +=weight;
         visited[n]=1;
         visited[v]=1;
         cout<<"\n"<<n<<" - "<<v<<" "<<weight<<"\n";
         mst_edges++;
       }
       if(mst_edges==N-1){
        break;
       }


     }
     cout<<"\nTotal weight of mst"<<mst_cost;

}

int main()
{
   int N,E;
   cout<<"\nEnter the no of nodes/vertices  and edges";
   cin>>N>>E;
   int visit[20],G[20][20] ;



   int ch,v;
   do{
    cout<<"\nEnter your choice:\n";
    cout<<"1.traversal using \"prims\" \n";
    cout<<"2.traversal using \"Kruskal\" \n";
    cin>>ch;

    switch(ch)
    {
  case 1:
   for(int i=0;i<N;i++)
   { visit[i]=0;
   }
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

    cout<<"Enter from node you want to start";
    cin>>v;
    prims(v,N,visit,G);
    break;

  case 2:

      cout<<"Enter the nodes in B/W edge is present with weight(n,v,weight)\n";
      for(int i=0;i<E;i++)
      { cout<<"enter node in b/w edge is there ";
        cin>>edge[i].n;
        cin>>edge[i].v;
        cout<<"Enter the weight";
        cin>>edge[i].weight;

      }
      sort(edge,edge+E,compare);

      for(int i=0;i<E;i++)
      {
        cout<<edge[i].n<<" "<<edge[i].v<<" "<<edge[i].weight<<endl;
      }
      kruskal(N,E);


      break;
  case 3:


      break;
  default:
     break;
    }
   } while(ch>0);





}
