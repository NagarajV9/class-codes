#include<iostream>
using namespace std;

class Vector
{
  float *arr;
  int size;
  public:
  Vector()
  {
    arr=NULL;
    size=0;
  }
  void create(int s)
  {
    int i;
    arr=new float[s];
    size=s;
    cout<<endl<<"Enter the elements"<<endl;
    for(i=0;i<s;i++)
     cin>>*(arr+i);
  }
  void modify(int po,float va)
  {
     *(arr+po)=va;
      cout<<endl<<"After modifying "<<endl;
      this->display();
  }
  void multiply(int sc)
  {
     int i;
     for(i=0;i<size;i++)
     {
       *(arr+i)*=sc;
     }
     cout<<endl<<"After multiplying"<<endl;
     this->display();
  }
  void display()
  {
     int i;
     for(i=0;i<size;i++)
       cout<<*(arr+i)<<" ";
  }
  void descending()
  {
     int i;
     for(i=size-1;i>=0;i--)
       cout<<*(arr+i)<<" ";
  }
};

int main()
{
   Vector vec;
   int s,p,sc;
   float va;
   cout<<"Enter the size of the vector ";
   cin>>s;
   vec.create(s);
   cout<<endl<<"Enter the position ";
   cin>>p;
   cout<<endl<<"Enter the value ";
   cin>>va;
   vec.modify(p,va);
   cout<<endl<<"Enter the scalar ";
   cin>>sc;
   vec.multiply(sc);
   cout<<endl<<"The list in ascending order is"<<endl;
   vec.display();
   cout<<"The list in descending order is"<<endl;
   vec.descending();
   return 0;
}
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
~               
