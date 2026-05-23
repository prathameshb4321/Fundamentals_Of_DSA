#include<iostream>
#include<vector>
using namespace std;
void *print(int *q)
{
  cout<<*q<<endl;
   cout<<q<<endl;
   q=q+1;

}

int main()
{
 int a=12;
  int *A=&a;
  cout<<sizeof(A)<<endl;
   double b=10;
  double *B=&b;
  cout<<sizeof(B)<<endl;
  /* char c='abc';
  char *C=&c;
  cout<<sizeof(C)<<endl;
  long d='AB';
  long *D=&d;
  cout<<"op:";
  cout<<d<<endl;
  cout<<sizeof(D)<<endl;

  int *Q=0;
  cout<<Q<<endl;

  int i=5;
  //int *p=&i;
  int *p=0;
  p=&i;
  int *q=&i;

  cout<<p<<endl;
  cout<<q<<endl;
  cout<<*p<<endl;


int num=5;
/*int a=num;
a++;
cout<<a<<" "<<num;

int *p=&num;
//cout<<"\n num"<<num<<endl;
//cout<<p<<endl;
//cout<<*p;
(*p)++;
cout<<"\n afte"<<endl<<*p;
int *q=p;
cout<<"\n"<<*q;

int arr[20]={2,4,1,6,4};
int *a=&arr[0];
cout<<*arr+1<<endl;
cout<<*(arr+1)<<endl;
cout<<(*arr)+1<<endl;
cout<<(*arr+1)<<endl;
cout<<*a<<endl;
cout<<(*a)+1<<endl;







cout<<sizeof(a)<<endl;
cout<<sizeof(arr)<<endl;
cout<<sizeof(*a)<<endl;
cout<<sizeof(&a)<<endl;


//char C[8]={"trfg"};
//char *c=&C[0];
//cout<<c<<endl;
char temp='z';
char *ot=&temp;
cout<<endl<<ot;

*/

int num=5;
int *p=&num;

print(p);

cout<<*p;
}


