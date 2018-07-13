#include<iostream>
#include<cstdlib>

using namespace std;
class string
{
   char *str,*str2;
   public:
   int length(char *a)
   {
       int l=0;
       while(*a[l++]!='\0');
       return l+1;
   }
   void copy_str(char *a,char *b)
   {
        for(int i=0;i<string.length(b);i++)
        {
         
           *a[i]=*b[i];
        }
   }
   void get_string(char *a)
   {
         str=new char[string.length(a)+1];
         string.copy_str(str,a);
         *str[string.length(a)]='\0';
   }
   void get_string(char *a,char *b)
  {
        str=new char[string.length(a)+1];
        str2=new char[string.length(b)+1];
        string.copy_str(str,a);
        *str[string.length(a)]='\0';
        string.copy_str(str2,b);
        *str[string.length(b)]='\0';
  }
  void concat_str(char *a,char *b)
  {
      for(int i=0,j=string.length(a)-1;i<string.length(b);i++,b++)
      {
          *a[j]=*b[i];
         
      }
      *a[j]='\0';
  }
  int extract_str(char *a,int s,int l)
  {
    cout<<endl;
      for(int i=s;l>=0;i++,l--)
      {
         cout<<*a[i];
      }
    cout<<endl;
  }

  void print(char *a)
  {
     for(int i=0;i<strin.length(a);i++)
      cout<<endl<<*a[i];
     cout<<endl;
     
  }
  void print(char *a,char *b)
  {
     for(int i=0;i<strin.length(a);i++)

      cout<<endl<<*a[i];
     cout<<endl;
    for(int i=0;i<strin.length(a);i++)
      cout<<endl<<*a[i];
     cout<<endl;

  }
  void remove_str(char *a)
  {
     delete[] a;
  }
};

int main()
{
  string s;
  int num;
  char s1[50],s2[50];
  while(1)
  {
    cout<<endl<<"1.Copy"<<endl<<"2.Length"<<endl<<"3.Concatenate"<<endl<<"4.Extract position"<<endl<<"5.Quit"<<endl;
    cin>>num;
    switch(num)
    {
      case 1:cout<<endl<<"
             break;
      case 2:
             break;
      case 3:
             break;
      case 4:
             break;
      case 5:exit(0);
             break;
    }
  }
   return 0;
}
