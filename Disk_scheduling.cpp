#include<iostream>
using namespace std;
main()
 {
    int temp,tracks,initial,no,traverse,queue[100],i=0,avg,t_tracks=0,j=1,k;
  cout<<"\t\tOS PACKAGE\n\t\t-----------\n";
  cout<<"DISK SCHEDULING ALGORITHM\n-----------------------------\n";
  cout<<"ENTER THE NO.OF TRACKS IN THE DISK:";
  cin>>tracks;
  A:
  cout<<"ENTER THE INITIAL TRACK POSITION:";
  cin>>initial;
   if(initial>=tracks || initial<0)
    {
    cout<<"INVALID TRACK POSITION!!! RE-ENTER...\n";
     goto A;
    }
  cout<<"ENTER THE NO.OF REQUESTS WAITING:";
  cin>>no;
  cout<<"ENTER THE REQUESTS ONE BY ONE:\n";
   while(i<no)
    {
     cin>>queue[i];
      if(queue[i]>=tracks || queue[i]<0)
       {
         cout<<"INVALID TRACK NUMBER!!!\t RE-ENTER THE REQUEST\n";
         continue;
       }
       i++;
    }
   cout<<"FIRST COME FIRST SERVED(FCFS):\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
     traverse=queue[0]-initial;
     cout<<"NEXT TRACK ACCESSED\t\tNO.OF TRAVERSALS\n";
    for(i=0;i<no;i++)
     {
         if(traverse<0)
        traverse=traverse*-1;
      cout<<"\t"<<queue[i]<<"\t\t\t"<<traverse<<"\n";
        t_tracks=traverse+t_tracks;
        traverse=queue[i+1]-queue[i];
     }
   avg=t_tracks/i;
   cout<<"\nTOTAL NUMBER OF TRACKS ACCESSED:"<<t_tracks;
   cout<<"\nAVERAGE SEEK LENGTH:"<<avg;
  cout<<"\n\nSHORTEST SEEK TIME FIRST(SSTF):\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
   for(i=0;i<no;i++)
      for(j=i+1;j<no;j++)
        if(queue[i]>queue[j])
          {
           temp=queue[i];
           queue[i]=queue[j];
           queue[j]=temp;
          }
t_tracks=0;
avg=0;
j=no;
cout<<"NEXT TRACK ACCESSED\t\tNO.OF TRAVERSALS\n";
while(no!=0)
{
  for(i=0;i<no;i++)
   {
    if(queue[i]>initial)
    {
    if(queue[i]-initial>initial-queue[i-1]&& i!=0)
     {
     //cout<<"\nnearest is"<<queue[i-1];
      //if((initial-queue[i-1])<0)
      //traverse=-1*(initial-queue[i-1]);
      //else
      traverse=initial-queue[i-1];
     cout<<"\t"<<queue[i-1]<<"\t\t\t"<<traverse<<"\n";
      initial=queue[i-1];
      for(k=i;k<no;k++)
       {
        queue[k-1]=queue[k];
       }break;
     }
    else
     {
    //cout<<"\nnearest is"<<queue[i];
   //  if((queue[i]-initial)<0)
    //  traverse=-1*(queue[i]-initial);
    //else
     traverse=queue[i]-initial;
      cout<<"\t"<<queue[i]<<"\t\t\t"<<traverse<<"\n";
     initial=queue[i];
      for(k=i;k<no;k++)
       {
        queue[k]=queue[k+1];
       }break;
     }
     //no--;
    }
   }
   if(i==no)
   {
     //if((initial-queue[i-1])<0)
      //traverse=-1*(initial-queue[i-1]);
      //else
       traverse=initial-queue[i-1];
     cout<<"\t"<<queue[i-1]<<"\t\t\t"<<traverse<<"\n";
      initial=queue[i-1];
      for(k=i;k<no;k++)
       {
        queue[k-1]=queue[k];
       }
   }
   t_tracks=t_tracks+traverse;
   no--;
  }
  avg=t_tracks/j;
   cout<<"\nTOTAL NUMBER OF TRACKS ACCESSED:"<<t_tracks;
   cout<<"\nAVERAGE SEEK LENGTH:"<<avg;
 }

