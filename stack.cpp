#include<bits/stdc++.h>
using namespace std;

class stak
{
  int size,stack[10],top;
  public:
  stak()
  {
     size=10;
     top=-1;
  }
  void push(int e)
  {
    if(top==size-1)
    {
       cout<<"Stack Overflow"<<endl;
    }
    else
    {
       stack[++top]=e;
    }
  }
  int pop()
  {
    if(top==-1)
    return -1;
    else
    return stack[top--];
  }
  void display()
  {
    if(top==-1)
    cout<<"Stack Empty"<<endl;
    else
    {
    for(int i=top;i>=0;i--)
     cout<<endl<<stack[i];
    }
  }
};

int main()
{
  stak s;
  int num,ele,p;
  while(1)
  {
  cout<<"Enter the operation to be performed "<<endl<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
  cin>>num;
  switch(num)
  {
    case 1:cout<<endl<<"Enter the number to push ";
           cin>>ele;
          s.push(ele);
           break;
    case 2:p=s.pop();
           if(p==-1)
             cout<<endl<<"Stack underflow"<<endl;
           else
             cout<<endl<<"Item popped: "<<p<<endl;
           break;
    case 3:s.display();
           cout<<endl;
           break;
    case 4:exit(0);
           break;
  }
  }
  return 0;
}
