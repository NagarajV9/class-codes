#include<iostream>
#include<iomanip>
using namespace std;

class student
{
  int regno,mark[3];
  char grade,name[30];
  float percent;
  public:
  void getdetails(int rn,int m[],char n[])
  {
    regno=rn;
    for(int i=0;i<3;i++)
      mark[i]=m[i];
    for(int i=0;n[i]!='\0';i++)
      name[i]=n[i];
  }
  void compute_percent()
  {
    int s=0;
    for(int i=0;i<3;i++)
    {
       s+=mark[i];
      
    }
    percent=s/3;
  }
  void compute_grade()
  {
    if(percent>90)
       grade='O';
    else if(percent>80)
       grade='A';
    else if(percent>70)
       grade='B';
    else if(percent>60)
       grade='C';
    else if(percent>50)
       grade='P';
    else
       grade='F';
  }
  void print_details()
  {
    cout<<endl<<"Name: "<<name<<endl;
    cout<<"Register No: "<<regno<<endl;
    cout<<"Marks:";
    for(int i=0;i<3;i++)
    cout<<" "<<mark[i];
    cout<<endl<<"Percentage: "<<setprecision(2)<<percent<<endl;
    cout<<"Grade: "<<grade<<endl;
  }
};

int main()
{
  int r1,m1[3];
  char n1[30];
  student s;
 
    cout<<endl<<"Name: ";
    cin>>n1;
    cout<<endl<<"Reg No: ";
    cin>>r1;
    cout<<endl<<"Marks: ";
    for(int j=0;j<3;j++)
     cin>>m1[j];
    s.getdetails(r1,m1,n1);
    s.compute_percent();
    s.compute_grade();
  
  
   
    s.print_details();
  
  return 0;
}
