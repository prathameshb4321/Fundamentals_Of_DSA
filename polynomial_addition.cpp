#include<iostream>
using namespace std;
struct node
{
 float co;
 int po;
 struct node*next;
};

void inser_t(struct node*&poly1,float co,int po)
{
  struct node*newn,*temp;
  newn=(struct node*)malloc(sizeof(struct node));
  newn->co=co;
  newn->po=po;
  newn->next=NULL;

  if(poly1==NULL)
  {
   poly1=newn;
  }


   else
   {temp=poly1;
    while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=newn;
   }

}

void add(struct node*poly1,struct node*poly2,struct node*&poly3)
{
 while(poly1!=NULL && poly2!=NULL)
 {

  if(poly1->po>poly2->po)
  {
   inser_t(poly3,poly1->co,poly1->po);
   poly1=poly1->next;
  }
  else if(poly2->po>poly1->po)
  {
    inser_t(poly3,poly2->co,poly2->po);
    poly2=poly2->next;
  }
  else
  {
    inser_t(poly3,poly2->co+poly1->co,poly2->po);
    poly1=poly1->next;
    poly2=poly2->next;
  }
 }
  while(poly1!=NULL)
  {
    inser_t(poly3,poly1->co,poly1->po);
   poly1=poly1->next;
  }
   while(poly2!=NULL)
   { inser_t(poly3,poly2->co,poly2->po);
    poly2=poly2->next;
  }





}

void display(struct node*poly1)
{struct node*temp=poly1;
while(temp!=NULL)
{   cout<<"->";
    cout<<temp->co;
    cout<<"X^"<<temp->po;
    temp=temp->next;
}
cout<<"\n";

}


int main()
{ int co,po;
  struct node*poly1=NULL,*poly2=NULL,*poly3=NULL;
  int p1;
   cout<<"term size";
  cin>>p1;
  for(int i=0;i<p1;i++)
  {
   cout<<"enter coe and power\n";
   cin>>co>>po;
   inser_t(poly1,co,po) ;
  }
  display(poly1);

  int p2;
  cout<<"term size";
  cin>>p2;
  for(int i=0;i<p2;i++)
  {
   cout<<"enter coe and power\n";
   cin>>co>>po;
   inser_t(poly2,co,po) ;
  }
  display(poly2);

  add(poly1,poly2,poly3);
  display(poly3);

}
