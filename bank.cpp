#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class bank
{
   char name_of_depositor[50],account_type[15];
   int acc_no,acc_balance;
   public:
   bank()
   {
   acc_no=0;
   acc_balance=0;
   }
   void assign(int ac,char na[],char ac_t[])
   {
      acc_balance=500;
      acc_no=ac;
      strcpy(name_of_depositor,na);
      strcpy(account_type,ac_t);
   }
   void deposit(int amt,int a)
   {
      if(a==acc_no)
      {acc_balance+=amt;
      this->display(a);}
      else
         return;
   }
   void withdraw(int amt,int a)
   {
      if(a==acc_no)
      {
      if(acc_balance<amt)
       {
         cout<<"Sorry! Your account balance is too low to withdraw"<<endl;
         return;
       }
       else
        acc_balance-=amt;
      this->display(a);}
      else
          return;
   }
   void display(int a)
   {
     if(a==acc_no)
     {cout<<"Name: "<<name_of_depositor<<endl;
     cout<<"A/c Balance: "<<acc_balance<<endl;}
     else
         return;
   }
};

int main()
{
  bank customers[5];
  int i,choice,dep,wit;
  char name[50],account_t[15];
  int acc_n,acc_ba;

  for(i=0;i<5;i++)
  {
    cout<<endl<<"Enter the details of the customer "<<i+1<<endl;
    cout<<"Name: ";
    cin>>name;
    cout<<endl<<"Account Type: ";
    cin>>account_t;
    cout<<"Account No: ";
    cin>>acc_n;
    customers[i].assign(acc_n,name,account_t);
  }
  while(1)
  {
  cout<<endl<<"Enter the operations to be performed"<<endl<<"1.Deposit"<<endl<<"2.Withdraw"<<"3.Display"<<endl<<"4.Exit"<<endl;
  cin>>choice;
  switch(choice)
  {
     case 1:cout<<"Enter the amount to be deposited ";
            cin>>dep;
            cout<<"Enter the account no ";
            cin>>acc_n;
            for(i=0;i<5;i++)
            {

                  customers[i].deposit(dep,acc_n);

              }

            break;
     case 2:cout<<"Enter the amount to be withdrawn ";
            cin>>wit;
            cout<<"Enter the account no ";
            cin>>acc_n;
            for(i=0;i<5;i++)
            {
                  customers[i].withdraw(wit,acc_n);

              }

            break;
     case 3:cout<<"Enter the account no ";
            cin>>acc_n;
            for(i=0;i<5;i++)
            {
                  customers[i].display(acc_n);

              }

            break;
     case 4:exit(0);
            break;
  }
  }
  return 0;
}
