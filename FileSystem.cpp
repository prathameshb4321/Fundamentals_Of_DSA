#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;


struct student{
       int roll;
       string name;
       string div;
       string add;
};

void Insert()
{
  student st;
  cout<<"Enter the roll: ";
  cin>>st.roll;
  cin.ignore();
  cout<<"enter the name: ";
  getline(cin,st.name);
  cout<<"enter the div: ";
  getline(cin,st.div);
  cout<<"enetr the address:";
  getline(cin,st.add);

  ofstream file("stud.txt",ios::app);

  if(!file.is_open())
  {
   cout<<"\n file cant be opened....\n";
   return;
  }

  file<<st.roll<<"\n";
  file<<st.name<<"\n";
  file<<st.div<<"\n";
  file<<st.add<<"\n";
  file.close();

  cout<<"\ndata inserted.....\n";




}

void searchs()
{
  int roll;
  cout<<"Enter roll data you want search:";
  cin>>roll;

  ifstream file("stud.txt");
  student st;

  if(!file.is_open())
  {
   cout<<"\n file cann't be opened....\n";
   return;
  }
  int flag=1;
  while(file>>st.roll)
  {
      file.ignore();
      getline(file,st.name);
      getline(file,st.div);
      getline(file,st.add);

      if(st.roll==roll)
      {
         flag=0;
         cout<<"\n stu roll: "<<st.roll;
         cout<<"\n stu name: "<<st.name;
         cout<<"\n stu div: "<<st.div;
         cout<<"\n stu add: "<<st.add;
      }
  }
      if(flag)
      {
       cout<<"\n student data not present...\n";
       break;
      }
      else{
        cout<<"\ndata is shown...\n";
      }




}
void display()
{
  student st;
  ifstream file("stud.txt");

  if(!file.is_open())
  {
      cout<<"file cann't be opened";
      return;
  }

  while(file>>st.roll)
  {
    file.ignore();
    getline(file,st.name);
    getline(file,st.div);
    getline(file,st.add);

     cout<<"\n stu roll: "<<st.roll;
     cout<<"\n stu name: "<<st.name;
     cout<<"\n stu div: "<<st.div;
     cout<<"\n stu add: "<<st.add;
     cout<<"\n";
 }

}

void Delete()
{
  int roll,flag=1;
  cout<<"enter roll to delete";
  cin>>roll;
  ifstream file("stud.txt");
  ofstream r("temp.txt");
  student st;

  while(file>>st.roll)
  {
   file.ignore();
   getline(file,st.name);
   getline(file,st.div);
   getline(file,st.add);

   if(st.roll!=roll)
   {
     r<<st.roll<<"\n";
     r<<st.name<<"\n";
     r<<st.div<<"\n";
     r<<st.add<<"\n";
   }
   else{
    flag=0;
   }
  }
  r.close();          //imp
  file.close();       //imp
  if(flag)
  {
    cout<<"\n student data not present...\n";

  }
  else{
        remove("stud.txt");
        rename("temp.txt" , "stud.txt");
    cout<<"\n data deleated successfully....\n";
  }


}




int main()
{
   int ch;
   while(1)
   {


   cout<<"1.insert data in file.\n";
   cout<<"2.search stu\n";
   cout<<"3.display all stu\n";
   cout<<"4.delete stud\n";
   cout<<"\nEnter teh choice:";
   cin>>ch;
   switch(ch)
   {
 case 1:
    Insert();
    break;
 case 2:
    searchs();
    break;
 case 3:
    display();
    break;
 case 4:
    Delete();
    break;



   }



   }
}
