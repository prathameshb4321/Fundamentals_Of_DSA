#include<iostream>
#include<string.h>
#include<chrono>
#include<iomanip>
#include<ctime>
#include<sstream>
using namespace std;
#define n 36
#define e 63
#define max 99999
int G[36][36];
int visit[36];

struct Station
{
  int code;
  string name;
}station[36];

struct Data{
    char name[100];
    long long int phone_no;
    int age;
   char time[50];
}data[100];

void inser_t(int p,int q,int dist)
{
 G[p][q]=dist;
 G[q][p]=dist;
}

void displays(Station station[36])  // Display all the stations with their station_codes
{
  cout<<"-------------\"Stations_with_station_codes\"------------\n";
  cout<<"Station   Station \n code      Name\n";
  for(int i=0;i<10;i++)
  {
   cout<<"  "<<station[i].code<<"   ||  "<<station[i].name<<endl;
  }
  for(int i=10;i<36;i++)
  {
   cout<<"  "<<station[i].code<<"  ||  "<<station[i].name<<endl;
  }

}

string convert(int code)
{
    switch(code)
    {
    case 0:
        return "Navi_mumbai" ;

    case 1:
        return "Nandurbar";

    case 2:
        return "Dhule" ;

    case 3:
        return "Nashik";
    case 4:
        return "Palghar";
    case 5:
        return "Thane" ;
    case 6:
        return "Mumbai";
    case 7:
        return "Raigad";
    case 8:
        return "Ratnagiri";
    case 9:
        return "Sindhudurg";
    case 10:
        return "Kolhapur" ;
    case 11:
        return "Sangli";
    case 12:
        return "Satara";
    case 13:
        return "Pune";
    case 14:
        return "Ahmadnagar";
    case 15:
        return "Solapur";
    case 16:
        return "Dharashiv";
    case 17:
        return "Beed";
    case 18:
        return "Sambhaji_Nagar";
    case 19:
        return "Jalgaon";
    case 20:
        return "Jalna";
    case 21:
        return "Buldhana";
    case 22:
        return "Akola";
    case 23:
        return "Washim";
    case 24:
        return "Amaravati";

    case 25:
        return "Wardha";
    case 26:
        return "Nagpur";
    case 27:
        return "Bhandra";
    case 28:
        return "Gondia";
    case 29:
        return "Gadchorili";
    case 30:
        return "Chandrapur";
    case 31:
        return "Yavatmal";
    case 32:
        return "Nanded";
    case 33:
        return "Hingoli";
    case 34:
        return "Parbhani";
    case 35:
        return "Latur";
        }
}



void prims(int v,int visit[36],int G[36][36])
{
    int sum=0,p,temp,Min,a,b;
     visit[v]=1;
    for(int k=0;k<n-1;k++)
    {    temp=9999;
        for(int i=0;i<n;i++)
        {
           if(visit[i]==1)
           { Min=9999;
            for(int j=0;j<n;j++)
             {
               if(G[i][j]!=0 )
               {
                 if(Min>=G[i][j] && visit[j]==0)
                 {
                     Min=G[i][j];
                     p=j;
                 }

               }
             }
             if(Min<temp)
             {
                 temp=Min;
                 a=i;
                 b=p;
             }

           }
        }
        sum=sum+G[a][b];
        cout<<"selected Distance Between   "<<convert(a)<<"   to   "<<convert(b)<<"  is :"<<G[a][b]<<"\n";
        visit[a]=1;
        visit[b]=1;
    }
    cout<<"\nTotal min Distance is : "<<sum;
}



int choose(int dist[],int visited[])
{
  int mi_n=max,min_index;

  for(int i=0;i<n;i++)
  {
      if(dist[i]<mi_n && visited[i]==0)
      {
        mi_n=dist[i];
        min_index=i;
      }
  }
  return min_index;
}

int dijkstra(int G[n][n],int src,int destination)
{
  int dist[n],visited[n],parent[n];

  for(int i=0;i<n;i++)
  {
     visited[i]=0;
     dist[i]=max;
     parent[i]=-1;
  }

  dist[src]=0;

  for(int cnt=0; cnt<n-1;cnt++)
  {
    int u=choose(dist,visited);

    visited[u]=1;

    for(int v=0;v<n;v++)
    {
        if(visited[v]==0 &&G[u][v]!=0 && dist[u]+G[u][v]<dist[v] )
        {
            dist[v]=dist[u]+G[u][v];
            parent[v]=u;
        }
    }
  }

  cout<<"shortest  distance from \""<<convert(src)<<"\" to \""<<convert(destination)<<"\" is : \n\n ";

  int path[n];
  int pathlength=0;

   for(int p=destination; p!=-1;p=parent[p])
  {
      path[pathlength++]=p;
  }

  for(int i=pathlength-1;i>=0;i--)
  {
    cout<<convert(path[i]);
    if(i>0){
        cout<<"- > ";
    }
  }
  cout<<"\n Total distance :"<<dist[destination]<<" KM \n\n"<<endl;
  bool op;
  cout<<"\"want to travel ?\" it will cost  "<<dist[destination]*3.5<<" RS/person \"yes\"=1  AND \"NO\"=0  \n";
  cin>>op;
  if(op==1)
  { int people;
    float cost;
    int i=0;

    char name[100];
    long long int phone_no;
    int age;
    char time[50];
    cout<<"Enter the  No. of people: ";
    cin>>people;
    cout<<"Enter the amount"<<people*dist[destination]*3.5<<" RS    :";
    cin>>cost;
    int p=0;
    do{
    if(cost==people*dist[destination]*3.5 )
    {
      for(int j=0;j<people;j++)
      {
       cout<<"Enter the name of passenger: "<<j+1<<"\t";
       cin>>name;
       cout<<"\n age:\t";
       cin>>age;
       if(age>100){
        cout<<"Enter age less than \"100\"YEARS";
        cin>>age;
       }

       cout<<"\nPhone no:\t";
       cin>>phone_no;
       strcpy(data[i].name,name);
       data[i].age=age;
       data[i].phone_no=phone_no;

       auto now=chrono::system_clock::now();
       time_t now_time_t =chrono::system_clock::to_time_t(now);
       tm now_tm = *localtime(&now_time_t);
       strftime(time,sizeof(time),"  %Y/%m/%d    %H:%M:%S",&now_tm);
       strcpy(data[i].time,time);
       i++;
      } return i;
      cout<<"\"Thanks\" \n";
    }
    else{
        cout<<"Please enter correct amount: ";
        cin>>cost;
    }
    p++;
    }while(p<3);

  }
  else{
    cout<<"\"Thanks for using our service\"";
  }

return 0;
}





void display_adjacencyMatrix(int G[36][36])
{
  for(int i=0;i<36;i++)
  {
      for(int j=0;j<36;j++)
      {
        cout<<G[i][j]<<"  ";
      }
      cout<<"\n";
  }
}

void graph( )
{ cout<<"                                                                                                                                                          \n";
  cout<<"                                                                                                                                                          \n";
  cout<<"                                                                                                  Nagpur -                                                \n";
  cout<<"                                                                           Amarvati              -  -       -                                             \n";
  cout<<"                                                                        -      -    -          -               -                                          \n";
  cout<<"                                                                 Akola        -       -Wardha-        -         Bhandara                                  \n";
  cout<<"                       Nandurbar                               -    -        -            -                     -     -                                   \n";
  cout<<"                           -                                 -        -     -            -   -           -   -          -Gondia                           \n";
  cout<<"                            -                              -            -Washim         -       -         -                -                              \n";
  cout<<"                              -                       Buldhana               -        -            -Chandrapur  -        -                                \n";
  cout<<"                               Dhule-                -   -                     -     -                              - Gadchorili                          \n";
  cout<<"                             -        -            -     -                        -Yavatmal                                                               \n";
  cout<<"                          -              -Jalgaon-       -                     -    -                                                                     \n";
  cout<<"                 Nashik-                      -          -              Hingoli                                                                           \n";
  //cout<<"                -   -                       -            -                -       -                                                                       \n";
  //cout<<"              -       -                   -              -              -    -                                                                            \n";
  cout<<"            -          -               Sambhaji- - - - Jalna- - - Parbhani     -                                                                          \n";
  cout<<"          -             -             -   nagar         -         -        -                                                                              \n";
  cout<<"        -                -Ahmadnagar-           -        -      -            Nanded                                                                       \n";
  cout<<"   Palghar             -      -       - -         -      -   -             -                                                                              \n";
  cout<<"         -           -                   -   -    -   Beed -           -                                                                                  \n";
  cout<<"Navi_       -      -            -          -           -      -  Latur                                                                                    \n";
  cout<<"Mumbai          Thane                         -        -   -                                                                                              \n";
  cout<<"  -         -     -  -            -              Dharashiv                                                                                                \n";
  cout<<"   -Mumbai-      -    -                       -                                                                                                           \n";
  cout<<"                -      Pune -  - -  Solapur-                                                                                                              \n";
  cout<<"               -     -  -            -                                                                                                                    \n";
  cout<<"             Raigad-     -          -                                                                                                                     \n";
  //cout<<"             -          -   -     -                                                                                                                     \n";
  cout<<"            -        -Satara      -                                                                                                                       \n";
  cout<<"           -        -  -         -                                                                                                                        \n";
  cout<<"        Ratnagiri -     -      -                                                                                                                          \n";
  cout<<"          -   -          Sangli                                                                                                                           \n";
  cout<<"         -      -         -                                                                                                                               \n";
  //cout<<"        -          -        -                                                                                                                             \n";
  cout<<" Sindhudurga-  -  -  -Kolhapur                                                                                                                            \n";
  cout<<"                                                                                                                                                          \n";

}



int main()
{
  int v;
  for(int i=0;i<36;i++)
  {
      for(int j=0;j<36;j++)
      {
        G[i][j]=0;
      }
  }


 station[0].code=0;station[0].name="Navi_mumbai";
 station[1].code=1;station[1].name="Nandurbar";
 station[2].code=2;station[2].name="Dhule";
 station[3].code=3;station[3].name="Nashik";
 station[4].code=4;station[4].name="Palghar";
 station[5].code=5;station[5].name="Thane";
 station[6].code=6;station[6].name="Mumbai";
 station[7].code=7;station[7].name="Raigad";
 station[8].code=8;station[8].name="Ratnagiri";
 station[9].code=9;station[9].name="Sindhudurg";
 station[10].code=10;station[10].name="Kolhapur";
 station[11].code=11;station[11].name="Sangli";
 station[12].code=12;station[12].name="Satara";
 station[13].code=13;station[13].name="Pune";
 station[14].code=14;station[14].name="Ahmadnagar";
 station[15].code=15;station[15].name="Solapur";
 station[16].code=16;station[16].name="Dharashiv";
 station[17].code=17;station[17].name="Beed";
 station[18].code=18;station[18].name="Sambhaji_Nagar";
 station[19].code=19;station[19].name="Jalgaon";
 station[20].code=20;station[20].name="Jalna";
 station[21].code=21;station[21].name="Buldhana";
 station[22].code=22;station[22].name="Akola";
 station[23].code=23;station[23].name="Washim";
 station[24].code=24;station[24].name="Amaravati";
 station[25].code=25;station[25].name="Wardha";
 station[26].code=26;station[26].name="Nagpur";
 station[27].code=27;station[27].name="Bhandra";
 station[28].code=28;station[28].name="Gondia";
 station[29].code=29;station[29].name="Gadchorili";
 station[30].code=30;station[30].name="Chandrapur";
 station[31].code=31;station[31].name="Yavatmal";
 station[32].code=32;station[32].name="Nanded";
 station[33].code=33;station[33].name="Hingoli";
 station[34].code=34;station[34].name="Parbhani";
 station[35].code=35;station[35].name="Latur";








 inser_t(0,6,21);     // Navi_mumbai -- mumbai
 inser_t(1,2,99);     // Nandurbar -- Dhule
 inser_t(2,3,158);     // Dhule -- Nashik
 inser_t(2,19,91);    // Dhule -- jalgaon
 inser_t(3,4,148);     // Nashik -- Palghar
 inser_t(3,5,148);     // Nashik -- Thane
 inser_t(3,14,156);    // Nashik -- Ahmadnagar
 inser_t(3,18,179);    // Nashik -- Sambhaji_Nagar
 inser_t(4,5,85);     // Palghar -- Thane
 inser_t(5,6,23);     // Thane -- Mumbai
 inser_t(5,7,181);     // Thane   -- Raigad
 inser_t(5,13,156);    // Thane -- Pune
 inser_t(5,14,232);    // Thane -- Ahmadnagar
 inser_t(7,8,197);     // Raigad  -- Ratnagiri
 inser_t(7,13,135);    // Raigad -- Pune
 inser_t(8,9,151);     // Ratnagiri -- sindhudurga
 inser_t(8,10,172);    // Ratnagiri -- Kolhapur
 inser_t(8,12,190);    // Ratnagiri -- Satara
 inser_t(9,10,141);    // Sindhudurg -- Kolhapur
 inser_t(10,11,87);   // Kolhapur  -- Sangli
 inser_t(11,12,107);   // Sangli -- Satara
 inser_t(11,15,177);   // Sangli -- Solapur
 inser_t(12,13,126);   // Satara -- Pune
 inser_t(12,15,174);   // Satara -- Solapur
 inser_t(13,14,157);   // Pune -- Ahmadnagar
 inser_t(13,15,227);   // Pune -- Solapur
 inser_t(14,15,272);   // Ahmadnagar -- Solapur
 inser_t(14,16,287);   // Ahmadnagar -- Dharashiv
 inser_t(14,17,177);   // Ahmadnagar -- Beed
 inser_t(14,18,154);   // Ahmadnagar -- Sambhaji_Nagar
 inser_t(15,16,112);   // Solapur -- Dharashiv
 inser_t(16,17,114);   // Dharashiv -- Beed
 inser_t(16,35,80);   // Dharashiv -- Latur
 inser_t(17,18,126);   // Beed -- Sambhaji_Nagar
 inser_t(17,20,119);   // Beed -- Jalna
 inser_t(17,34,139);   // Beed -- Parbhani
 inser_t(17,35,136);   // Beed -- Latur
 inser_t(18,19,161);   // Sambhaji_Nagar -- Jalgaon
 inser_t(18,20,86);   // Sambhaji_Nagar -- Jalna
 inser_t(19,21,138);   // Jalgaon -- Buldhana
 inser_t(20,21,130);   // Jalna -- Buldhana
 inser_t(20,34,124);   // Jalna -- Parbhani
 inser_t(21,22,85);   // Buldhana -- Akola
 inser_t(22,23,78);   // Akola -- Washim
 inser_t(22,24,101);   // Akola -- Amaravati
 inser_t(23,24,171);   // Washim -- Amaravati
 inser_t(23,31,140);   // Washim -- Yavatmal
 inser_t(24,25,124);   // Amaravati -- Wardha
 inser_t(25,26,85);   // Wardha -- Nagpur
 inser_t(25,30,143);   // Wardha -- Chandrapur
 inser_t(25,31,112);   // Wardha -- Yavatmal
 inser_t(26,27,62);   // Nagpur -- Bhandra
 inser_t(26,30,153);   // Nagpur -- Chandrapur
 inser_t(27,28,88);   // Bhandra -- Gondia
 inser_t(27,30,185);   // Bhandra -- Chandrapur
 inser_t(28,29,253);   // Gondia -- Gadchiroli
 inser_t(29,30,153);   // Gadchiroli -- Chandrapur
 inser_t(31,32,176);   // Yavatmal -- Nanded
 inser_t(32,33,88);   // Nanded -- Hingoli
 inser_t(32,34,67);   // Nanded -- Parbhani
 inser_t(32,35,132);   // Nanded -- Latur
 inser_t(33,34,75);   // Hingoli -- Parbhani
 inser_t(34,35,128);   // Parbhani -- Latur






int rows;
int ch;
do
{

 cout<<"\n1. Display all stations with their station_code\n";
 cout<<"2. Display adjacency matrix\n";
 cout<<"3. Travel to all stations with min cost \n";
 cout<<"4. Display map of all station \n";
 cout<<"5. Travel from one to another station\n";
 cout<<"\nEnter your choice: ";
 cin>>ch;

 switch(ch)
 {
   case 1:
        displays(station);
        break;
   case 2:
        display_adjacencyMatrix(G);
        break;
   case 3:
        cout<<"\n Enter the station code from where you want to start";
        cin>>v;
        prims(v,visit,G);
        break;
   case 4:
         graph();
         break;
   case 5:
        int src,destination;
        cout<<"Enter stations code from where to where you want reach \n";
        cin>>src>>destination;
       rows=dijkstra(G,src,destination);
       cout<<" NAME       AGE         DATE         TIME  \n";
       for(int i=0;i<rows;i++)
       {
           cout<<" "<<data[i].name<<"       "<<data[i].age<<"     "<<data[i].time<<"\n";
       }
 }


}while(ch>0);

}
