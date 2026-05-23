#include<iostream>
#include<string.h>

using namespace std;
struct arr
{
  int roll;
  char name[30];
  float sgpa;
};

void display(struct arr A[],int a)
{
  for(int i=0;i<a;i++)
  {
  cout<<A[i].roll<<", "<<A[i].name<<" ,"<<A[i].sgpa<<"\n";

  }
}

void mearge(struct arr A[],int l,int mid,int h)
{
 int n=mid-l+1;
 int m=h-mid;

 struct arr N[n],M[m];
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
  if(N[i].sgpa<M[j].sgpa)
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



void meargesort(struct arr A[],int l,int h)
{
  if(l<h){
  int mid=(l+h)/2;
  meargesort(A,l,mid);
  meargesort(A,mid+1,h);
  mearge(A,l,mid,h);
}
}


int main()
{ int a;
  cout<<"enter size of array\n";
  cin>>a;
  cout<<"hello\n";
  int l=0,h=a-1;
  int roll;
  char name[30];
  float sgpa;
  struct arr A[a];
  for(int i=0;i<a;i++)
  {   cout<<"roll:";
      cin>>A[i].roll;
      cout<<"name:";
      cin>>A[i].name;
      cout<<"sgpa:";
      cin>>A[i].sgpa;
  }
  display(A,a);
  meargesort(A,l,h);
  cout<<"sorted format:\n";
  display(A,a);
}
