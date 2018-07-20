#include<iostream>
#include<cstdlib>
using namespace std;

class que
{
  int arr[5],front,rear,size;
  public:
  que()
  {
    front=-1;
    rear=-1;
    size=5;
  }
  void enque(int e)
  {
    if((front==0&&rear==size-1)||(rear==front-1))
     cout<<endl<<"Queue Overflow"<<endl;
    else
    {
       if(rear==size-1)
        {
          rear=0;
          arr[0]=e;
        }
        else
         {
          if(front==-1)
          front=0;
          arr[++rear]=e;

    }
  }

   }
  int deque()
  {
    int a;
    if(rear==-1&&front==-1)
      a=-1;
    else if(rear==front)
      {
       a=-1;
       front=rear=-1;
      }
    else if(front==size-1)
    {
       a=arr[front];
       front=0;
     }
     else
       a=arr[front++];

    return a;
  }
  void display()
  {
     int i;
     if(front==rear)
        cout<<endl<<arr[front];
     else if(front<rear)
        {
          for(i=front;i<=rear;i++)
            cout<<arr[i]<<" ";
           cout<<endl;
        }
     else if(front>rear)
        {
          for(i=front;i<=size-1;i++)
            cout<<arr[i]<<" "<<endl;
          for(i=0;i<=rear;i++)
            cout<<arr[i]<<" ";

        }
  }
};

int main()
{
   que q;
   int choice,ele;
   while(1)
   {
     cout<<endl<<"Enter the operation to be performed"<<endl;
     cout<<"1.Enque"<<endl<<"2.Deque"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
     cin>>choice;
     switch(choice)
     {
       case 1:cout<<endl<<"Enter the element to enque ";
              cin>>ele;
              q.enque(ele);
              break;
       case 2:ele=q.deque();
              if(ele==-1)
              cout<<endl<<"Queue underflow"<<endl;
              else
              cout<<endl<<ele<<" dequed"<<endl;
              break;
       case 3:cout<<endl;
              q.display();
              break;
       case 4:exit(0);
              break;
     }
   }
   return 0;
}
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
~                                                    
