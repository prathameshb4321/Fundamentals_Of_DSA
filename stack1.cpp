#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node*next;
};
struct node*top=NULL;
void push(int data)
{
  struct node*newn;
  newn=(struct node*)malloc(sizeof(struct node));
  newn->data=data;
  newn->next=NULL;
  if(top==NULL)
  {
   top=newn;
  }
  else
    {
     newn->next=top;
     top=newn;
    }
}
int pop()
{
 struct node*temp=top;
 top=top->next;
 free(temp);

}
int isempty()
{
 if(top==NULL)
    return 1;
 else
    return 0;
}

void display()
{
  struct node *temp=top;
 while(temp!=NULL)
 {
  cout<<"->";
  cout<<temp->data;
  temp=temp->next;
 }

}
void to_p()
{
cout<<top->data<<"  \n";
}

int main()
{
    int data;

    int ch=9;

    while(ch>0)
    {
        cout<<"\n1.push\n2.pop\n3.isempty\n4.top\n";
        cout<<"enter choice\n";
        cin>>ch;
        switch(ch)
        {
     case 1:
        {
         cout<<"enter data\n";
         cin>>data;
          push(data);
          display();
          break;
        }
     case 2:
        {
            pop();
            display();
          break;
        }
     case 3:
        {
          int r=isempty();
          if(r==1)
                cout<<"stack is empty\n";
          else
            cout<<"stack is not empty\n";

        }
     case 4:
        {
            to_p();
        }

        }
    }
}
