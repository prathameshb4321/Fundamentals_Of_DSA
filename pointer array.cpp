#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{int a;
 int *p;
 cout<<"size of array\n" ;
 cin>>a;
 p=(int*)malloc(a*sizeof(int));
 for(int i=0;i<a;i++)
 {
     cin>>*(p+i);
 }

 cout<<"\ndisplay\n";
 for(int i=0;i<a;i++)
 {
     cout<<*(p+i)<<" ";
 }

}
