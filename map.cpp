#include<bits/stdc++.h>
#include<map>
#include<iterator>
using namespace std;

class student
{
  int rollno;
  string name;
  public:
  student(string na,int rn)
  {
      name=na;
      rollno=rn;
  }
  int roll()
  {
      return this->rollno;
  }
  string nam()
  {
      return this->name;
  }
};

int main() {
    int i,ans;
	map<int,string> stud_list;
	student s[5]={student("nagaraj",6562),student("kasi",6532),student("Ajay",6561),student("Akshay",6563),student("Aakash",6502)};
	map<int,string>::iterator it;
	for(i=0;i<5;i++)
	{
	stud_list.insert(pair<int,string> (s[i].roll(),s[i].nam()));
	}
	string step;
	cin>>step;
	cin>>ans;
	for(it=stud_list.begin();it!=stud_list.end();it++)
	{
	    if(it->second==step)
	    cout<<it->first<<endl;
	    if(it->first==ans)
	    cout<<it->second<<endl;
	}
	return 0;
}
