
#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node*next;

};
struct node*head=NULL;

void insert_(int a)
{
 struct node*temp,*newn;
 newn=(struct node*)malloc(sizeof(struct node));
 newn->data=a;
 newn->next=NULL;
 temp=head;
 while(temp->next!=head)
 {
     temp=temp->next;
 }
 temp->next=newn;
 newn->next=head;

}

void delete_(int a)
{
  struct node*temp=head,*loc;
  while(temp->next->data!=a && temp->next!=head)
  { loc=temp;
   temp=temp->next;
  }
  if(temp->next==head)
  {
      cout<<"\ndata not present\n";
      return;
  }
  struct node*temp1;
 temp1= temp->next;
  temp->next=temp1->next;
  free(temp1);

}
void update(int a)
{  int b;
   cout<<"enter the new data you want to insert\n";
   cin>>b;
  struct node*temp=head;
  while(temp->data!=a && temp->next!=head)
  {
      temp=temp->next;
  }
  if(temp->next==head)
  {
      cout<<"\ndata not present\n";
      return;
  }
  temp->data=b;


}

void display()
{
  struct node*temp=head;
  while(temp->next!=head)
  {
      cout<<temp->data;
      cout<<"->";
      temp=temp->next;
  }
  cout<<temp->data;
}
void sort_()
{ struct node*temp=head;
  struct node*temp1;
  int loc;
  while(temp->next!=head)
  {
      temp1=temp->next;
      while(temp1->next!=head->next)
      {
          if(temp->data>temp1->data)
          {
          loc = temp->data;
          temp->data=temp1->data;
          temp1->data=loc;
          }
          temp1=temp1->next;
      }
      temp=temp->next;
  }
}

int main()
{ int a;
  //struct node*head;
  cout<<"Enter the head node:\t";
  cin>>a;
  head=(struct node*)malloc(sizeof(struct node));
  head->data=a;
  head->next=head;

  int ch=9;
  do
  {
    cout<<"\nEnter your choice\n1.insert\n2.delete\n3.update\n4.dispaly\n5.sort\n";
    cin>>ch;
    switch(ch)
    {
 case 1:
    {
    cout<<"Enter the data to insert\n";
    cin>>a;
    insert_(a);
    break;
    }
 case 2:
    {
    cout<<"Enter the data to delete\n";
    cin>>a;
    delete_(a);
    break;

    }
 case 3:
    {
    cout<<"Enter the node data need to update\n";
    cin>>a;
    update(a);
    break;
    }
 case 4:
    {
     display();
        break;
    }
    case 5:
    {
        sort_();
        display();
        break;
    }

    }
  }
  while(ch>0);




}
