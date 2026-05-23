#include<iostream>
using namespace std;
#define  m 3
int A[m];int f=-1,r=-1;

int isfull()
{
  if((r+1)%m==f)
        return 1;
  else
    return 0;
}
int isempty()
{
  if(f==-1&& r==-1)
        return 1;
  else
    return 0;
}
void enque(int data)
{ if(isfull())
{
    cout<<"q if full\n";
    return;
}

  if(isempty())
    f=0;

  r=(r+1)%m;
  A[r]=data;
}
int dque()
{
  int ele;
  ele=A[f];

  if(f==r)
    f=r=-1;
  else
    {
      f=(f+1)%m;
  }
}


void display()
{
    int i=f;
   do
    {
        cout<<A[i]<<" ";
        i=(i+1)%m;

    }while(i<r);
    cout<<A[r]<<"\n";



}
int main()
{
    int data;
    int ch=9;

    int f=-1,r=-1;

    while(ch>0)
    {
        cout<<"\n1.enque\n2.dque\n3.isempty\n4.isfull\n";
        cout<<"enter choice\n";
        cin>>ch;
        switch(ch)
        {
     case 1:
        {
         cout<<"enter data\n";
         cin>>data;
          enque(data);
          display();
          break;
        }
     case 2:
        {
            dque();
            display();
          break;
        }
     case 3:
        {
          int r=isempty();
          if(r==1)
                cout<<"queue is empty\n";
          else
            cout<<"queue is not empty\n";
}
     case 4:
        {
          int s=isfull();
          if(s==1)
                cout<<"queue isfull\n";
          else
            cout<<"queue is not full\n";


        }
    }
} }
