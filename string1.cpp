nclude<iostream>
#include<cstdlib>

using namespace std;
class strin
{
   char *str,*str2;
   public:
   int length(char *a)
   {
       int l=0;
       while(*(a+l++)!='\0');
       return l-1;
   }
   void copy_str(char *a,char *b)
   {
       a=new char[this->length(b)];
        for(int i=0;i<this->length(b);i++)
        {
         
           *(a+i)=*(b+i);
        }
   }
   void get_strin(char *a)
   {
         str=new char[this->length(a)+1];
         this->copy_str(str,a);
         *(str+this->length(a))='\0';
   }
   void get_strin(char *a,char *b)
  {
        str=new char[this->length(a)+1];
        str2=new char[this->length(b)+1];
        this->copy_str(str,a);
        *(str+this->length(a))='\0';
        this->copy_str(str2,b);
        *(str+this->length(b))='\0';
  }
  void concat_str(char *a,char *b)
  {int j,i;
      for(i=0,j=this->length(a);i<this->length(b);i++,j++)
      {
          *(a+j)=*(b+i);
         
      }
      *(a+j)='\0';
  }
  int extract_str(char *a,int s,int l)
  {
    cout<<endl;
      for(int i=s;l-1>=0;i++,l--)
      {
         cout<<*(a+i);
      }
    cout<<endl;
  }

  void print(char *a)
  {
     for(int i=0;i<this->length(a);i++)
      cout<<*(a+i);
     cout<<endl;
     
  }
  void print(char *a,char *b)
  {
     for(int i=0;i<this->length(a);i++)

      cout<<*(a+i);
     cout<<endl;
    for(int i=0;i<this->length(a);i++)
      cout<<*(a+i);
     cout<<endl;

  }
  void remove_str(char *a)
  {
     delete[] a;
  }
};

int main()
{
  strin s;
  int num,ind,len;
  char *s1,*s2;
  while(1)
  {
    cout<<endl<<"1.Copy"<<endl<<"2.Length"<<endl<<"3.Concatenate"<<endl<<"4.Extract position"<<endl<<"5.Quit"<<endl;
    cin>>num;
    switch(num)
    {
      case 1:cout<<endl<<"Enter the string to be copied ";
              s1=new char[50];
             cin>>s1;
             s.copy_str(s2,s1);
             s.print(s1,s2);
             s.remove_str(s1);
             s.remove_str(s2);
             break;
      case 2:cout<<endl<<"Enter the string ";
              s1=new char[50];
              cin>>s1;
              cout<<endl<<"The length of string is "<<s.length(s1);
              s.remove_str(s1);
             break;
      case 3:cout<<endl<<"Enter string1 ";
              s1=new char[50];
              cin>>s1;
              cout<<endl<<"Enter string2 ";
              s2=new char[50];
              cin>>s2;
              s.concat_str(s1,s2);
              
              s.print(s1);
              s.remove_str(s1);
              s.remove_str(s2);
             break;
      case 4:cout<<endl<<"Enter the main string ";
             s1=new char[50];
             cin>>s1;
             cout<<endl<<"Enter the starting position ";
             cin>>ind;
             cout<<endl<<"Enter the length of the substring ";
             cin>>len;
             s.extract_str(s1,ind,len);
             s.remove_str(s1);
             break;
      case 5:exit(0);
             break;
    }
    
  }
   return 0;
}


