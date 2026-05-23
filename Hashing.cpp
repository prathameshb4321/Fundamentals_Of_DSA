#include<iostream>
#include<cmath>
#define size 5
using namespace std;

struct call{
    int roll;
    int is_set;
}collect[size];

int has_hD(int data)
{
  return data%size;
}
int has_hM(int data)    // h(k)=floor( size (data*0.431 %1 )
{
  return (size *( fmod(data*0.431 , 1)));
}

void inser_t1(int data)
{
  int temp=has_hD(data);
 int p=temp;
  int i=1;
  while(collect[p].is_set==1)
  {
    cout<<"-----------collision :"<<i<<"----------- \n";
    p=(temp+i)%size;
    i++;
    if(i==size){
        cout<<"full ghari ja";
        return;
     }

  }
   collect[p].roll=data;
   collect[p].is_set=1;
   cout<<"data inserted\n";
}

void searc_h1(int data)
{
  int temp=has_hD(data);
  int p=temp,i=1;
  bool r;
  while(collect[p].is_set==1)
  {
     if(collect[p].roll==data){
        cout<<"\ndata found at position :"<< p;
        return;
     }
     p=(temp+i)%size;
     i++;
     if(i==size){
        cout<<"data is not there";
        return;
     }
  }

}



// Using Quadratic probing function

void inser_t2(int data)
{
  int temp=has_hM(data);
 int p=temp;
  int i=1;
  while(collect[p].is_set==1)
  {
    cout<<"-----------collision :"<<i<<"----------- \n";
    p=(temp+(i*i))%size;
    i++;
  }
  if(collect[p].is_set==0)
  {
   collect[p].roll=data;
   collect[p].is_set=1;
   cout<<"data inserted\n";
  }
  else{
    cout<<"data can't be inserted";
  }
}

void searc_h2(int data)
{
  int temp=has_hD(data);
  int p=temp,i=1;
  bool r;
  while(collect[p].is_set==1)
  {
     if(collect[p].roll==data){
        cout<<"\ndata found at position :"<< p;
        return;
     }
     p=(temp+(i*i))%size;
     i++;
     if(i==size){
        cout<<"data is not there";
        return;
     }
  }

}




void display()
{
   for(int i=0;i<size;i++){
     if(collect[i].is_set==1){
        cout<<i<<" "<<collect[i].roll<<endl;
     }
   }

}

int main()
{ int n,roll;
  cout<<"Enter no of roll no to insert.";
  cin>>n;


   int ch1;
   do{
    cout<<"\n Enter the choice";
    cout<<"\n1.linear probing";
    cout<<"\n2.Quadratic probing";
    cin>>ch1;

    switch(ch1)
    {
   case 1:

    for(int i=0;i<n;i++){
    cout<<"Enter the roll:";
    cin>>roll;
    inser_t1(roll);
    }
    int ch;
    do{

    cout<<"\n1.insert roll in hashTable linear probing ";
    cout<<"\n2.search roll from hashTable linear probing";
    cout<<"\n3.display roll from hashTable";
    cout<<"\nEnter your choice";
    cin>>ch;

    switch(ch)
    {
    case 1:
        cout<<"Enter the roll";
        cin>>roll;
        inser_t1(roll);
        break;
    case 2:
        cout<<"Enter the roll to search ";
        cin>>roll;
        searc_h1(roll);
        break;
    case 3:
        display();
        break;
    }
    } while(ch>0);

     break;



    case 2:
        for(int i=0;i<size;i++)
        {
          collect[i].roll=0;
          collect[i].is_set=0;
        }


    for(int i=0;i<n;i++){
    cout<<"Enter the roll:";
    cin>>roll;
    inser_t2(roll);
    }
    int ch2;
    do{

    cout<<"\n1.insert roll in hashTable Quadratic probing ";
    cout<<"\n2.search roll from hashTable Quadratic probing";
    cout<<"\n3.display roll from hashTable";
    cout<<"\nEnter your choice";
    cin>>ch2;

    switch(ch2)
    {
    case 1:
        cout<<"Enter the roll";
        cin>>roll;
        inser_t2(roll);
        break;
    case 2:
        cout<<"Enter the roll to search ";
        cin>>roll;
        searc_h2(roll);
        break;
    case 3:
        display();
        break;
    }
    }while(ch2>0);
     break;

   }
   }while(ch1>0);

}

