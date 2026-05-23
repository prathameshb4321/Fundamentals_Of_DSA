#include<iostream>
using namespace std;
int unio_n(int A[],int a,int B[],int b,int C[])
{
    int c=0;
    int flag;
    for(int i=0;i<a;i++)
    { flag=0;
     for(int j=0;j<c;j++)
     {
      if(A[i]==C[j])
            flag=1;

     }
     if(flag==0)
     { C[c]=A[i];
        c++;

     }
     }

     for(int i=0;i<b;i++)
    { flag=0;
     for(int j=0;j<c;j++)
     {
      if(B[i]==C[j])
            flag=1;

     }
     if(flag==0)
     { C[c]=B[i];
        c++;

     }
     }

    return c;
}

int intersc(int A[],int a,int B[],int b,int C[])
{
    int c=0;
 int flag;
 for(int i=0;i<a;i++)
 {   flag=0;
     for(int j=0;j<b;j++)
     {
       if(A[i]==B[j])
        {
         C[c]=A[i];
         c++;
        }

     }

 }

 }

int diff(int A[],int a,int B[],int b,int C[])
{
  int c=0;
  int flag;
  for(int i=0;i<a;i++)
  {  flag=0;
      for(int j=0;j<b;j++)
      {
        if(A[i]==B[j])
            flag=1;

      }
      if(flag==0)
      { C[c]=A[i];
        c++;

      }
  }


return c;
}

int symmetdif(int A[],int a,int B[],int b,int C[])
{
 int P[20],Q[20],p,q;
 p=diff(A,a,B,b,P);
 q=diff(B,b,A,a,Q);
int  c=unio_n(P,p,Q,q,C);
return c;
}



void display(int C[],int c)
{
    for(int i=0;i<c;i++)
  {
    cout<<C[i]<<" ";
  }


}





int main()
{
 int A[20],B[20],a,b,C[20],c;
 cout<<"enter size1\n";
 cin>>a;
 for(int i=0;i<a;i++)
 {
  cin>>A[i];
}

cout<<"enter size2\n";
 cin>>b;
 for(int i=0;i<b;i++)
 {
  cin>>B[i];
}

//c=unio_n(A,a,B,b,C);
//c=intersc(A,a,B,b,C);
//c=diff(A,a,B,b,C);
c=symmetdif(A,a,B,b,C);
display(C,c);
}
