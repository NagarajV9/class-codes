#include<stdio.h>
#include<string.h>

struct employee
{
  char name[50];
  int no;
  char position[30];
  int salary;
}e[5];

void salary_greater_than_70000()
{
 int i;
 for(i=0;i<5;i++)
 {
   if(e[i].salary>70000)
   printf("\n%s",e[i].name);
 }
  printf("\n");
}

void salary_between_30000_to_40000()
{
 int i;
 for(i=0;i<5;i++)
{
 if(e[i].salary>=30000&&e[i].salary<=40000)
   printf("\n%s",e[i].name);
}
  printf("\n");
}

int main()
{
  int i;
  printf("\nEnter the details of 5 employees\n");
  for(i=0;i<5;i++)
  {
     printf("\nEmployee %d",i+1);
     
     printf("\nName: ");
     getchar();
     scanf("%[^\n]s",e[i].name);
     printf("\nNumber: ");
     scanf("%d",&e[i].no);
     printf("\nPosition: ");
     getchar();
     scanf("%[^\n]s",e[i].position);
     printf("\nSalary: ");
     scanf("%d",&e[i].salary);
  }
   printf("\nThe employees whose salary is greater than 70000\n");
   salary_greater_than_70000();
   printf("\nThe employees whose salary is in between 30000 and 40000\n");
   salary_between_30000_to_40000(); 
   return 0;
}
