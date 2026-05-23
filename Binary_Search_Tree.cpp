#include<iostream>
using namespace std;

struct node{
   struct node*right,*left=NULL;
   int data;
};

struct node*sta_k[50];
int top=-1;

void push(struct node*root)
{ top++;
  sta_k[top]=root;

}
struct node*pop()
{ struct node*temp;
   temp=sta_k[top];
   top--;
   return temp;

};
int isempty(){
    if(top==-1)
        return 1;
    else
        return 0;

}

struct node*makenode(int data)
{
    struct node*newn;
    newn=(struct node*)malloc(sizeof(struct node));
    newn->data=data;
    newn->left=NULL;
    newn->right=NULL;
    return newn;


};

struct node*tree(struct node*root)
{ int data;
  char ans;

  cout<<"enter the root data";
  cin>>data;
  root=makenode(data);
  cout<<"Enter the node data";
  cin>>data;
  while(data!=0)
  { struct node *newn,*temp;
    newn=makenode(data);
    temp = root;
    while(1)
    { cout<<"enter where you want store data left or right of:"<<temp->data;
      cin>>ans;
      if(ans=='l' ||ans=='L')
      {
          if(temp->left==NULL)
          {
              temp->left=newn;
               break;
          }
          else
             temp=temp->left;
        }
        else if(ans=='r' ||ans=='R')
        {
          if(temp->right==NULL)
          {
              temp->right=newn;
               break;
          }
          else{
            temp=temp->right;
          }
        }
    }
    cout<<"Enter the data of node";
    cin>>data;

  }
 return root;
};

void inorder(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
void postorder(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
void INORDER(struct node*root)
{ struct node*temp;
      temp=root;
      while(1)
      {
          while(temp!=NULL)
          {
              push(temp);
              temp=temp->left;
          }
          if(isempty())
          {
            break;
          }
          temp=pop();
          cout<<temp->data<<" ";
          temp=temp->right;
      }


}

void PREORDER(struct node*root)
{
     struct node*temp;
      temp=root;
      while(1)
      {
          while(temp!=NULL)
          {   cout<<temp->data<<" ";
              push(temp);
              temp=temp->left;
          }
          if(isempty())
          {
            break;
          }
          temp=pop();

          temp=temp->right;
      }


}


int main()
{
 int ch,ans;
 struct node*root;
 root=tree(root);

 do
 {
  cout<<"Enter the choice\n 1.inorder\n2.INORDER\n3.PREORDER\n4.preorder\n5.postorder\n6.exit\n";
  cin>>ch;

  switch(ch)
  {

  case 1:
    {
        cout<<"inorder using recursion is:";
        inorder(root);
        break;
    }
  case 2:
    {
        cout<<"\nINORDER using iteration is:";
        INORDER(root);
        break;
    }
    case 3:
    {
        cout<<"\nPREORDER using iteration is:";
        PREORDER(root);
        break;
    }
     case 4:
    {
        cout<<"preorder using recursion is:";
        preorder(root);
        break;
    }
     case 5:
    {
        cout<<"postorder using recursion is:";
        postorder(root);
        break;
    }
     case 6:
    {
       break;

    }

  }

 }
while(ch>0);

}


