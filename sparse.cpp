#include<iostream>
using namespace std;

void sparse(int A[20][20],int m,int n,int C[20][20],int cnt)
{

   int cnt1=1;
   C[0][0]=m;
   C[0][1]=n;
   C[0][2]=cnt;

   for(int i=0;i<m;i++)
  {
      for(int j=0;j<n;j++)
      {
        if(A[i][j]!=0)
           {
             C[cnt1][0]=i;
             C[cnt1][1]=j;
             C[cnt1][2]=A[i][j];
              cnt1++;
           }

      }
  }

}

int trans(int C[20][20],int R[20][20])
{
 cout<<"transose id\n";
  int c=1;
    R[0][0]=C[0][1];
    R[0][1]=C[0][0];
    R[0][2]=C[0][2];
    for(int i=0;i<C[0][1];i++)
    {
        for(int j=1;j<=C[0][2];j++)
        {
               if(C[j][1]==i)
               {
                R[c][0]=C[j][1];
                R[c][1]=C[j][0];
                R[c][2]=C[j][2];
                  c++;

               }

        }
    }
}



void add(int C[20][20],int D[20][20],int R[20][20] )
{
  R[0][0]=C[0][0];
  R[0][1]=C[0][1];
  int cnt3=1;
  int i=1,j=1;
  while(i<=C[0][2] && j<=D[0][2])
  {
    if(C[i][0]>D[j][0])
    {
      R[cnt3][0]=D[j][0];
      R[cnt3][1]=D[j][1];
      R[cnt3][2]=D[j][2];
      cnt3++;
      j++;

    }
    else if(C[i][0]<D[j][0])
    {
      R[cnt3][0]=C[i][0];
      R[cnt3][1]=C[i][1];
      R[cnt3][2]=C[i][2];
      cnt3++;
      i++;
    }
    else{
       if(C[i][1]<D[j][1])
      {

      R[cnt3][0]=C[i][0];
      R[cnt3][1]=C[i][1];
      R[cnt3][2]=C[i][2];
      cnt3++;
      i++;
      }
      else if(C[i][1]>D[j][1])
      {
       R[cnt3][0]=D[j][0];
      R[cnt3][1]=D[j][1];
      R[cnt3][2]=D[j][2];
      cnt3++;
      j++;

      }
      else
      {
      R[cnt3][0]=C[i][0];
      R[cnt3][1]=C[i][1];
      R[cnt3][2]=C[i][2]+D[j][2];
      cnt3++;
      i++;
      j++;


      }

    }
  }
    while(i<=C[0][2])
    {
       R[cnt3][0]=C[i][0];
      R[cnt3][1]=C[i][1];
      R[cnt3][2]=C[i][2];
      cnt3++;
      i++;

    }

    while(j<=D[0][2])
    {
      R[cnt3][0]=D[j][0];
      R[cnt3][1]=D[j][1];
      R[cnt3][2]=D[j][2];
      cnt3++;
      j++;
    }

    R[0][2]=cnt3-1;


}



void display(int C[20][20])
{
  for(int i=0;i<=C[0][2];i++)
  {

    cout<<C[i][0]<<" "<<C[i][1]<<" "<<C[i][2];

    cout<<"\n";


  }

}
int main()
{
  int A[20][20],B[20][20],C[20][20],D[20][20],R[20][20],m,n,p,q;
  int cnt=0;
  cout<<"Enter the size of 1 matrix\n";
  cin>>m>>n;
  for(int i=0;i<m;i++)
  {
      for(int j=0;j<n;j++)
      {
        cin>>A[i][j];
        if(A[i][j]!=0)
            cnt++;

      }
  }
  if(cnt<(m*n)/2)
    {
       cout<<"matrix is sparse\n";
    sparse(A,m,n,C,cnt);
    display(C);}
  else
    cout<<"matrix cant convert sparse\n";


    int cnt2=0;
    cout<<"Enter the size of 2 matrix\n";
  cin>>p>>q;
  for(int i=0;i<p;i++)
  {
      for(int j=0;j<q;j++)
      {
        cin>>B[i][j];
        if(B[i][j]!=0)
            cnt2++;

      }
  }
  if(cnt2<(p*q)/2)
    {
       cout<<"matrix is sparse\n";
    sparse(B,p,q,D,cnt2);
    display(D);}
  else
    cout<<"matrix cant convert sparse\n";


add(C,D,R);
//trans(C,R);
display(R);

}
