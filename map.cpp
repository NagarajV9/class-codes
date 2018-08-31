#include<iostream>
#include<map>
#include<string>

using namespace std;

class student
{
   int no;
   string name;
   public:
   map<int,string> stud_list;
   map<int,string>::iterator it;
   void add()
  {
      cout<<"Enter the roll no";
      cin>>no;
      cout<<"Enter the name";
      cin>>name;
      stud_list.insert(pair<int,string> (no,name));
   }
   void num(int n)
   {
      for(it=stud_list.begin();it!=stud_list.end();it++)
       if(it->first==n)
       {
            cout<<it->second<<endl;
        }
   }
   void name(string na)
   {
      for(it=stud_list.begin();it!=stud_list.end();it++)
      if(it->second==na)
        {
           cout<<it->first<<endl;
        }
   }
};

int main()
{
   student o1[5];
  for(i=0;i<5;i++)
  {
     o[i].add();
  }

}
