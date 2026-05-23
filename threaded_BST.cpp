#include<iostream>
#include<stdlib.h>
using namespace std;

struct tbt{
   int data;
   int lbit;
   int rbit;
   struct tbt*left,*right;
};

struct tbt*makenode(int data)
{
    struct tbt*newn;
    newn=(struct tbt*)malloc(sizeof(struct tbt));
    newn->data=data;
    newn->lbit=newn->rbit=1;
    newn->left=newn->right=newn;
    return newn;

};

struct tbt*createTBT(struct tbt*head)
{ int data,n;
  struct tbt*root;
  root=NULL;
  cout<<"Enter number of node you want to insert";
  cin>>n;
  head=makenode(n);
  for(int i=0;i<n;i++)
  {


  if(root==NULL)
  { cout<<"Enter the root data";
    cin>>data;
    root=makenode(data);
   // root->lbit=root->rbit=1;
    root->left=root->right=head;
    head->left=root;
    head->lbit=0;
  }
  else
    {

      struct tbt*temp,*newn;
       temp=root;
        cout<<"Enter the node data";
       cin>>data;
        newn=makenode(data);

    while(1)
    {

       //newn=makenode(data);
       if(temp->data>newn->data) //GO TO LEFT
       {
          if(temp->lbit==1)
          {
             newn->left=temp->left;
             newn->right=temp;
             //newn->lbit=newn->rbit=1;
             temp->left=newn;
             temp->lbit=0;
             break;
          }
          else
            temp=temp->left;

      }
       else if(temp->data<newn->data)  //GO TO RIGHT
       {
           if(temp->rbit==1)
           {
               newn->right=temp->right;
               newn->left=temp;
               //newn->lbit=newn->rbit=1;
               temp->right=newn;
               temp->rbit=0;
               break;
           }
           else
            temp=temp->right;
      }
    }

     }
    }

return head;
};

void inorder(struct tbt*&head)
{

    struct tbt*ptr,*succ;
    ptr=head;
    while(ptr->lbit==0)
    {
        ptr=ptr->left;
    }
    cout<<ptr->data<<" ";

    while(1)
    {
      if(ptr->rbit==1)
      {
       succ=ptr->right;

      }
      else
      {
       ptr=ptr->right;
       while(ptr->lbit==0)
            ptr=ptr->left;
       succ=ptr;
      }
      ptr=succ;
      if(ptr==head)
        break;
      cout<<ptr->data<<" ";

    }

}

void preorder(struct tbt*&head)
{

    struct tbt*ptr,*succ;

    ptr=head->left;

    while(ptr->lbit==0)
    { cout<<ptr->data<<" ";
        ptr=ptr->left;
    }

    cout<<ptr->data<<" ";

    while(1)
    {
      if(ptr->rbit==1)
      {
       succ=ptr->right;

      }
      else
      {
       ptr=ptr->right;

       cout<<ptr->data<<" ";

       while(ptr->lbit==0)
        {  ptr=ptr->left;
            cout<<ptr->data<<" ";

        }
       succ=ptr;
      }
      ptr=succ;
      if(ptr==head)
        break;


    }

}




int main()
{
    struct tbt*head,*root;
    head=createTBT(head);

    int ch;
    do{
     cout<<"\nEnter your choice:"<<"\n";
     cout<<"1.inorder of Threaded binary tree\n";
     cout<<"2.preorder of Threaded binary tree\n";
     cin>>ch;

     switch(ch)
     {
   case 1:
    cout<<"Inorder is:";
    inorder(head);
    break;
   case 2:
    cout<<"\npreorder is:";
    preorder(head);
    break;
   default:
     cout<<"\nenter valid choice";

   }
  }while(ch>0);



}
