#include <stdio.h>
#include<stdlib.h>

struct employee
{
    int sal;
    struct employee *next;
}*head;

void insert(int s)
{
  struct employee *temp,*temp1=head;
  temp=(struct employee*)malloc(sizeof(struct employee));
  temp->sal=s;
  temp->next=NULL;
  if(head==NULL)
  head=temp;
  else
  {
      while(temp1->next!=NULL)
      temp1=temp1->next;
      temp1->next=temp;
  }
}

void display()
{
    struct employee *temp=head;
    while(temp!=NULL)
    {printf("%d\n",temp->sal);
    temp=temp->next;
    }
}

void sortl()
{
    int t1;
    
    struct employee *temp,*temp1;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        
      
        for(temp1=temp;temp1!=NULL;temp1=temp1->next)
        {
            if(temp->sal>temp1->sal)
            {
               t1=temp1->sal;     
               temp1->sal=temp->sal;
               temp->sal=t1;
            }
        }
    }
}

void reversel()
{
    struct employee *prev=NULL,*curr,*ne=NULL;
    curr=head;
    
    while(curr!=NULL)
    {
        
        ne=curr->next;
        curr->next=prev;
        prev=curr;
        curr=ne;
    }
    head=prev;
}

struct node *reverse_block(struct node *head,int k)
{
   struct node *prev=NULL,*next=NULL,*curr=head;
   int count=0;
    while(curr!=NULL&&count<k)
    {
        next=curr->next;
        curr->next=prev;
        curr=next;
        prev=curr;
    }
    if(next!=NULL)
        head->next=reverse_block(next,k);
    return prev;
}

int main()
{
    int num,sal;
    printf("\nEnter the no. of nodes ");
    scanf("%d",&num);
    printf("\nEnter the salary ");
    while(num--)
    {
        scanf("%d",&sal);
        insert(sal);
    }
    printf("\nBefore sorting\n");
    display();
    
    printf("\nAfter sorting\n");
    sortl();
    display();
    printf("\nAfter reversing\n");
    reversel();
    display();
    head=reverse_block(head,3);
    display();
    return 0;
}
