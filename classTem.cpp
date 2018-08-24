#include<iostream>
using namespace std;

template<typename C>
class Vector
{
   C *vec;
   int size;
   public:
   Vector(int s)
   {
       vec=new C[s];
       size=s;
   }
   void create(C arr[])
   {
      int i;
      for(i=0;i<size;i++)
      *(vec+i)=arr[i];
   }
   void modify(C ele,int p)
   {
      *(vec+p)=ele;
   }
   void multiply(C sc)
   {
      int i;
      for(i=0;i<size;i++)
      *(vec+i)*=sc;
   }
   void display()
   {
      int i;
      for(i=0;i<size;i++)
      cout<<"("<<*(vec+i)<<",";
      cout<<<<")"<<endl;
   }
};

int main()
{
  int n=5,arri[n];
  float arrf[n],vf,sf;
  double arrd[n],vd,sd;
  Vector<int> I(n);
  Vector<float> F(n);
  Vector<double> D(n);
  int i,p,vi,si;
  cout<<"Integer array"<<endl;
  for(i=0;i<n;i++)
  cin>>arri[i];
  cout<<"Float array"<<endl;
  for(i=0;i<n;i++)
  cin>>arrf[i];
  cout<<"Double array"<<endl;
  for(i=0;i<n;i++)
  cin>>arrd[i];
  I.create(arri);
  F.create(arrf);
  D.create(arrd);
  cout<<"Integer modify"<<endl;
  cin>>vi>>p;
  I.modify(vi,p);
  cout<<"Float modify"<<endl;
  cin>>vf>>p;
  F.modify(vf,p);
  cout<<"Double modify"<<endl;
  cin>>vd>>p;
  D.modify(vd,p);
  cout<<"All the scalars"<<endl;
  cin>>si>>sf>>sd;
  I.multiply(si);
  F.multiply(sf);
  D.multiply(sd);
  cout<<"Dispaly int"<<endl;
  I.display();
  cout<<"Display float"<<endl;
  F.display();
  cout<<"Display double"<<endl;
  D.display();
  return 0;
}

