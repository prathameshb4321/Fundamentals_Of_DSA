#include<iostream>
using namespace std;
int Q[40];
int f=-1;
int r=-1;


void enq(int data)
{
  r++;
  Q[r]=data;

}
int dq()
{
  int p;
  f++;
  p=Q[f];

  return p;
}

int isempty()
{
    if(f == r)
        return 1;
    else
        return 0;
}

 void BFS(int AV[100],int G[100][100],int start, int n )
 {
   int v;
   AV[start]=1;
   enq(start);
   while(!isempty())
   {
     v=dq();
     cout<<v<<" ";
     for(int i=0;i<n;i++)
     {
        if(G[v][i]==1 && AV[i]==0)
        {
            enq(i);
            AV[i]=1;
        }
     }
   }

 }

void DFS(int AV[100],int G[100][100],int start, int n)
{
    cout<<start<<" ";
    AV[start]=1;
    for(int i=0;i<n;i++)
    {
        if(G[start][i]==1 && AV[i]==0)
        {
            DFS(AV,G,i,n);
        }
    }
}


int main()
{
  int n,e,AV[100];
  int G[100][100];
  cout<<"Enter the no of nodes and edges";
  cin>>n>>e;

  for(int i=0;i<n;i++)
        AV[i]=0;

  for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
              G[i][j]=0;





  int p,q;
  cout<<"enter the nodes in between them edge is there";
  for(int i=0;i<e;i++)
  {  cin>>p>>q;
     G[p][q]=1;
     G[q][p]=1;
  }



  int start;
  cout<<"enter from which node you want to start";
  cin>>start;

  int ch;


  do
  {
      cout<<"\nEnter your choice";
      cout<<"\n1.BFS";
      cout<<"\n2.DFS";
      cin>>ch;
      switch(ch)
      {
      case 1:
           cout<<"BFS is : \t";
           BFS(AV,G,start,n);
           break;
      case 2:
          for(int i=0;i<n;i++)
                   AV[i]=0;
          cout<<"\n DFS is :\t";
          DFS(AV,G,start,n);
          break;
      default:
        cout<<"Enter valid choice";



      }
  }while(ch>0);
}
