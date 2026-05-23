#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node*next;
};
struct node*f=NULL;
struct node*r=NULL;

int isempty()
{
 if(f==NULL )
    return 1;
 else
    return 0;
}

void enque(int data)
{
  struct node*newn;
  newn=(struct node*)malloc(sizeof(struct node));
  newn->data=data;
  newn->next=NULL;
  if(isempty())
  {
   f=r=newn;
  }
  else
    {
     r->next=newn;
     r=newn;
    }
}
int dque()
{
 struct node*temp=f;
 f=f->next;
 free(temp);


}


void display()
{
  struct node *temp=f;
 while(temp!=NULL)
 {
  cout<<"->";
  cout<<temp->data;
  temp=temp->next;
 }

}


int main()
{
    int data;

    int ch=9;

    while(ch>0)
    {
        cout<<"\n1.enque\n2.dque\n3.isempty\n";
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
    }
} }
