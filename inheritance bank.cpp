#include<bits/stdc++.h>
using namespace std;
static long int co1=713560,co=713540;

class account
{
  protected:  
  char name[50],type;
  long int acc_no;
  
};

class savings:public account
{
  long double acc_bal;
  
  public:
  savings()
  {
      strcpy(name," ");
  }
  
  void getdetails(char na[],char te)
  {
      strcpy(name,na);
      type=te;
      acc_no=co++;
      acc_bal=500;
  }
  void deposit(int a)
  {
      acc_bal+=a;
      cout<<"Account balance updated:"<<acc_bal<<endl;
  }
  void with(int a)
  {
      if(acc_bal-a>500)
      {acc_bal-=a;
      cout<<"Account balance updated:"<<acc_bal<<endl;
      }
      else
      {
          cout<<"Withdraw amount is too high!!!"<<endl;
      }
  }
  void display()
  {
      cout<<endl<<"Account Balance: "<<acc_bal;
  }
  void interest(int r,int t)
  {
      long double ci=(acc_bal*r*t)/100;
      acc_bal+=ci;
      cout<<endl<<"simple interest added: "<<ci<<endl;
      cout<<"Updted balance: "<<acc_bal;
  }
};

class current:public account
{
  long double acc_balan;
  
  public:  
  
  void getdetail(char na[],char te)
  {
      strcpy(name,na);
      type=te;
      acc_no=co1++;
      acc_balan=2000;
  }
  void deposi(int a)
  {
      acc_balan+=a;
      cout<<"Account balance updated:"<<acc_balan<<endl;
  }
  void withd(int a)
  {
      if(acc_balan-a>0)
      {acc_balan-=a;
      cout<<"Account balance updated:"<<acc_balan<<endl;
      }
      else
      {
          cout<<"Withdraw amount is too high!!!"<<endl;
      }
  }
  void displa()
  {
      cout<<endl<<"Account Balance: "<<acc_balan;
  }
  void minbal()
  {
      if(acc_balan<2000)
      {
          acc_balan-=(2*acc_balan)/100;
          cout<<endl<<"Service charge:2%";
          cout<<endl<<"Updated balance: "<<acc_balan;
      }
  }
};

int main() {
	current cus[5];
	savings cus1[5];
	int choice,trans=0,s1=0,s2=0,i,in;
	char nam[50],typ;
	long int acno;
	long double amt;
	while(1)
	{
	    cout<<endl<<"Enter your choice"<<endl;
	    cout<<"1.Open an account"<<endl<<"2.Deposit"<<endl<<"3.Withdraw"<<endl<<"4.Check Balance";
	    cout<<endl<<"5.Exit"<<endl;
	    cin>>choice;
	    trans++;
	    switch(choice)
	    {
	        case 1:cout<<endl<<"Enter the name ";
	               cin>>nam;
	               cout<<endl<<"Enter the account type"<<endl<<"  s.savings"<<endl<<"  c.current"<<endl;
	               cin>>typ; 
	               if(typ=='s')
	               {
	                   cus1[s1++].getdetails(nam,typ);
	               }
	               else
	               {
	                   cus[s2++].getdetail(nam,typ);
	               }
	               break;
	        case 2:cout<<endl<<"Enter the account number ";
	               cin>>acno;
	               cout<<endl<<"Enter the account type ";
	               cin>>typ;
	               cout<<endl<<"Enter the amount to be deposited ";
	               cin>>amt;
	               if(typ=='s')
	               {
	                   in=acno%10;
	                   cus1[in].deposit(amt);
	               }
	               else
	               {
	                   in=acno%10;
	                   cus[in].deposi(amt);
	               }
	               break;
	        case 3:cout<<endl<<"Enter the account number ";
	               cin>>acno;
	               cout<<endl<<"Enter the account type ";
	               cin>>typ;
	               cout<<endl<<"Enter the amount to be withdrawn ";
	               cin>>amt;
	               if(typ=='s')
	               {
	                   in=acno%10;
	                   cus1[in].with(amt);
	               }
	               else
	               {
	                   in=acno%10;
	                   cus[in].withd(amt);
	               }
	               break;
	       case 4:cout<<endl<<"Enter the account number ";
	               cin>>acno;
	               cout<<endl<<"Enter the account type ";
	               cin>>typ;
	               if(typ=='s')
	               {
	                   in=acno%10;
	                   cus1[in].display();
	               }
	               else
	               {
	                   in=acno%10;
	                   cus[in].displa();
	               }
	               break;
	       case 5:exit(0);
	              break;
	    }
	    if(trans%10==0)
	    {
	        for(i=0;i<s1;i++)
	        cus1[i].interest(6+(0.2*(trans/10)),trans/10);
	    }
	    for(i=0;i<s2;i++)
	    {
	       cus[i].minbal(); 
	    }
	
	}
	
		return 0;
}
