#include<iostream>
#include<stdlib.h>
using namespace std;

void dis(int m,int n,int **p)
{
 for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
     cout<< *(*(p+i)+j)<<" ";
    }
    cout<<"\n";
  }
}
void add(int m,int n,int **p,int **q,int **r)
{
for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
    *(*(r+i)+j)=*(*(p+i)+j) + *(*(q+i)+j)  ;
    }
    }

    }
void multi(int m,int n,int b,int **p,int **q,int **r)
{
for(int i=0;i<m;i++)
  {
      for(int j=0;j<b;j++)
      {  *(*(r+i)+j)=0 ;
       for(int k=0;k<n;k++ )
       {
             *(*(r+i)+j)=*(*(r+i)+j) + (*(*(p+i)+k) * *(*(q+k)+j))  ;

       }

      }
  }
}
void trans(int **p,int m,int n,int **r)
{
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
    *(*(r+i)+j)=*(*(p+j)+i) ;
    }
    }


}
int main()
{
  int m,n,**p,**r;
  cout<<"Enter no of rows and column you want.\n";
  cin>>m>>n;

  r=(int**)malloc(m*sizeof(int*));
   for( int i=0;i<m;i++)
  {
    r[i]= (int*)malloc(n*sizeof(int));
  }

  p=(int**)malloc(m*sizeof(int*));

  for( int i=0;i<m;i++)
  {
    p[i]= (int*)malloc(n*sizeof(int));
  }

  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
     cin>>*(*(p+i)+j);
    }
  }


 int a,b,**q;
  cout<<"Enter no of rows and column you want.\n";
  cin>>a>>b;


  q=(int**)malloc(a*sizeof(int*));

  for( int i=0;i<a;i++)
  {
    q[i]= (int*)malloc(b*sizeof(int));
  }

  for(int i=0;i<a;i++)
  {
    for(int j=0;j<b;j++)
    {
     cin>>*(*(q+i)+j);
    }
  }

dis(m,n,p);
dis(a,b,q);
multi(m,n,b,p,q,r);
add(m,n,p,q,r);
dis(m,n,r);
trans(p,m,n,r);
dis(m,n,r);
}
