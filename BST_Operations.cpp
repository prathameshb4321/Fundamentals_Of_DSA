#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{   struct node*left,*right;
    int data;
};

struct node*makenode(int data)
{
  struct node*newn;
  newn=(struct node*)malloc(sizeof(struct node));
  newn->data=data;
  newn->left=newn->right=NULL;
  return newn;
};

struct node*createbst(struct node*root)
{ int data;

  cout<<"Enter the root data";
  cin>>data;
  root=makenode(data);
  cout<<"Enter the node data";
  cin>>data;
  while(data!=0)
  {
   struct node*newn,*temp;
   temp=root;
   newn=makenode(data);
   while(1)
   {
     if(temp->data<data)
     {
       if(temp->right==NULL)
       {
         temp->right=newn;
         break;
       }
       else
         temp=temp->right;

     }
     else if(temp->data>data)
     {
       if(temp->left==NULL)
       {
         temp->left=newn;
         break;
       }
       else
        temp=temp->left;
     }


   }
   cout<<"Enter the node data";
   cin>>data;

  }
  return root;
};

struct node*insertbst(struct node*root,int data)
{
  struct node*newn,*temp;
  newn=makenode(data);
  temp=root;
  while(1)
  {
    if(temp->data<data)
    {
      if(temp->right==NULL)
      {
        temp->right=newn;
        break;
      }
      else
        temp=temp->right;
    }
    else if(temp->data>data)
    {
        if(temp->left==NULL)
        {
          temp->left=newn;
          break;
        }
        else
            temp=temp->left;


    }

  }
  return root;

};
void inorder(struct node*root)
{
   if(root==NULL)
        return;
   inorder(root->left);
   cout<<root->data<<" ";
   inorder(root->right);

}

int heightbst(struct node*root)
{
   if(root==NULL)
        return -1;
   int lheight=heightbst(root->left);
   int rheight=heightbst(root->right);
   return(lheight>rheight ? lheight:rheight )+1;

}
struct node*mirror(struct node*root)
{
    struct node*left,*right;
    if(root==NULL)
        return NULL;
    left=mirror(root->left);
    right=mirror(root->right);

    root->left=right;
    root->right=left;

    return root;
};

struct node*q[20];
int f=-1;
int r=-1;

void enq(struct node*temp)
{
   r++;
   q[r]=temp;
}
struct node*dq()
{struct node*temp;

f++;
temp=q[f];

return temp;

};
int isempty()
{
    if(f==r)
        return 1;
    else
        return 0;
}

void levelorder(struct node*root)
{
  struct node*temp,*newn;
  newn=(struct node*)malloc(sizeof(struct node));
  newn->data=-1;
  newn->left=newn->right=NULL;
  if(root==NULL)
  {
      cout<<"Empty";
      return;
  }
  enq(root);
  enq(newn);
//  cout<<"\n";

  while(!isempty())
  {
      temp=dq();
      if(temp->data==-1)
      {
          cout<<"\n";
          if(f==r)
            break;

        enq(newn);
      }
      else
      {
         cout<<temp->data<<" ";
         if(temp->left!=NULL)
            enq(temp->left);
         if(temp->right!=NULL)
            enq(temp->right);

      }
  }

}
void leafn(struct node*root)
{
  if(root==NULL)
     return;
  if(root->left==NULL && root->right==NULL)
  {
      cout<<root->data;
      return;
  }
  leafn(root->left);
  leafn(root->right);
  return;

}
void searchbst(struct node*root,int data)
{
     struct node*temp=root;
     if(temp==NULL )
     {
         return;
     }
     if(temp->data==data)
     {
         cout<<"data founded";
     }
     if(temp->left==NULL && temp->right==NULL)
     {
         return;
     }
     if(temp->data>data)
     {
         searchbst(temp->left,data);
     }
     if(temp->data<data)
     {
         searchbst(temp->right,data);
     }



}

struct node*findmin(struct node*root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;
};

struct node* deletebst(struct node*root,int data)
{
  if(root==NULL)
   {
      return root;
   }
  else if(data<root->data)
    {
        root->left=deletebst(root->left,data);
    }
  else if(data>root->data)
   {
        root->right=deletebst(root->right,data);
   }
  else
  {

      if(root->left==NULL && root->right==NULL){

        free(root);
        root=NULL;
      }
      else if(root->left==NULL){
        struct node*temp=root;
        root=root->right;
        free(temp);
      }
      else if(root->right==NULL){
        struct node*temp=root;
        root=root->left;
        free(temp);
      }
      else
      {
          struct node*temp=findmin(root->right);
          root->data=temp->data;
          root->right=deletebst(root->right,temp->data);
      }
  }
  return root;

};








int main()
{  struct node*root;
   int data;
    int ch;

    root=createbst(root);
    do{
        cout<<"\nEnter your choice:\n";
        cout<<"1.inorder traversal \n";
        cout<<"2.insertdata in BST \n";
        cout<<"3.Height of BST \n";
        cout<<"4.MIRROR of BST \n";
        cout<<"5.Level order printing \n";
        cout<<"6.leaf nodes of BST \n";
        cout<<"7.search data in BST \n";
        cout<<"8.delete data from BST \n";
        cin>>ch;

        switch(ch)
        {

         case 1:
          {
               inorder(root);
           break;
          }
         case 2:
           {
             cout<<"Enter the data ";
             cin>>data;
             root=insertbst(root,data);
             break;
           }
         case 3:
            {
                cout<<"Height of the tree is";
            int h=heightbst(root);
            cout<<h<<endl;
            break;
            }
         case 4 :
            {
                root=mirror(root);
            inorder(root);
            break;
            }
         case 5:
            {
                cout<<"level order is:";
            levelorder(root);
            break;
            }
         case 6:
            {
                cout<<"leaf nodes are";
            leafn(root);
            break;
            }
         case 7:
            {
                 cout<<"Enter data you want to search";
             cin>>data;
             searchbst(root,data);
             break;
            }
         case 8:
           {
                cout<<"Enter data you want to delete";
            cin>>data;
            deletebst(root,data);
            break;
           }
         default :
            cout<<"Enter the valid choice";
        }
    }
    while(ch>0);
 }









