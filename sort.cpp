#include<iostream>
using namespace std;

void bubble(int A[],int m)
{
 for(int i=0;i<m;i++)
 {
     for(int j=0;j<m-1;j++)
     {
        if(A[j+1]<A[j])
        {
            swap(A[j+1],A[j]);
        }

     }
 }
}

void select(int A[],int m)
{
 for(int i=0;i<m-1;i++)
 {
     for(int j=i+1;j<m;j++)
     {
        if(A[j]<A[i])
        {
            swap(A[i],A[j]);
        }

     }
 }
}
void insertio(int A[],int m)
{
  for(int i=1;i<m;i++)
  {
  int  j=i-1;
   int x=A[i];
   while(x<A[j] && j>=0)
   {
       A[j+1]=A[j];
       j--;
   }
   A[j+1]=x;
  }

}

int  partitio_n(int A[20],int l,int h)
{
  int i=l;
  int j=h;
  int pivot=A[i];
  while(i<=j)
  {
    do
    {i++;
     }while(A[i]<pivot);

     do
     {j--;
     }while(A[j]>pivot);

     if(i<j)
        swap(A[i],A[j]);

  }
  swap(A[l],A[j]);
  return j;

}
void quick(int A[],int l,int h)
{
  if(l<h)
  {
  int  j=partitio_n(A,l,h);
   quick(A,l,j);
   quick(A,j+1,h);

  }

}



void mearge(int A[],int l,int mid,int h)
{
 int n=mid-l+1;
 int m=h-mid;

 int N[n],M[m];
 for(int i=0;i<n;i++)
 {
   N[i]=A[l+i];

 }
  for(int i=0;i<m;i++)
 {
   M[i]=A[mid+i+1];

 }
 int i=0,j=0,k=l;
 while(i<n && j<m)
 {
  if(N[i]<M[j])
  {
    A[k]=N[i];
    i++;
  }
  else
  {
    A[k]=M[j];
    j++;
  }
  k++;
 }
 while(i<n)
 {
   A[k]=N[i];
    i++;k++;
 }
 while(j<m)
 {
     A[k]=M[j];
    j++;k++;
 }


 }



void meargesort(int A[],int l,int h)
{
  if(l<h){
  int mid=(l+h)/2;
  meargesort(A,l,mid);
  meargesort(A,mid+1,h);
  mearge(A,l,mid,h);
}
}


void display(int A[],int m)
{
    for(int i=0;i<m;i++)
    {
        cout<<A[i]<<" ";
            }
}

int main()
{  int m,A[20];
   cin>>m;
   int l=0;
   int h=m;
  for(int i=0;i<m;i++)
  {
    cin >>A[i];
  }
 // bubble(A,m);
  // select(A,m);
  //insertio(A,m);
  //quick(A,l,h);
  meargesort(A,l,h-1);
  display(A,m);

}
