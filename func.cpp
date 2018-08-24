#include<iostream>
using namespace std;

template <class A>

A minimum(A x,A y)
{
  A z=x>y?x:y;
  return z;
}

int main()
{
  int a,b;
  double c,d;
  float e,f;
  cin>>a>>b;
  cin>>c>>d;
  cin>>e>>f;
  cout<<minimum(a,b)<<endl;
   cout<<minimum(e,f)<<endl;
   cout<<minimum(c,d)<<endl;
  return 0;
}

